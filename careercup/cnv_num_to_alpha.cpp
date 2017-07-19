//https://www.careercup.com/question?id=5765581773996032
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

class cv {
public:
    cv(int a = 0, int b = 0):x(a), y(b) {cout << "Constructed with :" << x << " " << y << endl;}
    //cv() {};
    cv operator+ (const cv& b);
public:
    int x, y;    
    //pair<int, int> get() const {return make_pair(x, y);}
    int& get() {return x;}
    const int& get() const {return x;}
};

cv cv::operator+ (const cv& b) {
    cv t;
    t.x = this->x + b.x;
    t.y = this->y + b.y;
    return t;
}

void printCv(const cv& c) {
    c.get();
}

cv operator+ (const cv& b, const cv& c) {
    cv t;
    t.x = b.x + c.x;
    t.y = b.y + c.y;
    return t;
}

template<size_t ub>
class urand {
bitset<ub> used; 
public:
    urand() {srand(time(0));}
    size_t operator()();
};

template<size_t ub>
inline size_t urand<ub>::operator()() {
    if (used.count() == ub) {
        used.reset();
        cout << "Reset\n";
    }

    size_t newval = 0;
    while(used[newval = (rand() % ub)]);
    used[newval] = true;
    return newval;
}

int main()
{
    string s("1024");
    int n=0;
    cv foo(10);
    const cv bar(20);
    foo.get() = 15;
    cout << foo.get() << " " << bar.get() <<endl;
    stringstream(s) >> n;
    cout << "num:" << n << endl;

    urand<10> u;
    for (int i = 0; i < 20; i++) {
        cout << u() << " ";
    }
    cout << endl;
    //cout << cnv_num_to_alpha(n) << endl;

    return 0;
}
