#include <iostream>
#include <set>

using namespace std;

template <typename T1>
bool compareSets(const set<T1> &setA, const set<T1> &setB, set<T1> &commonSet,
                 set<T1> &diffAlessB, set<T1> &diffBlessA) {
  auto itA = setA.begin();
  auto itB = setB.begin();
  for (; (itA != setA.end()) && (itB != setB.end());) {
    if (*itA == *itB) {
      commonSet.insert(*itA);
      ++itA;
      ++itB;
    } else if (*itA < *itB) {
      diffAlessB.insert(*itA);
      ++itA;
    } else {
      diffBlessA.insert(*itB);
      ++itB;
    }
  }
  while (itA != setA.end()) {
    diffAlessB.insert(*itA);
    ++itA;
  }
  while (itB != setB.end()) {
    diffBlessA.insert(*itB);
    ++itB;
  }
  return true;
}

typedef<int, int> a;
typedef<string, string> b;
using x = tuple<a, b>;

int main() {
  int a[] = {1, 2, 3, 5, 6, 7, 10, 20};
  int b[] = {2, 3, 4, 6, 10, 11, 16};
  set<int> seta(a, a + (sizeof(a) / 4));
  set<int> setb(b, b + (sizeof(b) / 4));
  set<int> common, diff1, diff2;
  compareSets(seta, setb, common, diff1, diff2);
  cout << "common: ";
  for (const auto &c : common) {
    cout << c << " ";
  }
  cout << "\na-b: ";
  for (const auto &c : diff1) {
    cout << c << " ";
  }
  cout << "\nb-a: ";
  for (const auto &c : diff2) {
    cout << c << " ";
  }
  cout << "\n";
  return 0;
}

/*
template <typename T1>
bool compareSets(const set<T1> &setA, const set<T1> &setB, set<T1> &commonSet,
                 set<T1> &diffAlessB, set<T1> &diffBlessA) {
  set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
                   inserter(commonSet, commonSet.begin()));
  if (setA.size() != commonSet.size()) {
    set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(),
                   inserter(diffAlessB, diffAlessB.begin()));
    set_difference(setB.begin(), setB.end(), setA.begin(), setA.end(),
                   inserter(diffBlessA, diffBlessA.begin()));
    return false;
  }
  return true;
}
*/
