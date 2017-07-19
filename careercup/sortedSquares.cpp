//https://careercup.com/question?id=5681516425248768
/*
Given: sorted array of integers 
Return: sorted array of squares of those integers 
Ex: [1,3,5] -> [1,9,25] 

Integers can be negative.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int *sortedSquares2(int arr[], int sz) {
    int *arr2 = new int[sz]();
    sort(arr, arr + sz, [](const int lhs, const int rhs){
        return (abs(lhs) < abs(rhs));});
    for (int i = 0; i < sz; i++) {
        arr2[i] = arr[i] * arr[i];
    }
    return arr2;
}

#define SQ(n) (arr[n])*(arr[n])
int *sortedSquares(int arr[], int sz) {
    int nidx = 0, pidx = sz-1;
    int *arr2 = new int[sz]();
    int s = sz-1;
    while(nidx < pidx) {
        if (SQ(nidx) > SQ(pidx)) {
            arr2[s--] = SQ(nidx);
            nidx++;
        } else {
            arr2[s--] = SQ(pidx);
            pidx--;
        }
        if ((nidx >= sz) || (arr[nidx] >= 0)) break; 
        if ((pidx < 0) || (arr[pidx] < 0)) break;
    }
    cout << nidx << " " << pidx << " " << s << endl;
    if (nidx > pidx) return arr2;
    cout << nidx << " " << pidx << " " << s << endl;
    if (arr[nidx] >= 0) {
        while(pidx >= nidx) { 
            arr2[s--] = SQ(pidx);
            pidx--;
        }
    }
    if (arr[pidx] < 0) {
        while(nidx <= pidx) { 
            arr2[s--] = SQ(nidx);
            nidx++;
        }
    }
    return arr2;
}

int main()
{
    int arr[] = { 1, 4, 6};
    int sz = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < sz; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int *arr2 = sortedSquares(arr, sz);
    for (int i = 0; i < sz; i++) {
        cout << arr2[i] << " ";
    }
    delete[] arr2;
    cout << endl;
    return 0;
}
