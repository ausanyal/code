//https://leetcode.com/problems/reverse-integer/
/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        cout << INT_MAX << endl;
        if (x < INT_MAX) cout << "OK\n";
        int isNeg = 0;
        if (x < 0) {
            isNeg = 1;
            x = x * -1;
        }
        int n = 0;
        while(x) {
            int t = x%10;
            cout << endl << "n: " << n << " x: " << x << " t: " << t << endl;
            if (((n * 10) + t) > INT_MAX) return 0;
            n = (n * 10) + t;
            x = x/10;
            cout << "n: " << n << " t:" << t << " x:" << x << endl;
        }
        if (isNeg) return (n * -1);
        return n;
    }
};

int main()
{
    Solution s;
    //cout << s.reverse(321) << endl;
    //cout << s.reverse(-10) << endl;
    cout << s.reverse(1534236469) << endl;
    return 0;
}
