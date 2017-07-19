// https://leetcode.com/problems/partition-equal-subset-sum/
/*
Given a non-empty array containing only positive integers, find if the array can
be partitioned into two subsets such that the sum of elements in both subsets is
equal.

Note:
Both the array size and each of the array element will not exceed 100.

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool canPartitionRecurse(vector<int> &nums, int idx, int sum1, int sum2) {
    cout << "idx " << idx << " sum1 " << sum1 << " sum2 " << sum2 << "\n";
    if (idx == nums.size()) {
      if (sum1 == sum2)
        return true;
      else
        return false;
    }
    return (canPartitionRecurse(nums, idx + 1, sum1 + nums[idx], sum2) ||
            canPartitionRecurse(nums, idx + 1, sum1, sum2 + nums[idx]));
  }
  bool canPartition(vector<int> &nums) {
    return canPartitionRecurse(nums, 0, 0, 0);
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 5, 12, 6};
  cout << s.canPartition(nums) << endl;
  return 0;
}
