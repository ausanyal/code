#include <iostream>

using namespace std;

int numDecodings(string s) {
  int n = s.size();
  int dp[n + 1];
  dp[n] = 1;
  dp[n - 1] = (s[n - 1] == '0') ? 0 : 1;
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= 6)) {
      dp[i] = dp[i + 1] + dp[i + 2];
    } else {
      dp[i] = dp[i + 1];
    }
  }
  return dp[0];
}

int numDecodings2(string s) {
  int w = 0, w1 = (s.empty()) ? 0 : 1, w0 = 0, pre = 0, curr = 0;
  for (char c : s) {
    curr = c - '0';
    w = ((c != '0') ? w1 : 0) +
        ((pre != 0 && (pre * 10 + curr) <= 26) ? w0 : 0);
    pre = curr;
    w0 = w1;
    w1 = w;
  }
  return w1;
}

int main() {
  cout << numDecodings("123") << "\n";
  cout << numDecodings2("123") << "\n";
  return 0;
}
