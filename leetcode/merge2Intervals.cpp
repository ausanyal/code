// https://discuss.leetcode.com/topic/245/merge-two-interval-lists/3
/*
Given A and B two interval lists, A has no overlap inside A and B has no overlap
inside B. Write the function to merge two interval lists, output the result with
no overlap. Ask for a very efficient solution

A naive method can combine the two list, and sort and apply merge interval in
the leetcode, but is not efficient enough.

For example,
A: [1,5], [10,14], [16,18]
B: [2,6], [8,10], [11,20]

output [1,6], [8, 20]
*/
#include <iostream>
#include <vector>

using namespace std;

void swapPairs(pair<int, int> &a, pair<int, int> &b) {
  pair<int, int> temp;
  temp = b;
  b = a;
  a = temp;
}

void mergeIntervalLists2(vector<pair<int, int>> &A, vector<pair<int, int>> &B) {
  int i = 0, j = 0;
  while (i < A.size() && j < B.size()) {
    cout << "A: [" << A[i].first << ", " << A[i].second << "] \n";
    cout << "B: [" << B[j].first << ", " << B[j].second << "] \n";
    if (A[i].second < B[j].first) {
      cout << "1\n";
      if ((i < A.size() - 1) && (A[i].second >= A[i + 1].first) &&
          (A[i].second < A[i + 1].second)) {
        A[i].second = A[i + 1].second;
        cout << "uodated\n";
        A.erase(A.begin() + i + 1);
      } else {
        i++;
      }
    } else if (B[j].second < A[i].first) {
      cout << "2\n";
      swapPairs(A[i], B[j]);
      i++;
    } else if ((A[i].first <= B[j].first) && (A[i].second >= B[j].second)) {
      cout << "3\n";
      j++;
    } else if ((B[j].first <= A[i].first) && (B[j].second >= A[i].second)) {
      cout << "4\n";
      swapPairs(A[i], B[j]);
      j++;
    } else if ((A[i].first < B[j].first) && (A[i].second < B[j].second)) {
      cout << "5\n";
      A[i].second = B[j].second;
      j++;
    } else if ((B[j].first < A[i].first) && (B[j].second < A[i].second)) {
      cout << "6\n";
      A[i].first = B[j].first;
      j++;
    } else {
      cout << "Error\n";
    }
    cout << "************* So far *****************\n";
    for (int i = 0; i < A.size(); i++) {
      cout << "[" << A[i].first << ", " << A[i].second << "] ";
    }
    cout << "\n**************************************\n";
  }

  if (i == A.size() && j != B.size()) {
    while (j < B.size()) {
      if (A[i - 1].second >= B[j].second) {
        j++;
      } else {
        A.push_back(B[j]);
      }
    }
  } else if (i != A.size() && j == B.size()) {
    int k = i + 1;
    while (k < A.size()) {
      if (A[i].second >= A[k].second) {
        A.erase(A.begin() + k);
        k++;
      }
    }
  }
}

pair<int, int> mergeIntervals(pair<int, int> &a, pair<int, int> &b) {
  pair<int, int> r = make_pair(INT_MIN, INT_MIN);
  if ((a.first <= b.first) && (a.second >= b.first)) {
    r.first = a.first;
    r.second = max(a.second, b.second);
  } else if ((b.first <= a.first) && (b.second >= a.first)) {
    r.first = b.first;
    r.second = max(a.second, b.second);
  }
  return r;
}

#define PRINT_PAIR(x)                                                          \
  cout << __LINE__ << ": [" << x.first << ", " << x.second << "]\n";

vector<pair<int, int>> mergeIntervalLists(vector<pair<int, int>> &A,
                                          vector<pair<int, int>> &B) {
  pair<int, int> currMergedList = make_pair(INT_MIN, INT_MIN);
  vector<pair<int, int>> result;
  int i = 0, j = 0;
  while ((i < A.size()) || (j < B.size())) {
    if (currMergedList.first == INT_MIN) {
      if (i < A.size()) {
        if (j < B.size()) {
          if (A[i].first <= B[j].first) {
            currMergedList = A[i];
            i++;
          } else {
            currMergedList = B[j];
            j++;
          }
        } else {
          currMergedList = A[i];
          i++;
        }
      } else {
        currMergedList = B[j];
        j++;
      }
    }
    cout << "\n\n";
    pair<int, int> r1 = make_pair(INT_MIN, INT_MIN),
                   r2 = make_pair(INT_MIN, INT_MIN);

    cout << __LINE__ << ": i " << i << " j " << j << endl;
    PRINT_PAIR(currMergedList);
    PRINT_PAIR(A[i]);

    if (i < A.size()) {
      r1 = mergeIntervals(currMergedList, A[i]);
    }
    if (r1.first != INT_MIN) {
      currMergedList = r1;
      i++;
    }

    cout << __LINE__ << ": i " << i << " j " << j << endl;
    PRINT_PAIR(currMergedList);
    PRINT_PAIR(B[j]);

    if (j < B.size()) {
      r2 = mergeIntervals(currMergedList, B[j]);
    }
    if (r2.first != INT_MIN) {
      currMergedList = r2;
      j++;
    }
    PRINT_PAIR(currMergedList);
    cout << __LINE__ << ": i " << i << " j " << j << endl;

    if ((r1.first == INT_MIN) && (r2.first == INT_MIN)) {
      result.push_back(currMergedList);
      currMergedList = make_pair(INT_MIN, INT_MIN);
      cout << __LINE__ << ": Result updated\n";
    }
  }
  return result;
}

int main() {

  vector<pair<int, int>> A = {make_pair(1, 5), make_pair(10, 14),
                              make_pair(16, 18)};
  vector<pair<int, int>> B = {make_pair(2, 6), make_pair(8, 10),
                              make_pair(11, 20)};
  /*
  vector<pair<int, int>> A = {make_pair(1, 6), make_pair(7, 9)};
  vector<pair<int, int>> B = {make_pair(2, 8), make_pair(9, 11)};
*/
  vector<pair<int, int>> res;
  res = mergeIntervalLists(A, B);
  for (int i = 0; i < res.size(); i++) {
    cout << "[" << res[i].first << ", " << res[i].second << "] ";
  }
  cout << endl;
  return 0;
}
