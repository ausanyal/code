//
//  vectorAppend.cpp
//  

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a1 = {1, 2, 3};
    vector<int> a, a2 = {5, 6, 7};
    a.insert(a.end(), a1.begin(), a1.end());
    a.insert(a.end(), a2.begin(), a2.end());
    for (int i : a) {
        cout << i << " ";
    }
    cout << "a: " << a.size();
    cout << "\n";
    
    return 0;
}
