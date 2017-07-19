// https://leetcode.com/problems/integer-break/
/*
Given a positive integer n, break it into the sum of at least two positive
integers and maximize the product of those integers. Return the maximum product
you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3
+ 3 + 4).
*/
#include <iostream>

using namespace std;

class Solution {
public:
  int maxProd = 0;
  int memo[58];
  int integerBreakRecurse(int n, int prod) {
    if (n <= 1)
      return 1;
    int res = 1;
    if (memo[n])
      return memo[n];

    for (int i = 1; i <= n; i++) {
      if (i > n)
        break;
      if (!prod)
        prod = i;
      else
        prod = prod * i;
      res = max(res, i * integerBreakRecurse(n - i, prod));
      prod = 0;
    }
    memo[n] = res;
    return res;
  }

  int integerBreak(int n) {
    int prod = 0;
    if (n <= 1)
      return 0;
    if (n <= 3)
      return n - 1;
    return integerBreakRecurse(n, prod);
  }
};

int main() {
  Solution s;
  int n;
  cin >> n;
  cout << s.integerBreak(n) << endl;
}
