#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> matrix;

long getSumFirst(matrix a) {
  int sum = 0;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) {
      if (i == j)
        sum += a[i][j];
    }
  }
  return sum;
}

long getSumSec(matrix a) {
  int sum = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    for (int j = 0; j < a[i].size(); j++) {
      if ((i + j) == (a.size() - 1))
        sum += a[i][j];
    }
  }
  return sum;
}

int main() {
  int n;
  // cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  /*
    for (int a_i = 0; a_i < n; a_i++) {
      for (int a_j = 0; a_j < n; a_j++) {
        cin >> a[a_i][a_j];
      }
    }
    */
  a = {{11, 2, 4}, {4, 5, 6}, {10, 8, -12}};
  int sum1 = getSumFirst(a);
  int sum2 = getSumSec(a);

  cout << "sum1 " << sum1 << " sum2 " << sum2 << " abs " << abs(sum1 - sum2)
       << endl;
  return 0;
}
