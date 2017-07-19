#include <iostream>
#include <thread>
#include <functional>
#include <chrono>
using namespace std;

void foo (int test) {
	cout << test;
	cout << "test called" << endl;
}

struct Bar {
	Bar(int num) : num_(num){}
	void print_add(int i)  const { cout << num_ + i << endl; }
	int num_;
};

struct PrintNum {
	void operator()(int num) const {
		cout << num << endl;
	}
	PrintNum(int num) : num_(num) {}
	void operator() () const {
		cout << num_ << endl;
	}
	int num_;
};

class threadPool {
private:
	int numThreads;
public:
	threadPool(int threads) : numThreads(threads) {}
	void createThreadPool(int nThreads) {}
};

void runThread(string msg) {
	cout << "Running thread :  " << msg << "\n";
}

thread start(string msg) {
	return thread([=] () {
		runThread(msg);
	});
}

int main()
{
	thread *mythread = new thread(foo, 1);
	cout << "Hello \n";
	mythread->join();
	delete mythread;

	function <void(const Bar&, int)> b_add_display = &Bar::print_add;
	Bar bar(300);
	b_add_display(bar, 1);

	function <int(Bar const &)> b_num = &Bar::num_;
	cout << b_num(bar) << endl;

	PrintNum printnum(600);
	function <void()> printN  = bind(printnum);
	function <void()> printN2 = bind(printnum, 700);
	printN();
	printN2();
	thread x = start("Thread x");
	x.join();

	return 0;
}
