#include <iostream>
#include <ctime>

using namespace std;
#define XSZ 7
#define YSZ 8

void printMatrix(int **arr, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << " " << arr[i][j];
        }
        cout << endl;
    }
}

void buildMatrix(int **arr, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            arr[i][j] = rand()%100;
        }
    }
}

int doDsf(int **arr, int **arrh, int x, int y, int i, int j) {
    cout << "i: " << i << " j: " << j << endl;
    if ((i >= x) || (j >= y)) return 0;
    cout << "arrh[i][j]: " << arrh[i][j] << endl;
    if (arrh[i][j]) return 0;
    if ((i == x-1) && (j == y-1)) {
        cout << "=>" <<  i << " " << j << endl;
        arrh[i][j] = 1;
        return 1;
    };

    arrh[i][j] = 1;
    cout << i << " " << j << endl;
    return doDsf(arr, arrh, x, y, i+1, j+1) || 
           doDsf(arr, arrh, x, y, i+1, j)  ||
           doDsf(arr, arrh, x, y, i, j+1);

}

void dsfMatrix(int **arr, int **arrh, int x, int y) {
    // src is 0, 0
    doDsf(arr, arrh, x, y, 0, 0);
}

int main()
{
    srand(time(NULL));
    int **arr = new int*[XSZ];
    for (int i = 0; i < XSZ; i++) {
        arr[i] = new int[YSZ];
    }
    int **arrh = (int **)calloc(1, XSZ*sizeof(int*));
    for (int i = 0; i < XSZ; i++) {
        arrh[i] = (int *)calloc(1, YSZ * sizeof(int));
    }
    buildMatrix(arr, XSZ, YSZ);
    printMatrix(arr, XSZ, YSZ);
    dsfMatrix(arr, arrh, XSZ, YSZ);
    printMatrix(arrh, XSZ, YSZ);

    delete[] arr;
    free(arrh);
    return 0;
}
