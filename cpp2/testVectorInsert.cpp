#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> s;
    vector<int> v = {1, 2, 3};
    //s.insert(v.begin(), v.end());
    copy(v.begin(), v.end(), inserter(s, s.end()));
    for (auto& it : s) {
        cout << it << "\n";
    }

    return 0;
}
