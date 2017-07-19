//http://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/
/*
Length of the largest subarray with contiguous elements | Set 1
Given an array of distinct integers, find length of the longest subarray which contains numbers that can be arranged in a continuous sequence.

Examples:

Input:  arr[] = {10, 12, 11};
Output: Length of the longest contiguous subarray is 3

Input:  arr[] = {14, 12, 11, 20};
Output: Length of the longest contiguous subarray is 2

Input:  arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
Output: Length of the longest contiguous subarray is 5
*/
#include <iostream>

using namespace std;

// Returns length of the longest contiguous subarray
int findLength(int arr[], int n)
{
    if (n ==0) return 0;
    int len = 0, mymin = 0, mymax = 0;
    for (int i = 0; i < n-1; i++) {
        mymin = mymax = arr[i];
        for (int j = i+1; j < n; j++) {
            int d = j-i;
            mymin = min(mymin, arr[j]);
            mymax = max(mymax, arr[j]);
            if ((mymax - mymin) == d) { 
            cout << "i: " << i << " j: " << j << " d=" << d << "(" << mymax-mymin << ") "
                << " mymax: " << mymax << " mymin: " <<  mymin << " len: " << len << endl;
                len = max(len, d);
            }
        }
    }
    return len+1;
}

int main()
{
    int arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Length of the longest contiguous subarray is "
        << findLength(arr, n) << endl;
    return 0;
}
