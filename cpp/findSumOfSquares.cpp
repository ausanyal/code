#include <iostream>
#include <vector>

using namespace std;

int findSquares(int n, int i, vector<int>& nums) {
    //cout << "n: " << n << " i: " << i << endl;
    //cout << "So far:\n";
    //for (int j: nums) cout << j << " ";
    //cout << "\n";
    if ((i*i) > n) { 
        //cout << "Exceeded \n";
        return 0;
    }
    if ((i*i) == n) {
        cout << "*************Found match*************\n";
        for (int j: nums) cout << j << " ";
        cout << "\n****************\n";
        return 1;
    }
    int r = n - (i*i);
    //cout << "trying (r = 0) : " << i+1 << endl;
    int x = findSquares(n, i+1, nums);

    //cout << "trying : " << i+1 <<  " r: " << r << endl;
    nums.push_back(i);
    int y = findSquares(r, i+1, nums);
    if (!y)  nums.pop_back();
    int min;
    if (x < y) {
        min = x;
        //cout << i << "*" << i << ":" << i*i << endl;
    } else {
        min = y;
        //cout << "Skipping: " << i << " : " << endl;
    }
    return min;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    findSquares(n, 1, nums);

    return 0;
}
