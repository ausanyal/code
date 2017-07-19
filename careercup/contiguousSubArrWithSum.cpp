//https://careercup.com/question?id=5726440612954112
/*
Given an array of positive integers and a target total of X, find if there exists a contiguous subarray with sum = X 

[1, 3, 5, 18] X = 8 Output: True 
X = 9 Output: True 
X = 10 Output: False 
X = 40 Output :False

*/

#include <iostream>
#include <vector>

using namespace std;

bool findContiguousSubArrWithSum(vector<int>& v, int sum) {
    int last_idx = 0, ts = 0, i = 0;
    i = last_idx;
    while(i < v.size()) {
        ts += v[i];
        //cout << "i: " << i << " ts: " << ts << endl;
        i++;
        if (ts == sum) {
            return true;
        } else if (ts > sum) {
            //cout << "ts: " << ts << " exceeded sum: " << sum << endl;
            //cout << "Setting idx to " << last_idx + 1 << endl;
            last_idx += 1;
            i = last_idx;
            ts = 0;
            continue;
        }
    }
    return false;
}

int main()
{
    vector<int> v = {1, 3, 5, 18};
    cout << "8: " << findContiguousSubArrWithSum(v, 8) << endl;
    cout << "9: " << findContiguousSubArrWithSum(v, 9) << endl;
    cout << "10: " << findContiguousSubArrWithSum(v, 10) << endl;
    cout << "40: " << findContiguousSubArrWithSum(v, 40) << endl;

    cout << endl;
    return 0;
}
