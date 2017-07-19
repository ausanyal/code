#bNextbNextinclude <iostream>
#include <boost/icl/split_interval_map.hpp>

using namespace std;
using namespace boost::icl;


/* The most simple example of an interval_map is an overlap counter.
   If intervals are added that are associated with the value 1,
   all overlaps of added intervals are counted as a result in the
   associated values. 
*/
typedef interval_map<int, int> OverlapCounterT;

void print_overlaps(const OverlapCounterT& counter)
{
    for(OverlapCounterT::const_iterator it = counter.begin(); it != counter.end(); it++)
    {
        discrete_interval<int> itv  = (*it).first;
        int overlaps_count = (*it).second;
        if(overlaps_count == 1)
            cout << "in interval " << itv << " intervals do not overlap" << endl;
        else
            cout << "in interval " << itv << ": "<< overlaps_count << " intervals overlap" << endl;
    }
}

void overlap_counter()
{
    OverlapCounterT overlap_counter;
    discrete_interval<int> inter_val;

    inter_val = discrete_interval<int>::right_open(4,8);
    cout << "-- adding   " << inter_val << " -----------------------------------------" << endl;
    overlap_counter += make_pair(inter_val, 1);
    print_overlaps(overlap_counter);
    cout << "-----------------------------------------------------------" << endl;

    inter_val = discrete_interval<int>::right_open(6,9);
    cout << "-- adding   " << inter_val << " -----------------------------------------" << endl;
    overlap_counter += make_pair(inter_val, 1);
    print_overlaps(overlap_counter);
    cout << "-----------------------------------------------------------" << endl;

    inter_val = discrete_interval<int>::right_open(1,9);
    cout << "-- adding   " << inter_val << " -----------------------------------------" << endl;
    overlap_counter += make_pair(inter_val, 1);
    print_overlaps(overlap_counter);
    cout << "-----------------------------------------------------------" << endl;
    
}

int main()
{
    cout << ">>Interval Container Library: Sample overlap_counter.cpp <<\n";
    cout << "-----------------------------------------------------------\n";
    overlap_counter();
    return 0;
}
