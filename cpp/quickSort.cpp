#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& nums, int beg, int end) {
    int pivot = nums[end];
    int i, j;
    cout << "pivot " << nums[end] << "\n";
    for (i = beg, j = end-1; i <= j;) {
        if (nums[i] > pivot && nums[j] <= pivot) {
            iter_swap(nums.begin() + i, nums.begin()+j);
            copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
            cout << "\n";
        }
        if (nums[i] <= pivot) i++;
        if (nums[j] > pivot) j--;
    }
    iter_swap(nums.begin() + i, nums.begin()+end);
    return i;
}

void quickSort( vector<int>& nums, int beg, int end) {
    if (beg >= end) {
        //cout << "..beg " << beg << " end " << end << "\n" << flush;
        //cout << flush;
        return;
    }
    int p = partition(nums, beg, end);
    for (const int& i : nums) cout << i << " ";
    cout << "\n";
    cout << "partition " << p << "\n";
    quickSort(nums, beg, p-1);
    quickSort(nums, p+1, end);
}

int main()
{
    //vector<int> nums = {3, 5, 100, 20, 1, 7, 4};
    vector<int> nums = {9, 8, 7, 6, 5};
    quickSort(nums, 0, nums.size()-1);
    cout << "Sorted: \n";
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    return 0;
}
