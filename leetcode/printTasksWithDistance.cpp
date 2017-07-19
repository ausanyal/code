// https://discuss.leetcode.com/topic/28289/rearrange-tasks/6
/*
Given a set of tasks like [A, A, B], and int k, which is the waiting time
between two same tasks. Calculate the min total execution time if you are
allowed to rearrange the tasks. Assume the execution for each individual task is
1.

In above example
A A B, k = 1, without rearrangement, the execution time would be 4:

A wait A B

1  1   1 1
with rearrangement, the execution time would be 3:

A B A

1 1 1
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>

using namespace std;

struct charFreq {
  char c;
  int f;
  int lastPos;
  bool operator<(const charFreq &rhs) const { return (f > rhs.f); }
};

int getLastPos(char t, unordered_map<char, charFreq> &taskLP) {
  if (taskLP.count(t)) {
    return taskLP[t].lastPos;
  }
  return INT_MIN;
}

char addCurrGetPendingIfAny(char c, unordered_map<char, charFreq> &taskLP,
                            vector<char> &myq, int pos, int d) {
  myq.push_back(c);
  for (int i = myq.size() - 1; i >= 0; i--) {
    char t = myq[i];
    if (taskLP.count(t)) {
      charFreq x = taskLP[t];
      if ((pos - taskLP[t].lastPos) > d) {
        taskLP[t].lastPos = pos;
        return t;
      }
    }
  }
  return '=';
}

char getFromtasks(vector<char> &tasks, unordered_map<char, charFreq> &taskLP,
                  int i, int d) {
  for (int j = i + 1; j < tasks.size(); j++) {
    if (tasks[j] == '\0')
      continue;
    char t = tasks[j];
    if (taskLP.count(t)) {
      charFreq x = taskLP[t];
      if ((i - taskLP[t].lastPos) > d) {
        taskLP[t].lastPos = i;
        tasks[j] = '\0';
        return t;
      }
    } else {
      taskLP[t].lastPos = i;
      tasks[j] = '\0';
      return t;
    }
  }
  return '-';
}
void scheduleTasks(vector<char> &tasks, int d) {
  unordered_map<char, charFreq> taskLP;
  vector<char> myq;
  for (int i = 0; i < tasks.size(); i++) {
    int p = getLastPos(tasks[i], taskLP);
    if ((p != INT_MIN) && ((i - p) < d)) {
      // cout << addCurrGetPendingIfAny(tasks[i], taskLP, myq, i, d) << " ";
      cout << getFromtasks(tasks, taskLP, i, d);
    } else {
      cout << tasks[i] << " ";
      taskLP[tasks[i]].lastPos = i;
    }
  }
  cout << endl;
}

int main() {
  vector<char> tasks = {'A', 'A', 'B', 'C', 'B', 'A', 'A', 'B'};
  scheduleTasks(tasks, 3);
  return 0;
}
