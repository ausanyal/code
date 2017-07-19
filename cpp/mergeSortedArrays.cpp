#include <iostream>
#include <ctime>

using namespace std;

void populate_arr(int* arr, int sz) {
    static int flag = 1;
    if (flag) {
        flag = 0;
        srand(time(NULL));
    }
    for (int i = 0; i < sz; i++) {
        arr[i] = rand()%100;
    }
    return;
}

void print_arr(int* arr, int sz) {
    for (int i = 0; i < sz; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeArrs(int* arr1, int sz1, int* arr2, int sz2, int sz3) {
    int i=sz1-1, j=sz2-1;
    while (1) {
        if (i >= 0 && j >= 0) {
            cout << endl << __LINE__ << " i: " << arr1[i] << " j: " << arr2[j] << endl;
            if (arr1[i] > arr2[j]) {
                arr2[sz3--] = arr1[i--];
                cout << "1" << endl;
            } else {
                arr2[sz3--] = arr2[j--];
                cout << "2" << endl;
            }
            cout << "arr2: ";
            print_arr(arr2, 10);
        } else if (i >= 0) {
            while(i >= 0) arr2[sz3--] = arr1[i--];
        } else if (j >= 0){
            while(j >= 0) arr2[sz3--] = arr2[j--];
        } else break;
    }
}

int main()
{
    int *arr1 = new int[5];
    int *arr2 = new int[10];
    populate_arr(arr1, 5);
    print_arr(arr1, 5);
    populate_arr(arr2, 5);
    print_arr(arr2, 10);
    sort(arr1, arr1 + 5);
    sort(arr2, arr2 + 5);
    print_arr(arr1, 5);
    print_arr(arr2, 5);

    mergeArrs(arr1, 5, arr2, 5, 9);
    print_arr(arr2, 10);

    return 0;
}
