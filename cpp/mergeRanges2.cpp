#include <iostream>
#include <boost/icl/interval_map.hpp>

using namespace boost::icl;

typedef std::set<discrete_interval<int> > intervals;

intervals singleton(const discrete_interval<int> &value) {
    intervals result = { value };
    return result;
}

int main() {
    interval_map<int, intervals> mymap;
    discrete_interval<int> i1 = discrete_interval<int>(2, 7);
    discrete_interval<int> i2 = discrete_interval<int>(3, 8);
    mymap.add(make_pair(i1, singleton(i1)));
    mymap.add(make_pair(i2, singleton(i2)));

    for (int i = 0; i < 10; ++i) {
        std::cout << "i: " << i << ", intervals: " << mymap(i) << std::endl;
    }
}
