//https://careercup.com/question?id=5648393205448704
/*
You have an array of unique integer numbers and only one operation: MoveToFront(x) that moves given number to the beginning of the array. 
Write a program to sort the array using the minimum possible number of MoveToFront() calls.
*/

#include <iostream>
#include <vector>
//#include <climit>

using namespace std;
typedef vector<int>::iterator it;

void printVector(vector<int> v) {

    for (int t = 0; t < v.size(); t++) {
        cout << v[t] << " ";
    }
    cout << endl;

}

void moveToFront(vector<int>& v, int pos) {
    if (pos == 0) return;
    if (pos >= v.size()) return;
    v.insert(v.begin(), v[pos]);
    v.erase(v.begin() + (pos + 1));
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    bool max_changed = 0;
    int max = v[0], mpos = 0;
    for (int j = 0; j < v.size(); j++) {
        cout << "j:" << j << "=>" << v[j] << endl;
        int max = v[j], mpos = j;
        max_changed = 0;
        for (int i = j+1; i < v.size(); i++) {
            cout << "  i:" << i << endl;
            if (v[i] > max) {
                cout << "i: " << i << " v[i]: " << v[i] << " max:" <<  max << endl;
                max = v[i];
                mpos = i;
                max_changed = 1;
            }
        }
        if (max_changed || (j+1 >= v.size()))
            moveToFront(v, mpos);
        printVector(v); 
    }

    cout << endl;
    printVector(v); 

    return 0;
}
