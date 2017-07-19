// http://www.geeksforgeeks.org/rearrange-a-string-so-that-all-same-characters-become-at-least-d-distance-away/
/*
Rearrange a string so that all same characters become d distance away
Given a string and a positive integer d. Some characters may be repeated in the
given string. Rearrange characters of the given string such that the same
characters become d distance away from each other. Note that there can be many
possible rearrangements, the output should be one of the possible
rearrangements. If no such arrangement is possible, that should also be
reported.
Expected time complexity is O(n) where n is length of input string.

Examples:
Input:  "abb", d = 2
Output: "bab"

Input:  "aacbbc", d = 3
Output: "abcabc"

Input: "geeksforgeeks", d = 3
Output: egkegkesfesor

Input:  "aaa",  d = 2
Output: Cannot be rearranged
We strongly recommend to minimize the browser and try this yourself first.
Hint: Alphabet size may be assumed as constant (256) and extra space may be
used.

Solution: The idea is to count frequencies of all characters and consider the
most frequent character first and place all occurrences of it as close as
possible. After the most frequent character is placed, repeat the same process
for remaining characters.

1) Let the given string be str and size of string be n

2) Traverse str, store all characters and their frequencies in a Max Heap MH.
The value of frequency decides the order in MH, i.e., the most frequent
character is at the root of MH.

3) Make all characters of str as ‘\0′.
4) Do following while MH is not empty.
…a) Extract the Most frequent character. Let the extracted character be x and
its frequency be f.
…b) Find the first available position in str, i.e., find the first ‘\0′ in str.
…c) Let the first position be p. Fill x at p, p+d,.. p+(f-1)d
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define MAX 256

struct charFreq {
  char c;
  int f;
};

void maxHeapify(charFreq *freq, int i, int size) {
  int l = (2 * i) + 1;
  int r = (2 * i) + 2;
  int largest = i;
  if ((l < size) && (freq[l].f > freq[i].f)) {
    largest = l;
    //swap(freq[i], freq[l]);
  }
  if ((r < size) && (freq[r].f > freq[largest].f)) {
    largest = r;
    //swap(freq[r], freq[largest]);
  }
  if (largest != i) {
    swap(freq[i], freq[largest]);
    maxHeapify(freq, largest, size);
  }
}

charFreq extractMax(charFreq *freq, int size) {
  charFreq root = freq[0];
  cout << " x " << freq[0].c << endl;
  if (size > 1) {
    freq[0] = freq[size - 1];
    maxHeapify(freq, 0, size - 1);
  }
  return root;
}

void buildHeap(charFreq *freq, int n) {
  int i = (n - 1) / 2;
  while (i >= 0) {
    maxHeapify(freq, i, n);
    i--;
  }
}

void rearrange(char *s, int d) {
  int n = strlen(s);
  charFreq freq[MAX] = {{0, 0}};
  int m = 0;
  unordered_map<char, int> alphaPos;
  for (int i = 0; i < n; i++) {
    char x = s[i];
    int loc;
    if (!alphaPos.count(x)) {
      loc = alphaPos[x] = m;
    } else {
      loc = alphaPos[x];
    }
    if (freq[loc].c == 0) {
      freq[loc].c = x;
      m++;
    }
    freq[loc].f++;
    s[i] = '\0';
    cout << " freq[" << loc << "].f " << freq[loc].c << " : " << freq[loc].f
         << endl;
  }

  buildHeap(freq, MAX);

  for (int i = 0; i < m; i++) {
    charFreq x = extractMax(freq, MAX - i);
    int p = i;
    while ((p < strlen(s)) && (s[p] != '\0'))
      p++;
    for (int k = 0; k < x.f; k++) {
      if ((p + (d * k)) >= n) {
        cout << "Not possible\n";
        exit(0);
      }
      s[p + (d * k)] = x.c;
    }
  }
}

int main() {
  char str[] = "aabbcc";
  rearrange(str, 3);
  cout << str << endl;
}
