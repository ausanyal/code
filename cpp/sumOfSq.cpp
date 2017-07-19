#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void sumOfSq(int num) {
  for (int i = 1; i <= num; i++) {
    if ((i * i > num) && (i-1 > 0)) {
      cout << "\t\t\t" <<  i-1 << "...\n";
      sumOfSq(num - ((i-1)*(i-1)));
      return;
    } else if (i*i == num) {
      cout << "\t\t\t" << i << "...\n";
      return;
    }
  }
}

/*
int minSumOfSquares(int n, vector<int> nums) {

  if (n <= 3) {
    nums.push_back(n);
    return n;
  }

  int res = n; // 1*1 ...n times
  for (int i = 1; i <= n; ++i) {
    cout << "n: " << n << " i: " << i << "\n";
    int temp = i*i;
    if (temp > n) {
      break;
    }
    nums.push_back(i);
    res = min(res, 1 + minSumOfSquares(n - temp, nums));
  }
  for (int i : nums) cout << i << " ";
  cout << "\n";
  return res;
}
*/

int minSumOfSquares(int n, vector<int> nums) {

  if (n <= 3) {
    nums.push_back(n);
    return n;
  }

  int res = n; // 1*1 ...n times
  for (int i = 1; i <= n; ++i) {
    //cout << "n: " << n << " i: " << i << "\n";
    int temp = i*i;
    if (temp > n) {
      break;
    }

    vector<int> nInt;
    nInt.push_back(i);
    int ret = 1 + minSumOfSquares(n - temp, nInt);
    if (ret < n) {
      res = n;
      nums.insert(nums.end(), nInt.begin(), nInt.end());
    }
  }
  for (int i : nums) cout << i << " ";
  cout << "\n";
  return res;
}



int main()
{
  int num;
  cin >> num;
  //sumOfSq(num);
  vector<int> nums;
  //cout << minSumOfSquares(num, nums) << "\n";
  minSumOfSquares(num, nums);
  return 0;
}
