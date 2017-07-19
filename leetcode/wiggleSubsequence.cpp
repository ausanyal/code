// https://leetcode.com/problems/wiggle-subsequence/
/*
A sequence of numbers is called a wiggle sequence if the differences between
successive numbers strictly alternate between positive and negative. The first
difference (if one exists) may be either positive or negative. A sequence with
fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences
(6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5]
and [1,7,4,5,5] are not wiggle sequences, the first because its first two
differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that
is a wiggle sequence. A subsequence is obtained by deleting some number of
elements (eventually, also zero) from the original sequence, leaving the
remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is
[1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

  bool checkWiggle(int delta, int prev) {
    cout << "Checking. delta " << delta << " prev " << prev;
    if (
        ((delta >= 0 && prev < 0) || prev == INT_MIN)
        ||
        ((delta < 0 && prev > 0) || prev == INT_MIN)
       ) {
      cout << " True\n";
      return true;
    }
    cout << " False \n";
    return false;
  }

  void printArr(vector<int>& res, const char *s) {
    cout << s << "\n";
    for (int i : res) cout << i << ", ";
        cout << "\n";
  }
  int wiggleMaxLength(vector<int> &nums) {
    vector<int> delta(nums.size()-1), res;
    if (nums.size() < 2) return nums.size();
    int j = 1;
    for (int i = 1; i < nums.size(); ++i) {
      delta[i-1] = nums[i] - nums[i-1];
    }
    printArr(delta, "Delta:");
    int prev = INT_MIN, count = 1;
    res.push_back(nums[0]);
    printArr(res, "Res:");
    bool flag = 1;
    for (int i = 0; i < delta.size(); ++i) {
      if (checkWiggle(delta[i], prev)) {
        flag = 1;
        int result = res[j-1] + delta[i];
        j++;
        //cout << "res[j-1] " << res[j-1] << " delta[i] " << delta[i] << "\n";
        res.push_back(result);
        count++;
        prev = delta[i];
      } else {
        delta[i] += delta[i-1];
        prev = delta[i];
        if (flag) {
          res.pop_back();
          j--;
          count--;
          flag = 0;
        }
        if ((i == (delta.size() - 1)) ||
            (i < (delta.size() - 1) && checkWiggle(delta[i + 1], prev))) {
          int result = res[j-1] + delta[i];
          j++;
          res.push_back(result);
          count++;
        }
      }
      printArr(res, "<<<<< Intermediary Res: >>>> ");
    }
    printArr(res, "Res:");
    return count;
  }

  int wiggleMaxLength2(vector<int> &nums) {
    if (nums.size() < 2)
      return nums.size();
    int up = 1, down = 1;
    for (int i = 1; i < nums.size(); i++) {
      // wiggle Up
      if ((nums[i] - nums[i - 1]) > 0)
        up = down + 1;
      // wiggle Down
      if ((nums[i] - nums[i - 1]) < 0)
        down = up + 1;
    }
    return (max(up, down));
  }

  int wiggleMaxLength1(vector<int> &nums) {
    if (nums.size() < 2)
      return nums.size();
    vector<int> seq;
    seq.push_back(0);
    for (int i = 0; i < nums.size() - 1; i++) {
      seq.push_back(nums[i + 1] - nums[i]);
    }
    int count = 1;
    for (int i = 1; i < seq.size(); i++) {
      if (((seq[i] > 0) && (seq[i - 1] <= 0)) ||
          ((seq[i] < 0) && (seq[i - 1] >= 0)))
        count++;
      else if (seq[i] == 0)
        seq[i] = seq[i - 1];
    }
    return count;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  cout << s.wiggleMaxLength(nums) << endl;
  return 0;
}
