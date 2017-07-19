//https://leetcode.com/problems/3sum-closest/
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
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
        int threeSumClosest(vector<int>& nums, int target) {
            vector<int> arr1, arr2;
            if (nums.size() < 3) return 0;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < (nums.size() - 2); i++) {
                int first = nums[i];
                int left = i+1;
                int right = nums.size()-1;
                while(left < right) {
                    cout << "f: " << first << " l: " << nums[left] << " r: " << nums[right] << endl;
                    int sum = first + nums[left] + nums[right];
                    cout << " sum: " << sum << endl;
                    if (target > sum) { 
                        int val = abs(target-sum);
                        auto it = upper_bound(arr1.begin(), arr1.end(), val);
                        arr1.insert(it, val);
                        left++;
                        cout << " t > s. val: " << val << " new left: " 
                             << left << " = " << nums[left] << endl;
                        cout << "\t\t\t Arr1: ";
                        for (auto x: arr1) cout << x << " ";
                        cout << endl;
                    }
                    else if (target < sum) {
                        int val = abs(sum - target);
                        auto it = upper_bound(arr2.begin(), arr2.end(), val);
                        arr2.insert(it, val);
                        right--;
                        cout << " t < s. val: " << val << " new right: " << right 
                             << " = " << nums[right] << endl;
                        cout << "\t\t\t Arr2: ";
                        for (auto x: arr2) cout << x << " ";
                        cout << endl;
                    }
                    else {
                        return sum;
                    }
                }
                while((i < (nums.size()-1)) && (nums[i+1] == first)) i++;
            }
            if (!arr1.size()) return (target + arr2[0]);
            else if (!arr2.size()) return (target - arr1[0]);
            cout << "Final: arr1[0]: " << arr1[0] << " arr2[0]: " << arr2[0] << endl;
            if (arr1[0] < arr2[0]) {
                cout << "Choosing arr1. sum : " << target - arr1[0] << endl;
                return (target - arr1[0]);
            } else {
                cout << "Choosing arr2. sum : " << target + arr2[0] << endl;
                return (target + arr2[0]);
            } 
        }
};

int main()
{
    Solution s;
    //vector<int> nums = {-1, 2, 1, -4};
    vector<int> nums = {0, 2, 1, -3};
    int res;
    res = s.threeSumClosest(nums, 1);
    cout << res << " ";
    cout << endl;
    return 0;
}

