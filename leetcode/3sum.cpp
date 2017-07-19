//https://leetcode.com/problems/3sum/
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
    [-1, -1, 2]
    ]
*/
#include <iostream>
#include <vector>

using namespace std;

#define PRX(x) { \
    for (int i = 0; i < x.size(); i++) cout << x[i] << " "; \
    cout << "\n";\
}

class Solution {
    public:
        bool checkIfDup (vector<int> x, vector<vector<int>> res) {
            int i;
            if (!res.size()) return false;
            for (i = 0; i < res.size(); i++) {
                vector<int> y = res[i];
                int j;
                for (j = 0; j < x.size(); j++) {
                    if (x[j] != y[j]) break;
                }
                if (j == x.size()) break;
            }
            if (i == res.size()) { 
                return false;
            }
            else { 
                return true;
            }
        }
        void ts(vector<int>& nums, vector<int> x, int cs, int i, vector<vector<int>>& res) {
            if (i >= nums.size()) return;
            if (x.size() >= 3) return;
            //cout << "cs: " << cs << " i: " << i << endl;
            ts(nums, x, cs, i+1, res);
            cs += nums[i];
            x.push_back(nums[i]);
            if ((x.size() == 3) && (cs == 0)) {
                sort(x.begin(), x.end());
                if (!checkIfDup(x, res)) res.push_back(x);
                //cout << "Found match\n";
                //PRX();
                return;
            }
            ts(nums, x, cs, i+1, res);
        }
        vector<vector<int>> threeSum2(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> x;
            int cs = 0;
            ts(nums, x, cs, 0, res);
            return res;
        }
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> l;
            if (nums.size() < 3) return l;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 2; i++) {
                int first = nums[i];
                int target = first * -1;
                int left = i+1;
                int right = nums.size()-1;
                while(left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum < target) left++;
                    else if (sum > target) right--;
                    else {
                        vector<int> ll = {first, nums[left], nums[right]};
                        l.push_back(ll);
                        while((left < (nums.size()-1)) && (nums[left+1] == nums[left])) left++; 
                        left++;
                    }
                }
                while((i < (nums.size()-1)) && (nums[i+1] == first)) i++;
            }
            return l;
        }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res;
    res = s.threeSum(nums);
    for (int i = 0; i < res.size(); i++) {
        vector<int> x = res[i];
        for (int j = 0; j < x.size(); j++) {
            cout << x[j] << " ";

        }
        cout << endl;
    }
    return 0;
}

/*
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> triplests;
    unordered_set<string> tt;
    for (int i = 0; i < nums.size(); i++) {
        unordered_set<int> numSet;
        for (int j = i + 1; j < nums.size(); j++) {
            auto it = numSet.find(0 - nums[i] - nums[j]);
            if (it != numSet.end()) {
                string key = to_string(nums[i])+ to_string(*it)+to_string(nums[j]);
                if(tt.find(key)==tt.end()) {
                    triplests.push_back(vector<int>{nums[i], *it, nums[j]});
                    tt.insert(key);
                }
            }
            numSet.insert(nums[j]);
        }
    }
    return triplests;
}
*/
