#include <iostream>
#include <boost/icl/split_interval_map.hpp>

using namespace std;
using namespace boost::icl;

typedef interval_map<int, int> OcT;

void print_map(const OcT& o) {
    for (OcT::const_iterator it = o.begin(); it != o.end(); it++) {
        int overlap_cnt = (*it).second;
        discrete_interval<int> itv = (*it).first;
        if (overlap_cnt == 1) {
            cout << "in interval: " << itv << "Does not overlap\n";
        } else {
            cout << "in interval: " << itv << "Overlaps\n";
        }
    }
}

void overlap_counter() {
    OcT overlap_counter;
    discrete_interval<int> inter_val;

    inter_val = discrete_interval<int>::right_open(1,3);
    overlap_counter += make_pair(inter_val, 1);

    inter_val = discrete_interval<int>::right_open(2, 5);
    overlap_counter += make_pair(inter_val, 1);
    print_map(overlap_counter);
}

int main()
{
    overlap_counter();
    return 0;
}

