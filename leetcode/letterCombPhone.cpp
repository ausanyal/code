// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  string numToAlpha_[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  public:
  void print_res(vector<string>& res) {
    for (auto& c : res) cout << c << " ";
    cout << "\n";
    cout << res.size();
    cout << "\n";
  }
  vector<string> letterCombinations(string digits) {
    vector<string> res;

    for (auto c : digits) {
      int num = c - '0';
      string alpha = numToAlpha_[num];
      if (alpha == "") continue;
      if (res.size() == 0) {
        for (char c : alpha) {
          string s(1, c);
          res.push_back(s);
        }
      } else {
        vector<string> adds;
        for (int i = 0; i < res.size(); ++i) {
          for (auto c2 : alpha) {
            adds.push_back(res[i] + c2);
          }
        }
        res = adds;
      }
    }
    print_res(res);
    return res;
  }
};

int main() {
  Solution s;
  string inp;
  cin >> inp;
  s.letterCombinations(inp);
  return 0;
}

