#include <iostream>

using namespace std;

void myFunc2(string* s) {
    cout << *s << endl;
}

void myFunc1(string& s) {
    myFunc2(&s);
}

int main()
{
    string s = "Hello";
    myFunc1(s);
    return 0;
}
