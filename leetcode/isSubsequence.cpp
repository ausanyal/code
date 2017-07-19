// https://leetcode.com/problems/is-subsequence/
/*
Given a string s and a string t, check if s is subsequence of t.
You may assume that there is only lower case English letters in both s and t.
t is potentially a very long (length ~= 500,000) string, and s is a short string
(<=100).

A subsequence of a string is a new string which is formed from the original
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters. (ie, "ace" is a subsequence of
"abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"
Return true.

Example 2:
s = "axc", t = "ahbgdc"
Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you
want to check one by one to see if T has its subsequence.
In this scenario, how would you change your code?
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    if (!s.size())
      return true;
    if (!t.size())
      return false;
    int i = 0, j = 0;
    while ((i < s.size()) && (j < t.size())) {
      if (s[i] == t[j]) {
        i++;
        j++;
      } else {
        j++;
      }
    }
    if (i == s.size())
      return true;
    return false;
  }

  typedef unordered_map<char, list<int>> charLocations;
  typedef shared_ptr<charLocations> charLocationsPtr;

  charLocationsPtr buildStrMAp(string& t) {
    charLocationsPtr charLoc = make_shared<charLocations>();
    int loc = 0;
    for(char c : t) {
      auto f = charLoc->find(c);
      if (f == charLoc->end()) {
        list<int> l;
        l.push_back(loc);
        //charLoc->insert(make_pair<char, list<int>>(c, l));
        charLoc->insert({c, l});
      } else {
        charLoc->at(c).push_back(loc);
      }
      ++loc;
    }
    return charLoc;
  }

  void printCharLocs(charLocationsPtr charLocs) {
    for (auto item : *charLocs) {
      cout << "char: " << item.first << " ";
      for (int i : item.second) {
        cout << i << " ";
      }
      cout << "\n";
    }
  }

  // For special case:
  // If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you
  // want to check one by one to see if T has its subsequence.
  bool isSubsequence2(string s, string t) {
    charLocationsPtr charLocs = buildStrMAp(t);
    printCharLocs(charLocs);
    int lastIdx = -1;
    for (char c : s) {
      auto f = charLocs->find(c);
      if (f == charLocs->end()) {
        return false;
      }
      list<int>& l = f->second;
      int x = l.front();
      l.pop_front();
      if (lastIdx != -1) {
        if (x < lastIdx) {
          return false;
        }
        lastIdx = x;
      } else {
        lastIdx = x;
      }
    }
    return true;
  }

};

int main() {
  Solution s;
  //cout << s.isSubsequence("abc", "ahbgdc") << "\n";
  //cout << s.isSubsequence("axc", "ahbgdc") << "\n";
  //cout << s.isSubsequence2("ahhgc", "ahbghdc") << "\n";
  //cout << s.isSubsequence2("abc", "ahbgdc") << "\n";
  cout << ".." << s.isSubsequence2("ahch", "ahbghdc") << "\n";
  cout << ".." << s.isSubsequence2("ahhc", "ahbghdc") << "\n";
  return 0;
}
