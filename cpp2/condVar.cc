#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

condition_variable cv;
mutex mtx;
bool ready = false;

static inline void getMyId() {
	cout << this_thread::get_id() << "\n";
}

void printInfo(int id) {
	//this_thread::sleep_for(chrono::milliseconds(100));
	unique_lock<mutex> lck(mtx);
	cout << id << " got lock \n";
	while(!ready) {
		cout << id << " waiting on cv \n";
		cv.wait(lck);
	}
	cout << "thread : " << id << "\n";
	cv.notify_one();
}

void go() {
	cout << "Main thread 1 .. attempting to lock\n";
	unique_lock<mutex> lck(mtx);
	cout << "Main thread 2 .. got lock\n";
//	this_thread::sleep_for(chrono::seconds(3));
//	cout << "Main thread 3 .. sleep done\n";
	ready = true;
	cv.notify_one();
}

int main()
{
	thread threads[10];
	
	for (int i = 0; i < 10; ++i) {
		threads[i] = thread(printInfo, i);
	}
 	
	go();

	for (auto& th : threads) {
		th.join();
	}
	
	return 0;
}

/*
     LOG_WARN(
        0, __func__,
        ": renewRegistnration doesnt support non-empty resources " << resources);
 * 
 */