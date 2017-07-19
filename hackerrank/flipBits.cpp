//https://www.hackerrank.com/challenges/flipping-bits
/*
You will be given a list of 32 bits unsigned integers. You are required to output the list of the unsigned integers you get by flipping bits in its binary representation (i.e. unset bits must be set, and set bits must be unset).

Input Format

The first line of the input contains the list size , which is followed by  lines, each line having an integer from the list.

Constraints

 

Output Format

Output one line per element from the list with the requested result.

Sample Input

3 
2147483647 
1 
0
Sample Output

2147483648 
4294967294 
4294967295
Explanation

Take 1 for example, as unsigned 32-bits is 00000000000000000000000000000001 and doing the flipping we get 11111111111111111111111111111110 which in turn is 4294967294.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    unsigned int num, max = -1;
    cin >> T;
    T = T | 0x01;
    cout << T << endl;
    for (int i = 0; i < T; i++) {
        cin >> num;
        //cout << (num ^ max) << endl;
        unsigned int t = 0, x;
        for (int i = 0; i < 32; i++) {
            x = (num & 0x01);
            cout << " x: " << x << " num : " << num ;
            num = num>>1;
            if (!x) t = (t | (0x01 << i));
            cout << " t: " << (t & (0x01<<(i))) << endl;
        }
        cout << "\n";
        cout << num << " : " << t << " :: " << (num^max)  << endl;
    }
    return 0;
}
