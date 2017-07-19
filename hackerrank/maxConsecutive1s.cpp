//https://www.hackerrank.com/challenges/30-binary-numbers?h_r=email&unlock_token=9b465a90346b107bd227d4238bb0c27fda5e68c2&utm_campaign=30_days_of_code_continuous&utm_medium=email&utm_source=daily_reminder
/*
Objective 
Today, we're working with binary numbers. Check out the Tutorial tab for learning materials and an instructional video!

Task 
Given a base- integer, , convert it to binary (base-). Then find and print the base- integer denoting the maximum number of consecutive 's in 's binary representation.

Input Format

A single integer, .

Constraints

Output Format

Print a single base- integer denoting the maximum number of consecutive 's in the binary representation of .

Sample Input 1

5
Sample Output 1

1
Sample Input 2

13
Sample Output 2

2
Explanation

Sample Case 1: 
The binary representation of  is , so the maximum number of consecutive 's is .

Sample Case 2: 
The binary representation of  is , so the maximum number of consecutive 's is .
*/
#include <iostream>

using namespace std;

int max1s(int n) {
    int max = 0, curr = 0;
    while(n) {
        if (n & 0x01) {
            curr++;
            if (curr > max) max = curr;
        } else {
            curr = 0;
        }
        n = n>>1;
    }
    return max;
}

int main(){
    int n;
    cin >> n;
    cout << max1s(n) << endl;
    return 0;
}

