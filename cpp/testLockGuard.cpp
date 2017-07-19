#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void callFunc() {

    cout << "Before\n";
    lock_guard<mutex> l(mtx);
    cout << "After\n";
}

int main()
{
    cout << "In main 1 \n";
    lock_guard<mutex> l(mtx);
    cout << "In main 2 \n";
    callFunc();
    cout << "In main 3 \n";

    return 0;
}
