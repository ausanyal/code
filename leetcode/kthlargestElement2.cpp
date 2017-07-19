//https://leetcode.com/problems/kth-largest-element-in-an-array/
/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
#include <iostream>
#include <vector>
//#include <ctime>

using namespace std;

void printNums(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k);
};

int partition(vector<int>& nums, int l, int r) {
    swap(nums[left], nums[left + (rand()%right-left+1)]);
    int pivot = nums[left];
    int slow = left+1, fast = left+1;
    while(fast <= r) {
        if (pivot < nums[fast]) {
            swap(nums[slow++], nums[fast]);
        }
        fast++;
    }
    swap(nums[--slow], nums[left]);
    return slow;
}

int 
Solution::findKthLargest(vector<int>& nums, int k) {
    if (!nums.size() < k || k ==0) return 0;
    int l = 0, r = nums.size()-1;
    k--;
    srand(time(NULL));
    while (l <= r) {
        int n = partition(nums, l, r);
        if (n == k) {
            return nums[n];
        } else if (n < k) {
            l = n+1;
        } else {
            r = n-1;
        }
    }
}

int main()
{
    Solution s;
    vector<int> nums;
    nums = {3, 2, 1, 5, 6, 4};
    cout << s.findKthLargest(nums, 2);
    cout << endl;
    return 0;
}
