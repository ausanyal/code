
/* 
https://www.hackerrank.com/challenges/divisible-sum-pairs?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=45-day-campaign
You are given an array of  integers, , and a positive integer, . Find and print the number of pairs where  and  +  is divisible by .

Input Format

The first line contains  space-separated integers,  and , respectively. 
The second line contains  space-separated integers describing the respective values of .

Constraints

Output Format

Print the number of  pairs where  and  +  is evenly divisible by .

Sample Input

6 3
1 3 2 6 1 2
Sample Output

 5
Explanation

Here are the  valid pairs:
0, 2 / 0, 5 / 1, 3 / 2, 4 / 4, 5
*/

#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;


using namespace std;

int divisibleSumPairs(int n, int k, vector <int> ar) {
  int count = 0;
  for (int i = 0; i < ar.size()-1; ++i) {
    for (int j = i+1; j < ar.size(); ++j) {
      if (!((ar[i] + ar[j]) % k)) {
        cout << i << " " << j << "\n";
        count++;
      }
    }
  }
  return count;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> ar = {1, 3, 2, 6, 1, 2};
    //vector<int> ar(n);
    /*
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    */
    int result = divisibleSumPairs(n, k, ar);
    cout << result << endl;
    return 0;
}

