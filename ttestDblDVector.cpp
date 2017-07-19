#include <iostream>
#include <vector>

using namespace std;

int main() {
  int m = 10, n = 20;
  vector<vector<pair<int, int>>> cost(
      m, vector<pair<int, int>>(n, make_pair(INT_MAX, INT_MAX)));

  return 0;
}
