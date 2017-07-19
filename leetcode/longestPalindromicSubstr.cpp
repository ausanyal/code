//https://leetcode.com/problems/longest-palindromic-substring/
/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        bool checkIfPalindrome(string s, int p1, int p2) {
            //cout << "Checking : " << s.substr(p1, p2-p1+1) << "\n";
            p1++;
            p2--;
            while(p1 < p2) {
                if (s[p1] != s[p2]) break;
                p1++;
                p2--;
            }
            return (p1 >= p2);
        }
        string longestPalindrome2(string s) {
            if (s.size() <= 1) return s;
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            vector<vector<int>> alphaPos(300);
            for (int t = 0; t < s.size(); t++) {
                int alpha = s[t] - '0';
                vector<int>& x = alphaPos[alpha];
                x.push_back(t);
            }
            string longest;
            for (int i = 0; i < alphaPos.size(); i++) {
                vector<int> v = alphaPos[i];
                if (v.size() < 2) continue;
                int t = 0;
                for (t = 1; t < v.size(); t++) {
                    if (v[t] - v[t-1] != 1) break;
                }
                if (t == v.size()) {
                    cout << "Caught................\n";
                    if (v.size() > longest.size()) longest = s.substr(v[0], v.size());
                    continue;
                }
                cout << "i: " << i << " size: " << v.size() << endl;
                for (int j = 0; j < v.size()-1; j++)  {
                    for (int k = j + 1; k < v.size(); k++) {
                        if (checkIfPalindrome(s, v[j], v[k])) {
                            if ((v[k]-v[j]+1) > longest.size()) { 
                                longest = s.substr(v[j], v[k]-v[j]+1);
                            }
                            //cout << "Found: " << s.substr(v[j], v[k]-v[j]+1) << endl;
                        }
                    }
                }
            }
            return longest;
        }

        string longestPalindrome(string s) {
            if(s.size() <= 1) return s;
            int l, r, start = 0, len = 1;
            int n = s.size();
            // optimize the loop to not proceed if 2*(n-i) is not > len.
            // This is because at at i in the for loop below, we move to its left and right
            // using the l (left) and r(right) pointers expanding the set by 2 each time.
            for (int i = 0; i < n && ((2*(n-i)) > len); i++) {
                l = r = i;
                // optimize on repeated characters - bbbbbbb is a valid palindrome
                // also skip i to the end of such a pattern
                for (;(r+1 < n) && (s[r] == s[r+1]); r++) i = r+1;
                while((l >= 0) && (r < n) && (s[l] == s[r])) {
                    if ((r-l+1) > len) { 
                        len = r-l+1;
                        start = l;
                    }
                    l--;
                    r++;
                }
            }
            return s.substr(start, len);
        }
};

int main()
{
    Solution s;
    //string str = "abcdhdcfcgabTbagc";
    string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    cout << s.longestPalindrome(str) << " " << str.size() << endl;
    return 0;
}
