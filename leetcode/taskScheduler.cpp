/*
https://leetcode.com/problems/task-scheduler/#/description
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
 public:

  int leastInterval(vector<char>& tasks, int n) {
    auto compare = [](const _charFreq& a, const _charFreq& b) ->bool {
      return a.freq < b.freq;
    };
    unordered_map<char, int> chCount;
    //priority_queue<_charFreq, vector<_charFreq>, decltype(compare)> pq(compare);
    priority_queue<_charFreq> pq;
    priority_queue<int, vector<int>> pq2;
    for (char c : tasks) {
      chCount[c]++;
    }
    for (auto t : chCount) {
      //pq.push({.c = t.first, .freq = t.second});
      pq2.push(t.second);
    }
    int res = 0;
    while(!pq2.empty()) {
      int t = 0;
      vector<int> tmp;
      for (int i = 0; i <= n; ++i) {
        if (!pq2.empty()) {
          tmp.push_back(pq2.top());
          pq2.pop();
          t++;
        }
      }
      for (int c : tmp) {
        if (--c) {
          pq2.push(c);
        }
      }
      cout << "Res: " << res << "\n";
      res += (!pq2.empty() ? (n+1):t);
    }
    return res;
    /*
    vector<char> res((pq.top().freq-1) * (n+1) + 1, '.');
    int lastStart = 0;
    unordered_map<int, int> lastStartOccupied;
    while(!pq.empty()) {
      while (lastStartOccupied[lastStart] == 1) {
        cout << "lastStart " << lastStart << " char: " << res[lastStart] << "\n";
        ++lastStart;
      }
      cout << " Found available: " << lastStart << "\n";

      _charFreq x = pq.top();
      pq.pop();
      char c = x.c;
      int freq = x.freq;
      int numEnts = lastStart + ((freq-1) * (n+1)) + 1;
      cout << "processing: " << c << ": " << freq << " numEnts: " << numEnts << "\n";
      if (numEnts > res.size()) {
        int delta = numEnts - res.size();
        res.resize(res.size() + delta, '.');
        cout << "Resizing " << res.size() << " delta " << delta
            << " new size " << res.size() << "\n";
      }
      for (int i = lastStart; freq; i = i+n+1) {
        res[i] = c;
        freq--;
        lastStartOccupied[i] = 1;
        cout << "Inserting " << c << " at " << i << " freq left " << freq << "\n";
      }
    }
    cout << "Done: \n";
    for (char c : res)  {
      cout << c << " ";
    }
    cout << "\nTotal: " << res.size() << "\n";

    return res.size();
    */
  }

 private:
  typedef struct _charFreq {
    char c;
    int freq;
    bool operator<(const _charFreq& rhs ) const {
      return rhs.freq > freq;
    }
  }charFreq;
};

int main() 
{
    Solution s;
    //vector<char> tasks = {'A','A','A','B','B','B'};
    //vector<char> tasks = {'A','A','A','A','A','A','B', 'C','D','E','F','G'};
    vector<char> tasks ={'G','C','A','H','A','G','G','F','G','J','H','C','A','G','E','A','H','E','F','D','B','D','H','H','E','G','F','B','C','G','F','H','J','F','A','C','G','D','I','J','A','G','D','F','B','F','H','I','G','J','G','H','F','E','H','J','C','E','H','F','C','E','F','H','H','I','G','A','G','D','C','B','I','D','B','C','J','I','B','G','C','H','D','I','A','B','A','J','C','E','B','F','B','J','J','D','D','H','I','I','B','A','E','H','J','J','A','J','E','H','G','B','F','C','H','C','B','J','B','A','H','B','D','I','F','A','E','J','H','C','E','G','F','G','B','G','C','G','A','H','E','F','H','F','C','G','B','I','E','B','J','D','B','B','G','C','A','J','B','J','J','F','J','C','A','G','J','E','G','J','C','D','D','A','I','A','J','F','H','J','D','D','D','C','E','D','D','F','B','A','J','D','I','H','B','A','F','E','B','J','A','H','D','E','I','B','H','C','C','C','G','C','B','E','A','G','H','H','A','I','A','B','A','D','A','I','E','C','C','D','A','B','H','D','E','C','A','H','B','I','A','B','E','H','C','B','A','D','H','E','J','B','J','A','B','G','J','J','F','F','H','I','A','H','F','C','H','D','H','C','C','E','I','G','J','H','D','E','I','J','C','C','H','J','C','G','I','E','D','E','H','J','A','H','D','A','B','F','I','F','J','J','H','D','I','C','G','J','C','C','D','B','E','B','E','B','G','B','A','C','F','E','H','B','D','C','H','F','A','I','A','E','J','F','A','E','B','I','G','H','D','B','F','D','B','I','B','E','D','I','D','F','A','E','H','B','I','G','F','D','E','B','E','C','C','C','J','J','C','H','I','B','H','F','H','F','D','J','D','D','H','H','C','D','A','J','D','F','D','G','B','I','F','J','J','C','C','I','F','G','F','C','E','G','E','F','D','A','I','I','H','G','H','H','A','J','D','J','G','F','G','E','E','A','H','B','G','A','J','J','E','I','H','A','G','E','C','D','I','B','E','A','G','A','C','E','B','J','C','B','A','D','J','E','J','I','F','F','C','B','I','H','C','F','B','C','G','D','A','A','B','F','C','D','B','I','I','H','H','J','A','F','J','F','J','F','H','G','F','D','J','G','I','E','B','C','G','I','F','F','J','H','H','G','A','A','J','C','G','F','B','A','A','E','E','A','E','I','G','F','D','B','I','F','A','B','J','F','F','J','B','F','J','F','J','F','I','E','J','H','D','G','G','D','F','G','B','J','F','J','A','J','E','G','H','I','E','G','D','I','B','D','J','A','A','G','A','I','I','A','A','I','I','H','E','C','A','G','I','F','F','C','D','J','J','I','A','A','F','C','J','G','C','C','H','E','A','H','F','B','J','G','I','A','A','H','G','B','E','G','D','I','C','G','J','C','C','I','H','B','D','J','H','B','J','H','B','F','J','E','J','A','G','H','B','E','H','B','F','F','H','E','B','E','G','H','J','G','J','B','H','C','H','A','A','B','E','I','H','B','I','D','J','J','C','D','G','I','J','G','J','D','F','J','E','F','D','E','B','D','B','C','B','B','C','C','I','F','D','E','I','G','G','I','B','H','G','J','A','A','H','I','I','H','A','I','F','C','D','A','C','G','E','G','E','E','H','D','C','G','D','I','A','G','G','D','A','H','H','I','F','E','I','A','D','H','B','B','G','I','C','G','B','I','I','D','F','F','C','C','A','I','E','A','E','J','A','H','C','D','A','C','B','G','H','G','J','G','I','H','B','A','C','H','I','D','D','C','F','G','B','H','E','B','B','H','C','B','G','G','C','F','B','E','J','B','B','I','D','H','D','I','I','A','A','H','G','F','B','J','F','D','E','G','F','A','G','G','D','A','B','B','B','J','A','F','H','H','D','C','J','I','A','H','G','C','J','I','F','J','C','A','E','C','H','J','H','H','F','G','E','A','C','F','J','H','D','G','G','D','D','C','B','H','B','C','E','F','B','D','J','H','J','J','J','A','F','F','D','E','F','C','I','B','H','H','D','E','A','I','A','B','F','G','F','F','I','E','E','G','A','I','D','F','C','H','E','C','G','H','F','F','H','J','H','G','A','E','H','B','G','G','D','D','D','F','I','A','F','F','D','E','H','J','E','D','D','A','J','F','E','E','E','F','I','D','A','F','F','J','E','I','J','D','D','G','A','C','G','G','I','E','G','E','H','E','D','E','J','B','G','I','J','C','H','C','C','A','A','B','C','G','B','D','I','D','E','H','J','J','B','F','E','J','H','H','I','G','B','D'};
    int x = s.leastInterval(tasks, 1);
    cout << " X : " << x << "\n";
    return 0;
}
