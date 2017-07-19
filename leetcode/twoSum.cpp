// https://leetcode.com/problems/two-sum/
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int binSearch(vector<int>& nums, int first, int last, int search) {
            if (first > last) return -1;
            int mid = (first + last)/2;
            cout << "\t first " << first << " last " << last << " mid " << mid << endl;
            cout << "\tnums[mid] " << nums[mid] << " srch " << search << endl;
            if (nums[mid] == search) return mid;
            if (search < nums[mid]) return binSearch(nums, first, mid-1, search);
            else return binSearch(nums, mid+1, last, search);
        }

        vector<int> twoSum_nonWorking(vector<int>& nums, int target) {
            vector<int> ret(2, 0);
            int n = nums.size();
            sort(nums.begin(), nums.end());
            for (int i = 0; i < n-1; i++) {
                int search = target - nums[i];
                if (search >= nums[i]) {
                    cout << "i " << i << " nums[i] " << nums[i] << " srch " << search << endl; 
                    int idx = binSearch(nums, i+1, n-1, search);
                    if (idx != -1) { 
                        ret[0] = i;
                        ret[1] = idx;
                        return ret;
                    }
                }
            }
            return ret;
        }

        vector<int> twoSum_unoptimized(vector<int>& nums, int target) {
            vector<int> ret(2, 0);
            for (int i = 0; i < nums.size()-1; i++) {
                for (int j = i+1; j < nums.size(); j++) {
                    if ((nums[i] + nums[j]) == target) {
                        ret[0] = i;
                        ret[1] = j;
                        return ret;
                    }
                }
            }
            return ret;
        }

        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> mymap;
            vector<int> ret(2, 0);
            for (int i = 0; i < nums.size(); i++) { 
                if (mymap.find(nums[i]) != mymap.end()) {
                    ret[0] = mymap[nums[i]];
                    ret[1] = i;
                    return ret;
                } else {
                    mymap[target - nums[i]] = i;
                }
            }
            return ret;
        }
};

int main() {
    Solution s;
    //vector<int> nums = {2, 7, 11, 15};
    vector<int> nums = {3, 2, 4};
    vector<int> ret;
    ret = s.twoSum(nums, 5);
    cout << ret[0] << " " << ret[1] << endl;
}
