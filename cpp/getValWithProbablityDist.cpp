#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int x, count0 = 0, count1 = 0;
    for (int j = 0; j < 100; j++) {
        for (int i = 0; i < 10000; ++i) {
            x = rand() % 100;
            if (x <= 70) {
                count1++;
            } else {
                count0++;
            }
        }
        //cout << "0: " << count0 << " 1: " << count1 << "\n"; 
        float r = count1/float(count0);
        cout <<  "% : " << r << "\n";
        if (r < 1.8 || r > 2.8) {
            cout << "Error: " << r << "\n";
        }
    }
    return 0;
}
