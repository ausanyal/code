#include <iostream>
#include <unordered_map>
#include <set>
#include <typeinfo>

using namespace std;

unordered_map<int, set<int>> m;
set<int> s;

typedef const set<int>::iterator sit;
typedef pair<bool, sit&> ret;
ret test_find(int i, int j) {
    if (m.find(i) != m.end()) {
        sit it = m.at(i).find(j);
        if (it != m.at(i).end()) {
            return make_pair(true, it);
        }
    }
    sit s;
    return make_pair(false, s);
}

int main()
{
    m[1];
    set<int> s;
    s.insert(10);
    m[0] = s;
    const set<int>::iterator it;
    sit x;
    bool f;
    pair<bool, sit> t = test_find(0, 1);
    cout << t.first << " " << *t.second << "\n";  
    return 0;
}
