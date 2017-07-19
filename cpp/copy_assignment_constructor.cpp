#include <iostream>

using namespace std;

class Test {
    int t, t1;
public:
    Test(int a) : t(a), t1(a) {cout << "Int constructor: " << a << "\n";} 
    Test() {t = t1 = 0 ; cout << "Default constructor \n";}
    Test(const Test& t);
    ~Test() {cout << "Destructor: " << t << " " << t1 << "\n";};
    Test& operator=(const Test& t);
};

Test::Test(const Test& test) {
    t = test.t;
    cout << "Copy constructor \n";
}

Test&
Test::operator=(const Test& test) {
    cout << "Assignment operator\n";
    this->t = this->t1 = test.t;
    return *this;
}

int main()
{
    Test t1(5);
    Test t2 = t1;
    Test t3;
    t3 = t2;
    return 0;
}
