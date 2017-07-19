//https://leetcode.com/problems/decode-ways/
/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int getNumDecodings(string s, int stack, int curr) {
            stack++;
            cout << "\nEntered: stack: " << stack << " s: " << s[curr] << " curr: " << curr << endl;
            if (curr==s.size()) { 
                cout << "returning 1" << endl; 
                return 1;
            }
            if (s[curr] == '0') { 
                cout << "returning 0" << endl;
                return 0;
            }
            if (curr==s.size()-1) {
                cout << "..returning 1" << endl;
                return 1;
            }
            cout << ".. "  << s[curr] << endl;
            if ((s[curr] == '1') || ((s[curr]=='2') && (s[curr+1] <='6'))) {
                cout << "...\n";
                return getNumDecodings(s, stack, curr+1) + getNumDecodings(s, stack, curr+2);
            }
            cout << ":: "  << s[curr] << endl;
            return getNumDecodings(s, stack, curr+1);
        }
        int numDecodings(string s) {
            int count=0;
            if (s.empty()) return 0;
            for (int i = 0; i < s.size()-1; i++) {
                if (s[i] == '0' && s[i+1] == '0') return 0;
            }
            count  = getNumDecodings(s, 0, 0);
            return count;
        }
        int numDecodings2(string s) {
            if (s.empty()) { cout << "1\n"; return 0; }
            if (s[0] == '0') { cout << "2\n"; return 0;}
            int num[s.size()+1];
            num[s.size()] = 1;
            if (s[s.size()-1] == '0') num[s.size()-1] = 0;
            else num[s.size()-1] = 1;
            for (int i = s.size()-2; i>=0; i--) {
                if (s[i] == '0' && s[i+1] == '0') { cout << "3\n"; return 0;}
                if ((s[i] == '1')  || ((s[i] == '2') && (s[i+1] <= 6))) {
                    num[i] = num[i+1] + num[i+2]; 
                } else {
                    num[i] = num[i+1];
                }
            }
            return num[0];
        }
        int numDecodings3(string s) {
            int ways1 = s.empty()?0:1, ways0 = 0, pre = 0;
            for (char c: s) {
                int curr = c - '0';
               int ways = (curr != 0 ? ways1:0) + (((pre != 0) && (((pre*10) + curr) <= 26)) ? ways0:0);
               ways0 = ways1, ways1 = ways, pre = curr;
            }
            return ways1;
        }
};

int main()
{
    Solution s;
    int count = 0;
    //cout << s.numDecodings("27") << endl;
    cout << s.numDecodings2("123") << endl;
    //cout << "________________________________________\n";
    //cout << s.numDecodings3("123") << endl;
    return 0;
}
