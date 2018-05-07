// https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<string, int> wset, wset_temp;
  public:
    vector<int> findSubstring(string s, vector<string>& words) {
      vector<int> res;
      if (s.empty() || !words.size()) return res;
      int l = words[0].size();
      for (auto w : words) wset[w]++;
      bool searching = false;
      int j = -1;
      for (int i = 0; i < s.size();) {
        string substr = s.substr(i, l);
        cout << "substr = " << substr << "\n";
        if (!searching) {
          cout << "Not yet searching \n";
          if (wset.find(substr) != wset.end()) {
            searching = true;
            // Remember where we started from.
            j = i;
            wset_temp = wset;
            cout << "Now searching. i = " << i << "\n";
          } else {
            // Still not searching. Go to next index.
            i++;
            cout << "Still not searching. new i = " << i << "\n";
            continue;
          }
        }
        auto it = wset_temp.find(substr);
        if (it == wset_temp.end()) {
          cout << "While searching couldnt find " << substr << "\n";
          searching = false;
          // Jump tp the next index from where last started.
          i = j+1;
          continue;
        }
        // Found the entry... erase it.
        wset_temp[substr]--;

        cout << "found in wset_temp. substr = " << substr << " entry size "
          << wset_temp[substr] << " map size " << wset_temp.size() << "\n";

        if (!wset_temp[substr]) {
          cout << "Erasing the entry \n";
          wset_temp.erase(it);
        }
        if (!wset_temp.size()) {
          res.push_back(j);
          cout << "Found a set at " << j << "\n";
        }
        // Increment by the fixed size of words to get to next word.
        i=i+l;
      }
      return res;
    }
};

int main() {
  Solution s;
  //string str = "barfoothefoobarman";
  //vector<string>words = {"foo", "bar"};
  string str = "wordgoodgoodgoodbestword";
  vector<string>words = {"word","good","best","good"};
  vector<int> v = s.findSubstring(str, words);
  for (auto i : v) cout << i << " ";
  cout << "\n";
  return 0;
}
