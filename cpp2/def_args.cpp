#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class test {
 public:
  virtual void testF(int i = 5, string s = "") {
    if (s != "") cout << "!Blank\n";
    else cout << "blank \n";
    cout << "in dtest " << i << " s: " << s << "\n";
  }
};

class dtest : public test {
 public:
  void testF(int i = 50, string s = "") {
    if (s != "") cout << "!Blank\n";
    else cout << "blank \n";
    cout << "in dtest " << i << " s: " << s << "\n";
  }
};

using myMap = unordered_map<int, unordered_set<string>>;
void populateMap(myMap& intStrMapT) {
  myMap intStrMap = intStrMapT;
  for (const auto& k : intStrMap) {
    //cout << "k " << k.first << " " << k.second << "\n";
  }
}

int main()
{
  test t = dtest();
  dtest dt = dtest();

  t.testF();
  t.testF(10, "wildchar");

  dt.testF();
  dt.testF(10);

  //unordered_map<int, string> intStrMap;
  myMap intStrMap;
  //unordered_set<string> st = ß{"h", "g"};
  unordered_set<string> st ( {"red","green","blue"} );
  intStrMap = {
      {1, st}
  };
  //populateMap(intStrMap);


  vector<int> vInt = {1, 2, 3};
  cout << "first: " << vInt[0] << "\n";

  return 0;
}
