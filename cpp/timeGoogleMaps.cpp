#include <iostream>
#include <ctime>
#include <list>
#include <chrono>
#include <unistd.h>

using namespace std;

/*

    0       1       2
    |      X|X      |
         0.9 1.1
    
    20 requests in ~200 milliseconds
    
    
Requests should be rejected if there were 10 requests
within the last second at any given time.
*/

unsigned long long current_time_ms()
{
    return
        chrono::duration_cast<chrono::milliseconds>(
                chrono::system_clock::now().time_since_epoch()
        ).count();
}

class GoogleMapsClient
{
  private:
    list<unsigned long long> time_series;  
  public:
    const char* make_request();
    bool record_and_check_if_exceeded();
};

// Modify make_request to rate limit requests to 10 per second.
//
// If a request should be rate limited,
//      return "RATE LIMIT EXCEEDED"
// Otherwise,
//      return "San Francisco"

bool 
GoogleMapsClient::record_and_check_if_exceeded() {
    unsigned long long t = current_time_ms();
    //Push latest time_stamp to the front
    unsigned int count = 0;
    // Ex: t = 12345...get 11345. Check in time_series if any 
    unsigned long long boundary = t - 1000;
    for (unsigned long long t1 : time_series) {
        if (count >= 10) {
            return false;
        }
        if (t1 <= boundary) {
            time_series.push_front(t);
            return true;
        }
        ++count;
    } 
    if (count >= 10) return false;
    time_series.push_front(t);
    return true;
}

const char*
GoogleMapsClient::make_request() {
    if (record_and_check_if_exceeded()) {
     return "San Francisco";
    } else {
        return "RATE LIMIT EXCEEDED";
    }
}

// time(NULL) => current time in seconds
// sleep(N) => sleep for N seconds

int main() {
    GoogleMapsClient client;

    // Call make_request 30 times,
    //
    //  1 - <current time in seconds> - San Francisco
    //  2 - <current time in seconds> - San Francisco
    //  ..
    //  30 - <current time in seconds> - San Francisco
    for (int i = 0; i < 30; ++i) {
        // Sleep for a second every 12 requests
        if ((i != 0) && !(i % 12)) { 
            // cout << " i " << i << " sleeping" << endl;
            sleep(1);
        }
        cout << i + 1 << " - " << time(NULL) << " - " << client.make_request() << endl;
    }
}
