#include <iostream>
#include <vector>

using namespace std;

int maxProdArr(vector<int> arr) {
  if (!arr.size())
    return 0;

  int max_prod = 1, min_prod = 1, max_so_far = 1;

  for (int i = 0; i < arr.size(); i++) {

    if (arr[i] > 0) {
      max_prod = max_prod * arr[i];
      min_prod = min(min_prod * arr[i], 1);
    } else if (arr[i] == 0) {
      max_prod = min_prod = 1;
    } else {
      int temp = max_prod;
      max_prod = max(min_prod * arr[i], 1);
      min_prod = temp * arr[i];
    }
    if (max_so_far < max_prod)
      max_so_far = max_prod;
    cout << "i " << i << " min_prod " << min_prod << " max_prod " << max_prod
         << " max_so_far " << max_so_far << endl;
  }
  return max_so_far;
}

int main() {
  vector<int> arr = {6, -3, -10, 0, 2};
  cout << maxProdArr(arr) << endl;
}
