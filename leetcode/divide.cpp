// https://leetcode.com/problems/divide-two-integers/description/
/*
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 *
 * Return the quotient after dividing dividend by divisor.
 *
 * The integer division should truncate toward zero.
 */

#include <iostream>

using namespace std;

class Solution {
  private:
  public:
    int divide(int dividend, int divisor) {
      if (!divisor || (dividend == INT_MIN && divisor == -1)) {
        return INT_MAX;
      }
      int sign = (dividend < 0) ^ (divisor < 0) ? -1:1;
      long long dvd = labs(dividend);
      long long dvs = labs(divisor);
      if (dvs == 1) return sign == -1 ? -dvd : dvd;
      else if (dvd == dvs) return sign*1;

      long long res = 0;
      while(dvd >= dvs) {
        long long t = dvs;
        long long multiple = 1;
        //cout << "B: dvd: " << dvd << " dvs: " << dvs 
        //  << " t: " << t << " multiple: " << multiple << " res: " << res << "\n";
        while((t << 1) < dvd) {
          t = t<<1;
          multiple = multiple << 1;
        }
        dvd -= t;
        res += multiple;
        //cout << "E: dvd: " << dvd << " dvs: " << dvs 
        //  << " t: " << t << " multiple: " << multiple << " res: " << res << "\n";
      }
      return sign*res; 
    }
};

int main() {
  int divident, divisor;
  cout << "Dividend: ";
  cin >> divident;
  cout << "Divisor: ";
  cin >> divisor;
  Solution s;
  cout << s.divide(divident, divisor) << "\n";
  return 0;
}
