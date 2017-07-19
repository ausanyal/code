#include <iostream>

using namespace std;

struct t {
    int a;
};

using fptr = struct t (*)(int);  

struct t fn(int x) {
    cout << x << "\n";
    struct t tt;
    tt.a = x;

    return tt;
}

int main()
{
    fptr f = fn;
    struct t tt1 = f(5);
    cout << tt1.a << "\n";
    return 0;
}
