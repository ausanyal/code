#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
  public:
    int min = INT_MAX;
    vector<int> min_locs;
    int computeDistance(vector<int> res) {
      int d = 0;
     sort(res.begin(), res.end());
     for (int i = 1; i < res.size(); ++i) {
      d += abs(res[i] - res[i-1]);
     }
     if (d < min) {
       min = d;
       min_locs = res;
     }
     //cout << "Distance: " << d << " min " << min << "\n";
      return d;
    }

    int recFindMinW(unordered_map<string, vector<int>>& ch_count,
                     unordered_map<string, vector<int>>::iterator it,
                     vector<int> res) {
      if (it == ch_count.end()) {
        int r = computeDistance(res);
        return r;
      }

      vector<int> locs = it->second;

      for (int k = 0; k < locs.size(); ++k) {
        auto temp = res;
        temp.push_back(locs[k]);
        for (auto t : temp) cout << t << " ";
        cout << "\n";
        auto j = it;
        recFindMinW(ch_count, ++j, temp);
      }

      return 1;
    }

    string minWindow(string s, string t) {
      string min_str;

      if (t.size() > s.size()) return min_str;

      unordered_map<string, vector<int>> ch_count;
      for (int i = 0; i < s.size(); ++i) {
        if (t.find(s[i]) == string::npos) continue;
        if (ch_count.find(to_string(s[i])) != ch_count.end()) {
          string tt = s[i] + to_string(ch_count[to_string(s[i])].size());
          ch_count[tt].push_back(i);
        } else {
          ch_count[to_string(s[i])].push_back(i);
        }
      }

      for (auto ch : t) {
        if (ch_count.find(to_string(ch)) == ch_count.end()) return min_str;
      }
      //if (ch_count.size() != t.size()) return min_str;

      for (auto e  : ch_count) {
        cout << e.first;
        for (auto l : e.second) {
          cout << " " << l;
        }
        cout << "\n";
      }
      cout << "\n";

      vector<int> r;
      recFindMinW(ch_count, ch_count.begin(), r);

      //cout << min_locs[0] << " " << min_locs[min_locs.size()-1] << "\n";
      for (int i = min_locs[0]; i <= min_locs[min_locs.size()-1] ; ++i) {
        min_str += s[i];
      }
      //cout << "min str " << min_str << "\n";

      return min_str;
    }
};

int main() {
  Solution s;
  string str = "ADOBECODEBANC";
  string t = "ABC";
  //string str = "AA";
  //string t = "AA";
  cout << s.minWindow(str, t) << "\n";

  return 0;
}
