#include <iostream>
#include <string>
#include <cmath>

using namespace std;
#define NUM_EDITS_ALLOWED 1

bool isValid(string s1, string s2) {
  int i, j, l1 = s1.size(), l2 = s2.size();
  if (abs(l1 - l2) > 1) return 0;

  int num_edits = 0;
  for (i = 0, j = 0; i < l1 && j < l2;) {
    if (s1[i] == s2[j]) { 
      cout << s1[i] << " = " << s2[j] << "\n";
      ++i; ++j;
    cout << s1[i] << " .. " << s2[j] << "\n";
      continue;
    }
    cout << s1[i] << " .. " << s2[j] << "\n";
    if (num_edits < NUM_EDITS_ALLOWED) {
      ++num_edits;
    } else { 
      return 0;
    }

    if (l1 == l2) {
      ++i; ++j;
    } else if (l1 < l2) {
      ++j; 
    } else {
      ++i; 
    }
  }
  if (i < l1 || j < l2) {
    cout << i << "." << l1 << "::" << j << "." << l2 << "\n";
    if (num_edits >= NUM_EDITS_ALLOWED) {
      return 0;
    }
  }

  return 1;
}

bool oneEditApart(string s1, string s2) {
  int l1 = s1.size();
  int l2 = s2.size();
  if (s1.size() > s2.size()) swap(s1, s2);
  if (l2 - l2 > 1) return 0;
  bool saw_diff = false;
  for (int i = 0, j = 0; i < l1; ++i, ++j) {
    if (s1[i] != s2[j]) {
      if (saw_diff) return 0;
      saw_diff = true; 
      if (l1 < l2) {
        --i;
      }
    }
  }
  return (saw_diff || l1 != l2);
}

int main() {
  string s1, s2;
  cout << "Enter s1 and s2: ";
  cin >> s1 >> s2;
  if (oneEditApart(s1, s2)) cout << "Valid \n";
  else cout << "Invalid \n";

  return 0;
}
