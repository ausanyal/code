#include <iostream>

using namespace std;

int fibMemo(int n, int* memo) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo[n] == 0) {
        memo[n] = fibMemo(n-1, memo) + fibMemo(n-2, memo);
        cout << "Computed. n: " << n << " val: " << memo[n] << endl;
    } else {
        cout << "Returning from cached.   n: " << n << " val: " << memo[n] << endl;
    }
    return memo[n];
}

int main()
{
    int memo[100];
    cout << "fib: " << fibMemo(8, memo) << endl;
    return 0;
}
