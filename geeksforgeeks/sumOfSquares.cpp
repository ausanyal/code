//http://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/
/*
Minimum number of squares whose sum equals to given number n
A number can always be represented as a sum of squares of other numbers. Note that 1 is a square and we can always break a number as (1*1 + 1*1 + 1*1 + …). Given a number n, find the minimum number of squares that sum to X.

Examples:

Input:  n = 100
Output: 1
100 can be written as 102. Note that 100 can also be 
written as 52 + 52 + 52 + 52, but this
representation requires 4 squares.

Input:  n = 6
Output: 3
*/
#include <iostream>

using namespace std;

int minSquares(int n, int *memo) {
    if (n <= 3) return n;
    if (memo[n]) {
        cout << "Found cached for " << n << " val: " << memo[n] << endl;
        return memo[n];
    }
    int res = n; // 1*1 + 1*1 + ... n times
    for (int i = 1; i <= n; i++) {
        int temp = i*i;
        if (temp > n) break;
        cout << "Trying: " << i << endl;
        res = min(res, 1 + minSquares(n-temp, memo));
    }
    memo[n] = res;
    return res;
}

int main()
{
    int n;
    cin >> n;
    int *memo = new int[n+1]();
    cout << minSquares(n, memo) << endl;

    return 0;
}

