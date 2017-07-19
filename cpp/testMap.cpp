#include <iostream>
#include <unordered_map>

using namespace std;

struct s {
    int a;
    char b;
};

using myMap = unordered_map<int, pair<struct s*, unordered_map<string, struct s>>>;
using x = unordered_map<string, struct s>;


void print_map(myMap& c) {
    for (auto a = c.begin(); a != c.end(); ++a) {
        auto& b = a->second;
         cout << a->first << " " << b.first <<"\n";
         for (auto d = b.second.begin(); d != b.second.end(); ++d) {
            cout << "\t" << d->first << " " << d->second.a << " " << d->second.b << "\n";
         }
    }
}


int main()
{
    myMap a;
    struct s s1 = {1, 'a'};
    struct s s2 = {2, 'b'};
    struct s s3 = {3, 'c'};
    a[1].first = &s1;
    a[1].second["a"] = s1;

    a[1].first = &s2;
    a[1].second["b"] = s2;

    a[2].first = &s3;
    a[2].second["c"] = s3;

    print_map(a);
    return 0;
}
