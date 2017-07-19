#include <iostream>
#include <vector>

using namespace std;

vector<string> getAllPerms(string s) {
    vector<string> v;
    if (!s.size()) { 
        v.push_back(string());
        return v;
    }
    if (s.size() == 1) {
        string s1(1, s[0]);
        v.push_back(s1);
        return v;
    }

    for(int i = 0; i < s.size(); ++i) {
        string t = s;
        t.erase(t.begin() + i);
        vector<string> vt = getAllPerms(t);
        for (int j = 0; j < vt.size(); ++j) {
            v.push_back(s[i] + vt[j]);
        }
    }

    return v;
}

int main()
{
    string s = "abc";
    vector<string> ps;
    ps = getAllPerms(s);
    cout << "All Perms: \n";
    copy(ps.begin(), ps.end(), ostream_iterator<string>(cout, " "));
    cout << "\n";
    return 0;
}
