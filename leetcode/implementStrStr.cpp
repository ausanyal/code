//https://leetcode.com/problems/implement-strstr/
/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool foundNeedle(const char *needle, const char *haystack) {
        int i = 0, j = 0;
        while(i < strlen(needle)) {
            cout << __func__ << haystack[j] << endl;
            if (needle[i++] != haystack[j++]) return false;
        }
        return true;
    }
    int strStr2(string haystack, string needle) {
        int i = 0;
        if (haystack.empty()) {
            if (!needle.empty()) return -1;
            else return 0;
        }
        if (!haystack.empty()) {
            if (needle.empty()) return 0;
        }
        cout << "starting" <<endl;
        while(i < haystack.size()) {
            if (haystack[i] == needle[0]) {
                if (foundNeedle(needle.c_str(), haystack.c_str() + i)) {
                    cout << "Found needle at: " << i << endl;
                    return i; 
                }
            }
            i++;
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        for (int i = 0, j = 0; i+j < haystack.size();) {
            if (haystack[i+j] != needle[j]) {
                i++; j = 0;
            } else {
                j++;
                if (j == needle.size()) {
                    cout << "Found needle at: " << i << endl;
                    return i;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.strStr("bca", "a") << endl;

    return 0;
}
