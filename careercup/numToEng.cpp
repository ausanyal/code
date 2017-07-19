//https://careercup.com/page?pid=facebook-interview-questions

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string tens1(int num) {
    if (num == 10) return "ten";
    if (num == 11) return "eleven";
    if (num == 12) return "twelve";
    if (num == 13) return "thirteen";
    if (num == 14) return "fourteen";
    if (num == 15) return "fifteen";
    if (num == 16) return "sixteen";
    if (num == 17) return "seventeen";
    if (num == 18) return "eighteen";
    if (num == 19) return "nineteen";
}

string tens2(int num) {
    int n = num/10;
    if (n == 2) return "twenty";
    if (n == 3) return "thirty";
    if (n == 4) return "forty";
    if (n == 5) return "fifty";
    if (n == 6) return "sixty";
    if (n == 7) return "seventy";
    if (n == 8) return "eighty";
    if (n == 9) return "ninety";
}

string ones(int num) {
    if (num == 0) return "zero";
    if (num == 1) return "one";
    if (num == 2) return "two";
    if (num == 3) return "three";
    if (num == 4) return "four";
    if (num == 5) return "five";
    if (num == 6) return "six";
    if (num == 7) return "seven";
    if (num == 8) return "eight";
    if (num == 9) return "nine";

}

void numToEng(int num) {
    if (num == 0) return;
    string s = to_string(num);
    int n = s.length();
    int sb = pow(10, n-1);
    if (n == 1) {
        cout << ones(num);
        return;
    } else if (n == 2) {
        int n = num/10;
        if (n == 1) { 
            cout << tens1(num);
            return;
        } else {
            cout << tens2(num) << " ";
            return numToEng(num % sb);
        }
    } else if (n == 3) { 
        cout << ones(num/sb) << " humdred ";
        return numToEng(num % sb);
    } else  if (n == 4) { 
        cout << ones(num/sb) << " thousand ";
        return numToEng(num % sb);
    } else if (num >= 10000 and num < 1000000) {
        numToEng(num/1000);
        cout << " thousand ";
        numToEng(num%1000);
        return;
    } else if (num >= 1000000) {
        numToEng(num/1000000);
        cout << " million ";
        numToEng(num%1000000);
        return;
    }

}

int main()
{
    int num;
    cin >> num;
    numToEng(num);
    cout << endl;
    return 0;
}

