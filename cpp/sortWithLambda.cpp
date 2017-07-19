#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nums = {1, 2, -3, -20, 21, 20, 30};
  sort(nums.begin(), nums.end(),
       [](const int a, const int b) { return (abs(a) < abs(b)); });
  for (auto i : nums)
    cout << i << " ";
  cout << "\n";
}
