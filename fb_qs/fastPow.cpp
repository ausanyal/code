#include <iostream>

using namespace std;

long fastPow(int base, int exp) {
  if (exp == 0) return 1;
  if (exp == 1) return base;

  if (exp % 2 == 0) { 
    long res = fastPow(base, exp/2);
    return res * res;
  } else {
    long res = fastPow(base, exp/2);
    return res * res * base;
  }
}

int main() {
  int base, exp;
  cout << "Enter base and exp: \n";
  cin >> base >> exp;
  cout << fastPow(base, exp) << "\n";
  return 0;
}
