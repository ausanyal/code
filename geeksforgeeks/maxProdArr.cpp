// http://www.geeksforgeeks.org/maximum-product-subarray/
/*
Maximum Product Subarray
Given an array that contains both positive and negative integers, find the
product of the maximum product subarray. Expected Time complexity is O(n) and
only O(1) extra space can be used.

Examples:

Input: arr[] = {6, -3, -10, 0, 2}
Output:   180  // The subarray is {6, -3, -10}

Input: arr[] = {-1, -3, -10, 0, 60}
Output:   60  // The subarray is {60}

Input: arr[] = {-2, -3, 0, -2, -40}
Output:   80  // The subarray is {-2, -40}
We strongly recommend that you click here and practice it, before moving on to
the solution.

The following solution assumes that the given input array always has a positive
output. The solution works for all cases mentioned above. It doesn’t work for
arrays like {0, 0, -20, 0}, {0, 0, 0}.. etc. The solution can be easily modified
to handle this case.
It is similar to Largest Sum Contiguous Subarray problem. The only thing to note
here is, maximum product can also be obtained by minimum (negative) product
ending with the previous element multiplied by this element. For example, in
array {12, 2, -3, -5, -6, -2}, when we are at element -2, the maximum product is
multiplication of, minimum product ending with -6 and -2.
*/

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
