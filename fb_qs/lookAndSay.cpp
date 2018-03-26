/*
 * Look and Say sequence:
 * 1
 * 11
 * 21
 * 1211
 * 111221
 * 312211
 * 13112221
 * 1113213211
 * 31131211131221
 * 13211311123113112211
 */

#include <iostream>
#include <vector>

using namespace std;

int count_num(vector<int> last, int pos, int* num, int* count) {
  int n = last[pos];
  //cout << "Inspecting: " << n << "\n";
  *count = 1;
  while (++pos < last.size()) {
    if (last[pos] == n) {
      *count = *count + 1;
    } else {
      *num = last[pos];
      //cout << "Returning next: pos: " << pos << " num: " << *num << " count: " << *count << "\n";
      return pos;
    }
  }

  //cout << "Returning end: pos: " << pos << " num: " << *num << " count: " << *count << "\n";
  return pos;
}

void LookAndSay(int n) {
  vector<int> last = {1}, curr;
  int next_num = -1, count = -1;
  while(n) {
    --n;
    int pos = 0;
    curr.clear();
    while (pos < last.size()) {
      int curr_num = last[pos];
      pos = count_num(last, pos, &next_num, &count);
      curr.push_back(count);
      curr.push_back(curr_num);
    }
    cout << ">>> ";
    for (auto& t : curr) {
      cout << t << " ";
    }
    cout << "\n";
    last = curr;
  }
}

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;
  LookAndSay(n);
  return 0;
}
