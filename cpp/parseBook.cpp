#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;

unordered_map<string, int> wordCount;
bool checkSpecial(char c) {
  return true;
}

void parseStr(string line) {
  istringstream iss(line);
  string a;
  while(iss >> a) {
    if (!checkSpecial(a.back())) continue;
    //cout << a << "\n";
    wordCount[a]++;
  }

}

struct wordCnt {
  string word;
  int count;
};

struct wordCountCompare {
  bool operator()(const wordCnt& lhs, const wordCnt& rhs) const {
    return lhs.count < rhs.count;
  }
};

list<string> getTopTen() {
  list<string> s;
  priority_queue<wordCnt, vector<wordCnt>, wordCountCompare> prioQ;
  for (const auto& it : wordCount) {
    wordCnt wC = {it.first, it.second};
    cout << it.first << ":" << it.second << "\n";
    prioQ.push(wC);
  }

//  int count = 0;
//  while(1)) {
//    s.push_back(prioQ.pop());
//    count++;
//  }

  auto func = [&]() {
    for (int count = 0; count < 10; count++)  {
      s.push_back(prioQ.top().word);
      prioQ.pop();
    }
  };
  func();
  return s;
}

int main()
{
  ifstream fst("parseStrFile.txt");
  string line;

  while(getline(fst, line)) {
    //cout << line << "\n";
    parseStr(line);
  }

  const list<string>& wordList = getTopTen();
  for (string s : wordList) cout << s << "\n";
  return 0;
}
