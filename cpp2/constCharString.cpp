#include <iostream>
#include <unordered_map>
#include <functional>
#include <unordered_set>


using namespace std;

struct A {
    int a1;
    int a2;
};

struct B_ {
    int b1;
    int b2;
}B;

typedef struct temp_ {
    struct A a;
    struct B_ b;
    int t1;
} temp;

namespace std {

    template <>
    struct hash<struct A> {
        size_t operator() (const struct A& a) const {
            return hash<int>()(a.a1);
        }
    };

    template <>
    struct hash<struct B_> {
        size_t operator() (const struct B_& b) const {
            return hash<int>()(b.b1) ^ hash<int>()(b.b2);
        }
    };

    template <>
    struct hash<temp> {
        size_t operator()(const temp t) const {
            return hash<struct A>()(t.a) ^ hash<struct B_>()(t.b)
                ^ hash<int>()(t.t1);
        }
    };

}

int main() 
{
    unordered_map<temp, string> myMap;
    return 0;
} 
