// https://leetcode.com/problems/frog-jump/
/*
A frog is crossing a river. The river is divided into x units and at each unit
there may or may not exist a stone. The frog can jump on a stone, but it must
not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order,
determine if the frog is able to cross the river by landing on the last stone.
Initially, the frog is on the first stone and assume the first jump must be 1
unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k,
or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping
1 unit to the 2nd stone, then 2 units to the 3rd stone, then
2 units to the 4th stone, then 3 units to the 6th stone,
4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as
the gap between the 5th and 6th stone is too large.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool canCrossRecurse(vector<int> &stones, int idx, int k) {
    if (idx == stones.size() - 1) {
      // cout << "Frog reached \n";
      return true;
    }
    int target1 = stones[idx] + k - 1;
    int target2 = stones[idx] + k;
    int target3 = stones[idx] + k + 1;
    // cout << "\nk " << k << " t " << target1 << " " << target2 << " " <<
    // target3
    //     << endl;
    for (int j = idx + 1; j < stones.size(); j++) {
      if (j > target3) {
        // cout << "j " << j << " beyond target3 " << target3 << endl;
        break;
      }
      if (stones[j] == target1) {
        // cout << "Found target1 " << target1 << " at " << j << endl;
        int x = canCrossRecurse(stones, j, k - 1);
        if (x)
          return true;
        // else
        // cout << "\t\tNext trying target2 " << target2 << " at j " << j
        //     << " k " << k << endl;
      }
      if (stones[j] == target2) {
        // cout << "Found target2 " << target2 << " at " << j << endl;
        int y = canCrossRecurse(stones, j, k);
        if (y)
          return true;
        // else
        // cout << "\t\tNext trying target3 " << target3 << " at j " << j
        //     << " k " << k << endl;
      }
      if (stones[j] == target3) {
        // cout << "Found target3 " << target3 << " at " << j << endl;
        int z = canCrossRecurse(stones, j, k + 1);
        if (z)
          return true;
        // else
        // cout << "\t\ttarget3 done... target3 " << target3 << " at j " << j
        //     << " k " << k << endl;
      }
    }
    return false;
  }

  bool canCross(vector<int> &stones) {
    if ((stones[0] != 0) || (stones[1] != 1))
      return false;
    return canCrossRecurse(stones, 1, 1);
  }

  int getNextIdx(vector<int>& stones, int idx, int nextJump) {
      if (idx >= stones.size()) {
          return -1;
      }
      int x = stones[idx];
      ++idx;
      // Walk through the array to find the nextIdx
      for (; idx < stones.size(); ++idx) {
        if (stones[idx] == (x + nextJump)) {
          return idx;
        }
      }
      return -1;
  }

  bool canCross2Recurse(vector<int>& stones, int currIdx, int lastJump) {

    cout << "CurrIdx: " << currIdx << " lastJump: " << lastJump << "\n";

    if (currIdx == (stones.size() - 1)) {
      cout << "Reached \n";
      return true;
    }

    // [0,1,3,5,6,8,12,17]
    for (int k = -1; k <= 1; ++k) {
      int nextJump = lastJump + k;
      if (nextJump <= 0) {
        cout << "k: " << k << " No fwd progress \n";
        continue;
      }

      int nextIdx = getNextIdx(stones, currIdx, nextJump);
      if (nextIdx == -1) {
        //cout << "Jump not possible \n";
        continue;
      }

      int r = canCross2Recurse(stones, nextIdx, nextJump);
      if (r == true) return true;
    }
    return false;
  }

  bool canCross2(vector<int> &stones) {
    if (stones[0] != 0 && stones[1] != 1) return false;
    return canCross2Recurse(stones, 1, 1);
  }
};

int main() {
  //vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
  // vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
  vector<int> stones = {0, 1, 2, 3, 5, 6, 8, 9, 13};
  Solution s;
  cout << s.canCross2(stones) << endl;
  return 0;
}
