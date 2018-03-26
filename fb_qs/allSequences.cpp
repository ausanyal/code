#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

vector<string> all_strings;

void CountAllSequences(string n, int &curr_count, string full_string) {
  if (!n.size()) {
    ++curr_count;
    cout << full_string << "\n";
    return;
  }

  //cout << "Called with: " << n << " curr_count: " << curr_count << "\n";
  int i = -1, j= -1;
  i = n[0] - '0';
  string s_copy1 = full_string, s_copy2 = full_string;
  s_copy1 += n[0]; s_copy1 += '.';
  CountAllSequences(n.substr(1, n.size()-1), curr_count, s_copy1);
  if (n.size() > 1) j = n[1] - '0'; 
  if (j != -1 && i*10 + j < 26) {
    s_copy2 += n[0];
    s_copy2 += n[1]; s_copy2 += '.';
    CountAllSequences(n.substr(2, n.size()-2), curr_count, s_copy2);
  }
}

int main() {
  string n; 
  cin >> n;
  //cout << n << ".." << n.size() << "\n";
  if (!n.size()) cout << "Empty string \n";
  int curr_count = 0;
  string s;
  CountAllSequences(n, curr_count, s);
  cout << "curr count " << curr_count << "\n";
  return 0;
}
