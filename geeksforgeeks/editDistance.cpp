//http://www.practice.geeksforgeeks.org/problem-page.php?pid=164
/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.


Output:
Coreesponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1<=T<=30
1<= Length(str1) <= 100
1<= Length(str2) <= 100
 

 Example:
 Input:
 1
 4 5
 geek gesek

 Output:
 1
 */

#include <iostream>
using namespace std;

int findMin(int a, int b, int c) {
    return ((a<b) ? ((a<c)?a:c) : ((b<c)?b:c)); 
}

int findDistance(string x, string y, int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;

    if (x[m-1] == y[n-1]) {
        return findDistance(x, y, m-1, n-1);
    } else {
        return (1 + findMin(findDistance(x, y, m, n-1), // insert
                        findDistance(x, y, m-1, n-1), // replace
                        findDistance(x, y, m-1, n))); // remove
    }
}

int findDistanceDP(string str1, string str2, int m, int n) {
    int dp[m+1][n+1];
#if 0
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // isnert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];

            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j] = 1 + findMin(dp[i][j-1],  // Insert
                                       dp[i-1][j],  // Remove
                                       dp[i-1][j-1]); // Replace
        }
    }
    return dp[m][n];
#endif

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) 
                dp[i][j] = j;
            else if (j == 0) 
                dp[i][j] = i;
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + findMin(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
    //code
    int T, m, n;
    string x, y;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> m >> n;
        cin >> x >> y;
        cout << findDistance(x, y, m, n) << endl;
        cout << "\n";
        cout << findDistanceDP(x, y, m, n) << endl;
        cout << "\n";
    }
    return 0;
}
