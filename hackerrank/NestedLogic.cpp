//  https://www.hackerrank.com/challenges/30-nested-logic?h_r=email&unlock_token=a0feee3a87f469d5df653e5542470fc7656c47f5&utm_campaign=30_days_of_code_continuous&utm_medium=email&utm_source=daily_reminder
/*
Objective 
Today's challenge puts your understanding of nested conditional statements to the test. You already have the knowledge to complete this challenge, but check out the Tutorial tab for a video on testing!

Task 
Your local library needs your help! Given the expected and actual return dates for a library book, create a program that calculates the fine (if any). The fee structure is as follows:

If the book is returned on or before the expected return date, no fine will be charged (i.e.: .
If the book is returned after the expected return day but still within the same calendar month and year as the expected return date, .
If the book is returned after the expected return month but still within the same calendar year as the expected return date, the .
If the book is returned after the calendar year in which it was expected, there is a fixed fine of .
Input Format

The first line contains  space-separated integers denoting the respective , , and  on which the book was actually returned. 
The second line contains  space-separated integers denoting the respective , , and  on which the book was expected to be returned (due date).

Constraints

Output Format

Print a single integer denoting the library fine for the book received as input.

Sample Input

9 6 2015
6 6 2015
Sample Output

45
Explanation

Given the following return dates: 
Actual:  
Expected: 

Because , we know it is less than a year late. 
Because , we know it's less than a month late. 
Because , we know that it was returned late (but still within the same month and year).

Per the library's fee structure, we know that our fine will be . We then print the result of  as our output.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findFine(int rd, int ed, int rm, int em, int ry, int ey) {

    if (ry > ey) {
        return 100000;
    }
    if ((rm != em) && (rm > em)) return (500 * (rm - em));
    if ((rd != ed) && (rd > ed) ) return (15 * (rd - ed));

    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int rd, rm, ry; 
    int ed, em, ey; 
    int fine;
    cin >> rd >> rm >> ry; 
    cin >> ed >> em >> ey; 

    cout << findFine(rd, ed, rm, em, ry, ey) << endl;

    return 0;
}
