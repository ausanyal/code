#include <iostream>
#include <vector>

using namespace std;
typedef unsigned int uint32_t;

#define PRINT_RANGE(count) {\
    for (auto &p: ranges) {\
        cout << count << " : " << p.first << "-" << p.second << endl;\
    }\
}

static void mergeRanges(vector<pair<uint32_t, uint32_t> >& ranges)
{
    sort(ranges.begin(), ranges.end());
    vector<pair<uint32_t, uint32_t> >::iterator it = ranges.begin();
    pair<uint32_t, uint32_t> current = *(it)++;
    while (it != ranges.end()) {
        if (current.second >= it->first) {
            pair<uint32_t, uint32_t>& x = *(it-1);
            x.second = current.second = std::max(current.second, it->second);
            it = ranges.erase(it);
        } else {
            current = *(it);
            it++;
        }
    }
}

int main()
{
    pair<uint32_t, uint32_t> p1 = make_pair(1, 2);
    pair<uint32_t, uint32_t> p2 = make_pair(2, 10);
    pair<uint32_t, uint32_t> p3 = make_pair(6, 8);

    vector<pair<uint32_t, uint32_t> > v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    mergeRanges(v);

    for (auto& p: v) {
        cout << p.first << " - " << p.second << "\n";
    } 

    return 0;
}
