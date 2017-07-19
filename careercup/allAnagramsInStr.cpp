#include <iostream>

using namespace std;

bool compareStrs(string a, string b) {
    return (a == b);
}

bool isAnagram(string a, string b) {
    cout << "a: " << a << " b: " << b << endl;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return compareStrs(a, b);
    return true;
}

void findAllAnagrams(string needle, string haystack) {
    for (int i = 0; i < (haystack.size() - needle.size() + 1); i++) {
        if (isAnagram(needle, haystack.substr(i, needle.size()))) {
            cout << "Found : " << haystack.substr(i, needle.size()) << endl;
        }
    }
}

int main()
{
    findAllAnagrams("abbc", "babcdbbacbbdefcbba");
    return 0;
}
