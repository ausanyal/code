//https://leetcode.com/problems/ransom-note/
/*
 Given  an  arbitrary  ransom  note  string  and  another  string  containing  letters from  all  the  magazines,  write  a  function  that  will  return  true  if  the  ransom   note  can  be  constructed  from  the  magazines ;  otherwise,  it  will  return  false.   

Each  letter  in  the  magazine  string  can  only  be  used  once  in  your  ransom  note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool searchMagazine(string& magazine, char a) {
            int i = 0;
            cout << "a: " << a << endl; 
            while(i < magazine.size()) {
                cout << __LINE__<< ":magazine: " << magazine << endl;
                if (magazine[i] == a) { 
                    magazine.erase(magazine.begin() + i);
                    cout << __LINE__<< ":magazine: " << magazine << endl;
                    return true;
                }
                if (magazine[i] < a) {
                    while((magazine[i] < a) && magazine.size()) {
                        magazine.erase(magazine.begin() + i);
                        cout << __LINE__<< ":magazine: " << magazine << endl;
                    }
                } else {
                    return false;
                }
            }
            return false;
        }
        bool canConstruct(string ransomNote, string magazine) {
            sort(ransomNote.begin(), ransomNote.end());
            sort(magazine.begin(), magazine.end());

            for (int i = 0; i < ransomNote.size(); i++) {
                if (!searchMagazine(magazine, ransomNote[i])) return false;    
            }

            return true;
        }
};

int main() {
    Solution s;
    cout << "canDonstruct: " << s.canConstruct("a", "b") << endl;
    return 0;
}
