// https://leetcode.com/problems/combination-sum-iv/
/*
Given an integer array with all positive numbers and no duplicates, find the
number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int sum = 0;
  void combSum4(vector<int> &nums, int target) {
    if (!nums.size())
      return;
    int n = nums.size();
    int temp = 0;
    cout << "Entering target: " << target << " sum " << sum << endl;
    for (int i = 0; i < n; i++) {
      cout << "i " << i << " target " << target << " sum " << sum << endl;
      if ((target - nums[i]) < 0) {
        cout << "Exceeded at i " << i << " total " << target - nums[i] << endl;
        continue;
      }
      if ((target - nums[i]) == 0) {
        sum++;
        cout << "\t\t\t\t\tFound at i " << i << " val " << nums[i] << " sum "
             << sum << endl;
        break;
      }
      temp = target - nums[i];
      cout << "\t\t\t\t\t using: " << i << " val " << nums[i] << " remaining "
           << temp << endl;
      cout << "before i " << i << " temp " << temp << " sum " << sum << endl;
      combinationSum4(nums, temp);
    }
    return;
  }
  int combinationSum4_2(vector<int> &nums, int t) {
    combSum4(nums, t);
    return sum;
  }

  int combinationSum4(vector<int> &nums, int target) {
    vector<int> memo(target + 1);
    memo[0] = 1;
    int n = nums.size();
    for (int i = 1; i <= target; i++) {
      for (int j = 0; j < n; j++) {
        if (i >= nums[j]) {
          memo[i] += memo[i - nums[j]];
        }
      }
    }
    return memo[target];
  }
};

int main(int argc, char const *argv[]) {
  vector<int> nums = {3, 1, 2, 4};
  Solution s;
  cout << s.combinationSum4(nums, 4) << endl;
  return 0;
}
