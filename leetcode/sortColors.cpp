// https://leetcode.com/problems/sort-colors/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void swapElems(vector<int> &nums, int i, int j) {
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
  }

  void sortColors(vector<int> &nums) {
    int cand[] = {0, 1, 2};
    int start = 0;
    for (int i = 0; i < 3; i++) {
      while ((start < nums.size()) && (nums[start] == cand[i]))
        start++;
      for (int j = start; j < nums.size(); j++) {
        if (nums[j] == cand[i])
          swapElems(nums, j, start++);
      }
    }
  }
};

int main() {
  srand(time(NULL));
  vector<int> n;
  Solution s;
  srand(time(NULL));
  for (int i = 0; i < 100; i++) {
    n.push_back(rand() % 3);
  }
  for (int i = 0; i < 100; i++) {
    cout << n[i] << " ";
  }
  cout << "\n-----------------------\n";
  s.sortColors(n);
  for (int i = 0; i < 100; i++) {
    cout << n[i] << " ";
  }
  cout << "\n";
  return 0;
}
