#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

/*
bool checkIfPalindrome(string s) {
    int x = s.length();
    if (x == 1) return 1;
    int i = 0, j = s.length()-1;
    while(i<j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } else break;
    }
    return (i >= j);

}

void printAllPs(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n-i+1; j++) {
            cout << s.substr(i, j);
            cout << " is : " << (checkIfPalindrome(s.substr(i, j)) ? "
palindrome\n" : "not-palindrome\n");
        }
    }
}
*/

void printPalindromes(string s, int i, set<string> &uniqPs) {
  uniqPs.insert(s.substr(i, 1));
  int j = i - 1, k = i + 1, n = s.size();
  while ((j >= 0) && (k < n)) {
    if (s[j] == s[k])
      uniqPs.insert(s.substr(j, k - j + 1));
    else
      break;
    j--, k++;
  }
}

typedef set<string>::iterator it;

void printAllPs(string s) {
  int n = s.size();
  set<string> uniqPs;
  for (int i = 0; i < n; i++) {
    printPalindromes(s, i, uniqPs);
  }
  for (it i = uniqPs.begin(); i != uniqPs.end(); i++)
    cout << *i << " ";
  cout << "\n";
}

int main() {
  string s = "abcba";
  printAllPs(s);
  return 0;
}
