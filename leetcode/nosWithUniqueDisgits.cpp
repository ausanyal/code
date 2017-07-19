// https://leetcode.com/problems/count-numbers-with-unique-digits/
/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0
≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of
0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
*/

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
  bool isUnique(int n) {
    while (n) {
      int x = n % 10;
      int y = n / 10;
      if (x == y)
        return false;
      n = n / 10;
    }
    return true;
  }

  int countNumbersWithUniqueDigits(int n) {
    int count = 0;
    for (int i = 0; i < pow(10, n); i++) {
      if (isUnique(i))
        count++;
    }
    return count;
  }
};

int main() {
  Solution s;
  cout << s.countNumbersWithUniqueDigits(2) << endl;

  return 0;
}
