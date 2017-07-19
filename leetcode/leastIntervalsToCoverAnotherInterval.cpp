#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> getLeastIntervals(vector<pair<int, int>> &list,
                                         pair<int, int> b) {
  sort(list.begin(), list.end());
  vector<pair<int, int>> res, empty;
  for (int i = 0; i < list.size(); i++) {
    vector<pair<int, int>> temp;
    for (int j = i; j < list.size(); j++) {
      if (list[j].first <= b.first)
        temp.push_back(list[j]);
      else
        break;
    }
    pair<int, int> longest = make_pair(0, 0);
    for (auto t : temp) {
      if ((t.second - t.first) > (longest.second - longest.first))
        cout << "Inspecting " << t.first << "::" << t.second << " vs "
             << longest.first << "::" << longest.second << "\n";
      longest = t;
    }
    cout << "longest " << longest.first << ".." << longest.second << " ";
    res.push_back(longest);
    if (longest.second >= b.second)
      return res;
    else
      b.first = longest.second;

    cout << "\nb = " << b.first << ".." << b.second << "\n";
  }
  if (res.back().second < b.second)
    return empty;
  return res;
}

int main() {
  vector<pair<int, int>> list, list2;
  //  list = {make_pair(0, 3), make_pair(3, 4), make_pair(4, 6), make_pair(2,
  //  7)};
  list = {make_pair(0, 10),  make_pair(10, 12), make_pair(12, 16),
          make_pair(16, 21), make_pair(0, 2),   make_pair(2, 5),
          make_pair(5, 21)};
  pair<int, int> b = make_pair(0, 21);
  list2 = getLeastIntervals(list, b);
  cout << "\n";
  for (auto l : list2) {
    cout << l.first << "," << l.second << " ";
  }
  cout << "\n";

  return 0;
}
