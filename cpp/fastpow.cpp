#include <iostream>

using namespace std;

long fastPow(int a, int b) {
  static int count = 1;
  if (b == 0) return 1;
  if (b == 1) return a;
  cout << "count: " << count++ << "\n";
  long t = fastPow(a, b/2);
  if (!(b%2)) {
    return t * t;
  } else {
    return t * t * a;
  }
}


int main()
{
  cout << fastPow(2, 3) << "\n";
  return 0;
}
