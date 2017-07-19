//
//  eventProcess.cpp

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <time.h>
#include <chrono>
#include <queue>

using namespace std;
using namespace chrono;
mutex mtx;
condition_variable cv;

typedef struct evet_{
    int eventId;
    long time;
    function<void()> fp;
} event_t;

void foo(thread::id th_id) {
    int test = 5;
    cout << __func__ << " : " << th_id << "\n";
}

typedef function<void(int)> voidFuncIntParam;

queue<voidFuncIntParam> processQ;

bool queueNonEmpty() {
    return !processQ.empty();
}

void generateClientRequests(int num) {
    unique_lock<mutex> lk(mtx);
    while(1) {
        for (int i = 0; i < num; ++i) {
            //function<void()> f = bind(foo, this_thread::get_id());
            function<void(int)> f = [&](int x) {
                cout << x << " " << this_thread::get_id() << "\n";
            };
            processQ.push(f);
            cout << __func__ << "Q size : " << processQ.size() << "\n";
        }
        cv.notify_all();
        cv.wait(lk);
        // this_thread::sleep_for(seconds(2));
    }
}

void processRequests() {
    //this_thread::sleep_for(chrono::seconds(1));
    unique_lock<mutex> lk(mtx);
    while(1) {
        while(processQ.size()) {
            auto& f = processQ.front();
            processQ.pop();
            f(rand()%100);
            cout << __func__ << ": Q size : " << processQ.size() << "\n";
        }
        cv.notify_all();
        cv.wait(lk);
        // this_thread::sleep_for(seconds(2));
    }
    return;
}

int main()
{
    srand(time(NULL));
    
    thread t1(generateClientRequests, 5);
    thread t2(processRequests);
    {
        // lock_guard<mutex> lk(mtx);
    }

    t1.join();
    t2.join();
    return 0;
}
