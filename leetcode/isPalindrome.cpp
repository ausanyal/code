#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int sum = 0;
        while(x > sum) {
            sum = (sum * 10) + (x % 10);
            x = x / 10;
        }
        return ((sum == x) || (sum/10 == x));
    }
};

int main()
{
    Solution s;
    cout << "is: " << s.isPalindrome(12321) << "\n";
    return 0;
}
