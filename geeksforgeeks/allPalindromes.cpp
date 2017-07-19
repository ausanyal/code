#include <iostream>
#include <vector>
using namespace std;

bool checkIfPalindrome(string s) {
    int x = s.length();
    if (x == 1) return 1;
    int i = 0, j = s.length()-1;
    while(i<j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } else break;
    }
    return (i >= j);

}

void printAllPs(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n-i+1; j++) {
            cout << s.substr(i, j);
            cout << " is : " << (checkIfPalindrome(s.substr(i, j)) ? " palindrome\n" : "not-palindrome\n");
        }
    }
}

void printAllSubstrings(char *s) {
    vector<string> *ss = new vector<string>();
    while(*s) {
        int x = 0;
        while(*(s+x)) {
            for (int y = 0; y <= x; y++) cout << s[y];
            cout << endl;
            x++;
        }
        s++;
    }
}


int main()
{
    printAllPs("abcba");
    //cout << checkIfPalindrome("aaabaaa") << endl; 
    string s1;
    //printAllPs2("abc", 0, s1);
    char s[] = "abc";
    //printAllSubstrings(s);
    return 0;
}
