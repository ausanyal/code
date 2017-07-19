#!/usr/bin/python

import sys
import os
import getopt

def main():
    try:
        opts, args = getopt.getopt(sys.argv[1:], 'd:f:', ["dir=", "file="])
    except getopt.error, msg:
        print msg
    directory=None
    filen=None
    for o, a in opts:
        if o in ('-d', '--dir'):
            directory=a
        elif o in ('-f', '--file'):
            filen = a
    if filen is None:
        if directory is None:
            print "please provide dir or file"
            sys.exit(1)
        else:
            filen = directory
    gen_c_file(filen, directory)

def write_template(f):
    f.write("#include <stdio.h>\n")
    f.write("\n")
    f.write("int main()\n")
    f.write("{\n")
    f.write("\n")
    f.write("    return 0;\n")
    f.write("}\n")
    f.close()

# create file of type = filename/filename
def gen_c_file(filen , directory=None):
    if directory is None:
        directory = filen
    filetowr = str(directory) + "/" + str(filen) + ".c"
    print "file = %s" % filetowr
    if not os.path.exists(str(directory)):
        os.makedirs(str(directory))
        print "making directory ", directory
    else:
        print "Directory %s exists" % directory
    if not os.path.isfile(filetowr):
        print "accessing file ", filetowr
        f = open(filetowr, "w")
    else:
        print "file %s exists" % filetowr
        sys.exit(1)
    write_template(f)

if __name__ == "__main__":
    main()