#!/usr/bin/python
"""
This script checks that the fan speeds are within thresholds.

The exit status of this script is inspected by monit, which issues
alerts for fans.

The following exit codes are defined:

0   -- all fans running normally
100 -- unexpected fan count detected
101 -- unable to read config file
102 -- invalid fan speed reads

Any other exit code indicates one or more fans is not with the
specified thresholds.

"""
##
## Copyright 2012 Cumulus Networks, Inc.
## All rights reserved.
##
## Perhaps read a style guide
## http://google-styleguide.googlecode.com/svn/trunk/pyguide.html
import os
import re
import sys
import time
import array
import tempfile
import led_remote
import subprocess
import process_lock
import ConfigParser
import argparse
import geyser_client as geyser

args = None
config_file = "/etc/fan_monitor/fan_monitor.cfg"

# fan status codes
STATUS_OK = "OK"
STATUS_FAILED = "FAILED"
STATUS_OVERSPEED = "OVERSPEED"
STATUS_UNDERSPEED = "UNDERSPEED"

def geyser_update_fan_info(geyser_client, fan_name, status=None, speed=None):
    if not geyser_client:
        return

    rsrc_updates = []
    if status is not None:
        rsrc_updates.append(geyser.ResourceUpdate(geyser.METRIC, "fan_monitor:fans:status", fan_name, status))

    if speed is not None:
        rsrc_updates.append(geyser.ResourceUpdate(geyser.METRIC, "fan_monitor:fans:fanRpmSensorValue", fan_name, speed))

    # TBD: how do we want to handle errors?
    # we don't really want to spam syslog and these updates will be
    # pushed periodically so do we care if one send fails?
    rv = geyser_client.send(rsrc_updates)

def log(msg):
    if args.log_en:
        print msg

def log_err(msg):
    sys.stderr.write("Fan monitor: " + msg + "\n")

def get_sensors(sensor_type):
    sensor_args = ["/usr/bin/sensors", "{0}-*".format(sensor_type)]

    retry = 0
    retry_max = 4
    retry_wait = 1
    while True:
        retry += 1

        try:
            sensor_data_input = subprocess.Popen(sensor_args, stdout=subprocess.PIPE)
            (sensor_data_stdout, sensor_data_stderr) = sensor_data_input.communicate()
        except Exception, e:
            if retry < retry_max:
                log_err('exception, retry sensors: {0}'.format(retry))
                time.sleep(retry_wait)
                retry_wait *= 2
                next
            else:
                raise e

        if len(sensor_data_stdout) == 0:
            if retry < retry_max:
                log_err('no data, retry sensors: {0}'.format(retry))
                time.sleep(retry_wait)
                retry_wait *= 2
                next
            else:
                raise RuntimeError('no output from sensors')
        else:
            break

    return sensor_data_stdout.splitlines()

# Returns (0,  fan_count, fan_sensor) on valid reading
# Returns (-1, fan_count, fan_sensor) on invalid reading
def parse_sensor_data(geyser_client, sensor_data, fan_high, sensor_line_re):
    fan_count = 0
    fan_sensor = []
    fan_count_err = False
    invalid_read_multiplier = 1.20

    for line in sensor_data:
        result = sensor_line_re.match(line)
        if result is not None:
            fan_count += 1
            if (fan_count > len(fan_high)):
                fan_count_err = True
            else:
                fan_speed = int(result.group(2))
                fan_threshold = fan_high[result.group(1)]
                invalid_read = fan_threshold * invalid_read_multiplier
                fan_sensor.append((result.group(1), fan_speed, "ALARM" in line or "FAULT" in line))
                if fan_speed > invalid_read:
                    errstr = "speed {0} is invalid -- over {1}. Retrying sensors.".format(fan_speed, invalid_read)
                    log_err(errstr)

                    geyser_update_fan_info(geyser_client, fname, status="INVALID")
                    return -1, fan_count, fan_sensor
                else:
                    log("found speed: {0}".format(fan_speed))

    if fan_count_err or fan_count != len(fan_high):
        log_err("found {0} fans, but expected to find {1}".format(fan_count, len(fan_high)))
        sys.exit(100)

    return 0, fan_count, fan_sensor


def get_optional(config, section, option):
    return None if not config.has_option(section, option) else config.get(section, option)


def get_led_config(config, section, item):
    led = item
    parts = get_optional(config, section, item + "_parts")
    ok_led_status = get_optional(config, section, item + "_ok_led_status")
    problem_led_status = get_optional(config, section, item + "_problem_led_status")
    if not ((parts is not None and ok_led_status is not None and problem_led_status is not None)
       or (parts is None and ok_led_status is None and problem_led_status is None)):
        raise ConfigParser.Error("LED config invalid for '{0}'".format(item))

    return led, parts, ok_led_status, problem_led_status


def show_status(led_controller, led_config, fan_status):
    led, parts, ok_led_status, problem_led_status = led_config
    parts_list = [x.strip() for x in parts.split(',')]
    try:
        for fan in parts_list:
            if fan_status[fan] != STATUS_OK:
                led_controller.set_status(led, problem_led_status)
                return
        #We have checked all fans, no problem
        led_controller.set_status(led, ok_led_status)
    except Exception, e:
        log_err(str(e))

def get_parser():
    parser = argparse.ArgumentParser(
            description="fan_monitor.py - Report fan status and speed",
            formatter_class=argparse.RawDescriptionHelpFormatter)

    parser.add_argument("-d", "--debug_log", dest="log_en", action="store_true",
                        help="enable debug logging",default=False)

    parser.add_argument("-g", "--geyser", dest="geyser", action="store_true",
                        help="enable publishing to geyser", default=False)
    return parser

def main():
    parser = get_parser()
    global args
    args = parser.parse_args()

    config = ConfigParser.RawConfigParser()
    log("Reading configuration from " + config_file)
    config.read(config_file)

    try:
        num_fans = config.getint('Control', 'num_fans')
        log("num_fans = {0}".format(num_fans))
    except ConfigParser.NoSectionError, e:
        # no config file
        log_err("missing config file {0}".format(config_file))
        sys.exit(101)

    sensor_type = config.get('Control', 'sensor_type')
    report_overspeed_on_fan_failure = config.getboolean('Control', 'report_overspeed_on_fan_failure')

    # connect to Geyser
    geyser_client = None
    if args.geyser:
        # If geyser client setup fails, continue as normal
        # This is falling back to the original event notification
        # of posting to syslog
        try:
            geyser_client = geyser.GeyserClient()
        except:
            # log error if geyser is unexpected down
            log_err("Failed to connect to geyserd")
            pass

    ## Perform Fan Check
    fan_low = dict()
    fan_high = dict()
    fan_re = re.compile("(fan\d+)_(low|high)")
    for fan in config.items('Fans'):
        result = fan_re.search(fan[0])
        if result is not None:
            fan_name = result.group(1)
            fan_threshold = result.group(2)
            if fan_threshold == 'low':
                fan_low[fan_name] = config.getint('Fans', fan[0])
            elif fan_threshold == 'high':
                fan_high[fan_name] = config.getint('Fans', fan[0])
        else:
            log_err("Found unknown fan config option: {0}".format(fan[0]))

    sensor_line_re = re.compile("^(fan\d+):  *(\d+) RPM")
    retry = 0
    retry_max = 5
    retry_wait = 1
    while True:
        retry += 1
        sensor_data = get_sensors(sensor_type)
        exit_code, fan_count, fan_sensor = parse_sensor_data(geyser_client, sensor_data, fan_high, sensor_line_re)

        if exit_code == 0:
            break
        if retry >= retry_max:
            log_err("too many invalid fan speed reads")
            sys.exit(102)
        time.sleep(retry_wait)

    rc = 0
    fan_status = dict()
    for i in range(0, fan_count):
        (fan_name, fan_speed, fan_failed) = fan_sensor[i]
        fan_status[fan_name] = STATUS_OK

        if fan_failed:
            log_err("{0}: fan failed".format(fan_name))
            fan_status[fan_name] = STATUS_FAILED

            geyser_update_fan_info(geyser_client, fan_name, status=STATUS_FAILED)
            rc += 1

    if rc == 0 or report_overspeed_on_fan_failure:
        for i in range(0, fan_count):
            (fan_name, fan_speed, fan_failed) = fan_sensor[i]
            if fan_high.get(fan_name) is not None and fan_speed > fan_high[fan_name]:
                err_str = "{0}: fan speed {1} is over threshold {2}".format(fan_name, fan_speed, fan_high[fan_name])
                log_err(err_str)

                if fan_status[fan_name] != STATUS_OK:
                    fan_status[fan_name] = STATUS_OVERSPEED
                    rc += 1
            elif fan_low.get(fan_name) is not None and fan_low[fan_name] >= fan_speed:
                err_str = "{0}: fan speed {1} is at or below threshold {2}".format(fan_name, fan_speed, fan_low[fan_name])
                log_err(err_str)

                if fan_status[fan_name] != STATUS_OK:
                    fan_status[fan_name] = STATUS_UNDERSPEED
                    rc += 1

            geyser_update_fan_info(geyser_client, fan_name, status=fan_status[fan_name], speed=fan_speed)

    ## Perform LED Check
    led_config = []
    led_controller = led_remote.DomainSocketLEDController()

    leds = get_optional(config, 'Control', 'leds')
    if(leds):
        led_list = [x.strip() for x in leds.split(',')]
        for i in led_list:
            led_config = get_led_config(config, 'LEDs', i)
            show_status(led_controller, led_config, fan_status)

    return rc

if __name__ == '__main__':
    lock_fd = process_lock.open_lockfile(sys.argv[0])
    try:
        sys.exit(main())
    finally:
        process_lock.close_lockfile(lock_fd)
