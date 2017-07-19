/*
 * Alice is taking a cryptography class and finding anagrams to be very useful. We consider two strings to be anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.
 *
 * Alice decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Can you help her find this number?
 *
 * Given two strings,  and , that may or may not be of the same length, determine the minimum number of character deletions required to make  and  anagrams. Any characters can be deleted from either of the strings.
 *
 * The first line contains a single string, . 
 * The second line contains a single string, .
 *
 * Constraints
 * It is guaranteed that  and  consist of lowercase English letters.
 * Output Format
 *
 * Print a single integer denoting the number of characters which must be deleted to make the two strings anagrams of each other.
 *
 * Sample Input
 *
 * cde
 * abc
 * Sample Output
 *
 * 4
 * Explanation
 *
 * We delete the following characters from our two strings to turn them into anagrams of each other:
 *
 * Remove d and e from cde to get c.
 * Remove a and b from abc to get c.
 * We had to delete  characters to make both strings anagrams, so we print  on a new line.
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int>

int minDeletionsToconvertToAnagrams(string a, string b) {
  cout << a << " " << b << "\n";
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  cout << a << " " << b << "\n";
  int as = a.size(), bs = b.size();
  int min = min(as, bs);
  for ()
  return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  string a, b;
  cin >> a >> b;
  minDeletionsToconvertToAnagrams(a, b);
  return 0;
}

