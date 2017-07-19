//https://leetcode.com/problems/sort-colors/
//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note:
//You are not suppose to use the library's sort function for this problem.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void swapNums(vector<int>& nums, int a, int b) {
            int temp = nums[a];
            nums[a] = nums[b];
            nums[b] = temp;
        }
        void sortColors(vector<int>& nums) {
            int cand[] = {0, 1, 2};
            int index = 0;
            for (int i = 0; i < 3; ++i) {
                while(index < nums.size() && nums[index] == cand[i]) index++;
                for (int j = index; j < nums.size(); ++j) {
                    if (nums[j] == cand[i]) swapNums(nums, j, index++);
                }
            }
        }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 0, 0, 2, 2, 2};
    s.sortColors(nums);
    for (int i : nums) cout << i << " ";
    cout << "\n";
    return 0;
}
