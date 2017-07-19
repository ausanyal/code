#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

void printGrid (int **arr, int x, int y);
void printArray();

int myarray[5][7] = {
    { 1, 0, 0, 1, 0, 1, 1 },
    { 0, 0, 0, 1, 0, 1, 0 },
    { 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 0, 1, 1, 1, 0 },
    { 1, 0, 0, 1, 1, 1, 0 }
};

typedef struct ptInfo_ {
  int x, y;
  int ne, se, nw, sw;
  int max;
  ptInfo_() : x(0), y(0), ne(0), se(0), nw(0), sw(0), max(0) {}
} ptInfo;

void buildGrid(int **arr, int x, int y) {
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; j++) {
      arr[i][j] = rand()%2;
    }
  }

  return;
}
inline bool checkOob(int i, int j, int x, int y) {
  if (i < 0 || i > x || j < 0 || j > y) {
    cout << "\tOut of bound. i: " << i << " j: " << j << " Err.\n";
    return true;
  }
  return false;
}

inline bool alreadyProcessed(ptInfo **pI, int i, int j) {
  if (pI[i][j].max) {
    cout << "\tAlready processed. " << " i: " << i << " j: " << j
        << " Max: " << pI[i][j].max << " Err.\n";
    return true;
  }
  return false;
}

int getMax(int i1, int i2, int i3, int i4) {
  int i = max(i1, i2);
  i = max(i, i3);
  return max(i, i4);
}

int getMin(int i1, int i2, int i3, int i4) {
  int i = min(i1, i2);
  int j = min(i3, i4);
  return min(i, j);
}

int processNW(int arr[][7], ptInfo **pI, int i, int j, int x, int y, int& refNw) {
  if (checkOob(i, j, x, y)) return -1;
  if (!arr[i][j]) return 0;
  refNw = 1 + pI[i][j].nw;
  return 0;
}

int processNE(int arr[][7], ptInfo **pI, int i, int j, int x, int y, int& refNe) {
  if (checkOob(i, j, x, y)) return -1;
  if (!arr[i][j]) return 0;
  refNe = 1 + pI[i][j].ne;
  return 0;
}

int processSw(int arr[][7], ptInfo **pI, int i, int j, int x, int y, int& refSw) {
  if (checkOob(i, j, x, y)) return -1;
  if (!arr[i][j]) return 0;
  refSw = 1 + pI[i][j].sw;
  return 0;
}

int processSE(int arr[][7], ptInfo **pI, int i, int j, int x, int y, int& refSe) {
  if (checkOob(i, j, x, y)) return -1;
  if (!arr[i][j]) return 0;
  refSe = 1 + pI[i][j].se;
  return 0;
}

int getBiggestX(int arr[][7], int x, int y) {
  ptInfo **pI = new ptInfo* [x];
  for (int i1 = 0; i1 < x; i1++) {
    pI[i1] = new ptInfo[y];
  }

  int i, j;
  cout << "\n\n************* NW ***** \n";
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      if (arr[i][j])
        processNW(arr, pI, i-1, j-1, x, y, pI[i][j].nw);
    }
  }
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      cout << i << "." << j << " " << pI[i][j].nw << "\n";
    }
  }

  cout << "\n************* NE ****** \n";
  for (i = 0; i < x; i++) {
    for (j = y; j >= 0; j--) {
      if (arr[i][j])
        processNE(arr, pI, i-1, j+1, x, y, pI[i][j].ne);
    }
  }
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      cout << i << "." << j << " " << pI[i][j].ne << "\n";
    }
  }

  cout << "\n************* SW ******\n";
  for (i = x; i >= 0; i--) {
    for (j = 0; j < y; j++) {
      if (arr[i][j])
        processNW(arr, pI, i+1, j-1, x, y, pI[i][j].sw);
      cout << i << "." << j << " " << pI[i][j].sw << "\n";
    }
  }
#if 0
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      cout << i << "." << j << " " << pI[i][j].sw << "\n";
    }
  }
#endif
return 0;
  cout << "\n************* SE *****\n";
  for (i = x; i >= 0; i--) {
    for (j = y; j >= 0; j--) {
      if (arr[i][j])
        processNW(arr, pI, i+1, j+1, x, y, pI[i][j].se);
    }
  }
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      cout << i << "." << j << " " << pI[i][j].sw << "\n";
    }
  }

  return 0;
}

int main()
{
  //int x, y;
  //cin >> x >> y;
  //cout << x << y << "\n";

  //int **arr;
  //arr = new int* [x];
  //for (int i = 0; i < x; ++i) arr[i] = new int[y];
  //srand(time(NULL));

  //buildGrid(arr, x, y);
  //cout << "\n";
  //printGrid(arr, x, y);
  //printArray();
  cout << "Reached 1\n";
  getBiggestX(myarray, 5, 7);

  //for (int i = 0; i < x; ++i) delete arr[i];
  //delete(arr);
  return 0;
}



void printArray() {
  for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 7; j++) {
        cout << myarray[i][j] << " ";
      }
      cout << "\n";
    }
}

#if 0
void printGrid (int **arr, int x, int y) {
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }

  return;
}

int processPt(int arr[][7], ptInfo **pI, int i, int j, int x, int y) {

  cout << "Checking: " << i << " " << j << "\n";
  if (checkOob(i, j, x, y)) return 0;
  if (alreadyProcessed(pI, i, j)) return pI[i][j].max;
  if (!arr[i][j]) {
    cout << "\ti: " << i << " j: " << j << " Val: 0 Err.\n";
    //cout << "\t\t\t***My max: " << i << " " << j << " : " << pI[i][j].max << "\n";
    return 0;
  }

  pI[i][j].max = 1;
  processNW(arr, pI, i-1, j-1, x, y, pI[i][j].nw);
  processNE(arr, pI, i-1, j+1, x, y, pI[i][j].ne);
  processSw(arr, pI, i+1, j-1, x, y, pI[i][j].sw);
  processSE(arr, pI, i+1, j+1, x, y, pI[i][j].se);
  int m = getMin(pI[i][j].nw, pI[i][j].ne, pI[i][j].sw, pI[i][j].se);
  cout << "Vals @ i:" << i << ", j:" << j << "=>" << pI[i][j].nw << " "
      << pI[i][j].ne << " " << pI[i][j].sw << " " << pI[i][j].se << "\n";
  //cout << "\t\t\t***My max: " << i << " " << j << " : " << pI[i][j].max << "\n";
  pI[i][j].max = max(1, m);
  cout << "\t\t\t***My max: " << pI[i][j].max << "\n";
  return pI[i][j].max;
}

#endif
