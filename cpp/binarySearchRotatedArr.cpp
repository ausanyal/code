#include <iostream>
using namespace std;

int findPartition(int *arr, int key, int beg, int end) {
    if (end-beg+1 < 2) return -1; 
    int x = beg+((end-beg+1)/2);
    if (arr[x-1] > arr[x]) return x;
    if (arr[x] < key) return findPartition(arr, key, beg, x-1);
    else return findPartition(arr, key, x+1, end);
}

int binarySearch(int *arr, int beg, int end, int key) {
    int d = end-beg;
    cout << __func__ << " d: " << d << " beg:" << beg << " end: " << end <<endl;
    if (d < 1) { 
        cout << __func__ << arr[beg + d] << " " << key << endl;
        if (arr[beg + d] == key) return beg;
        return -1;
    }
    int m = beg + (d/2);
    if (arr[m] == key) return m;
    else if (arr[m] < key) return (binarySearch(arr, m+1, end, key));
    else return (binarySearch(arr, beg, m-1, key));


}

int pivotedBinarySearch(int *arr, int n, int key) {
    int pos = findPartition(arr, arr[n-1], 0, n-1);
    cout << "pos: " << pos << endl;
    if (pos != -1) {
        if (key == arr[pos]) return pos;
        if(key > arr[pos] && key <= arr[n-1])
            return binarySearch(arr, pos+1, n-1, key);
        else 
            return binarySearch(arr, 0, pos-1, key);
    }
    return -1;
}

// Let us search 3 in below array
int main()
{
    int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int key = 1;
    printf("Index: %d\n", pivotedBinarySearch(arr1, n, key));

    return 0;
}
