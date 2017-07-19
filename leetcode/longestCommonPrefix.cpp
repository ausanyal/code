// https://leetcode.com/problems/longest-common-prefix/
//Write a function to find the longest common prefix string amongst an array of strings.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return string();
        }
        if (strs.size() == 1) return strs[0];
        sort(strs.begin(), strs.end());
        //for (auto s: strs) cout << s << endl;
        copy(strs.begin(), strs.end(), ostream_iterator<string>(cout, "/"));
        cout << "\n";
        auto sz = min(strs[0].size(), strs[strs.size()-1].size());
        decltype(sz) i = 0;
        while(i < sz && strs[0][i] == strs[strs.size()-1][i]) {
            i++;
        }
        return string(strs[0].begin(), strs[0].begin()+i);
    }
};

int main()
{
    Solution s;
    vector<string> strs;
    strs.push_back("abdc");
    strs.push_back("abbc");
    strs.push_back("abac");
    strs.push_back("abcdef");
    strs.push_back("abxyz");
    strs.push_back("abcdfeghxyz");
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
