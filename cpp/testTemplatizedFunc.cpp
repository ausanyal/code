#include <iostream>
#include <functional>
#include <typeinfo>
//cout << typeid(variable).name() << endl;

using namespace std;

class Foo {
public:
    void f1(int i) {
        cout << i << endl;
    }

    void f2(string s) {
        cout << s << endl;
    }
};

//template <typename T>
void receiveFunc(function<void(int)> Foo_api) {
       Foo_api(5); 
}

void receiveFunc(Foo ff)

int main()
{
    Foo f; 
    //auto greet = mem_fn(&Foo::f1);
    //cout << typeid(greet).name() << endl;
    //receiveFunc(f, Foo::f1);
    receiveFunc(f.f1);
    return 0;
}
