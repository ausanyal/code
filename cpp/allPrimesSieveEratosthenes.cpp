// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
#include <iostream>
#include <vector>

using namespace std;

void removeMultiples(vector<int> &nums, int p) {
  // cout << __func__ << " " << nums.size() << " p " << p << "\n";
  for (int k = 2; (k * p) < nums.size(); k++) {
    // cout << "k*p " << k * p << endl;
    nums[k * p] = 0;
  }
}

void printAllPrimes(int n) {
  vector<int> nums(n + 1, 0);
  int i;
  for (i = 1; i <= n; i++) {
    nums[i] = i;
  }
  int j = 2;
  while (true) {
    removeMultiples(nums, j);
    int x = j + 1;
    while ((x < nums.size()) && !nums[x])
      x++;
    if (x >= nums.size())
      break;
    j = x;
    // cout << " Found next j " << j << endl;
  }
  for (i = 2; (i <= n); i++)
    if (nums[i])
      cout << nums[i] << " ";
  cout << "\n";
}

int main() {
  int n;
  cin >> n;
  printAllPrimes(n);
}
