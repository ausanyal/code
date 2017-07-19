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
    int partition(vector<int>& nums, int left, int right);
    int findKthLargest2(vector<int>& nums, int k);
};

int 
Solution::partition(vector<int>& nums, int left, int right) {
    // Pick a random element and make it pivot
    int r = rand() % (right - left + 1);
    //cout << "\nStart\n";
    //printNums(nums);
    swap(nums[left], nums[left + r]);
    int pivot = nums[left];
    //cout << "\n Called with left: " << left << " right: " << right 
    //    << " random: " << r << " pivot: " << pivot << endl;
    int slow = left+1;
    int fast = left+1;
    while(fast <= right) {
        if (pivot < nums[fast]) {
            swap(nums[slow++], nums[fast]);
        }
        fast++;
    }
    swap(nums[left], nums[--slow]);
    //cout << " slow: " << slow << endl;
    return slow;
}

int 
Solution::findKthLargest(vector<int>& nums, int k) {
   int l = 0; 
   int r = nums.size()-1;
   k--;

   srand(time(NULL));
   while(l <= r) {
       int n = partition(nums, l, r);
       if (n == k) {
           return nums[n];
       } else if (n < k) {
           l = n+1;
       } else {
           r = n-1;
       }
   }
   return -1;
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

int 
Solution::findKthLargest2(vector<int>& nums, int k) {
    cout << nums.size() << endl;
    vector<int> temp;
    if (k == 0) return 0;
    for (int i = 0; i < nums.size(); i++) {
        //cout << "\nInspecting : " << nums[i] << endl;
        if ((temp.size() >= k) && (nums[i] > temp[0])) {
            int t = temp[0];
            temp[0] = nums[i];
            sort(temp.begin(), temp.end());
            //cout << "Replaced: " << t << " with: " << nums[i] << " temp.size(): " << temp.size() << endl;
        } else if (temp.size() < k) {
            temp.push_back(nums[i]);
            sort(temp.begin(), temp.end());
            //cout << "Pushed: " << nums[i] << " temp.size(): " << temp.size() << endl;
        } else {
            //cout << "Skipping: " << nums[i] << endl;
        }
    }
    return temp[0];
}
