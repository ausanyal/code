#include <iostream>

using namespace std;

void get_coord(int i, int dim, int* x, int* y) {
  static int dir = -1;
  static int x_min = -1, x_max = -1;
  static int y_min = -1, y_max = -1;
  if (dir == -1) {
    dir = 0;
    *x = 0;
    *y = 0;
    x_min = y_min = 0;
    x_max = y_max = dim;
    cout << "dir: " << dir << " x: " << *x << " y: " << *y
      << " x_min: " << x_min << " x_max: " << x_max
      << " y_min: " << y_min << " y_max: " << y_max <<  "\n";
    return;
  }

  cout << "\t\t\tdir: " << dir << " x: " << *x << " y: " << *y << "\n";
  if (dir == 0) {
    if (*y < y_max-1) {
      *y += 1;
    } else {
      dir = 1;
      *x += 1;
      x_min += 1;
    }
  } else if (dir == 1) {
    if (*x < x_max-1) {
      *x += 1;
    } else {
      dir = 2;
      *y -= 1;
      y_max -= 1;
    }
  } else if (dir == 2) {
    if (*y > y_min) {
      *y -= 1;
    } else {
      dir = 3;
      *x -= 1;
      x_max -= 1;
    }
  } else if (dir == 3) {
    if (*x > x_min) {
      *x -= 1;
    } else {
      dir = 0;
      *y += 1;
      y_min += 1;
    }
  }

  cout << "dir: " << dir << " x: " << *x << " y: " << *y 
    << " x_min: " << x_min << " x_max: " << x_max
    << " y_min: " << y_min << " y_max: " << y_max <<  "\n";
}

void spiral(int** arr, int dim) {
  int x = -1, y = -1;
  for (int i = 0; i < dim * dim; ++i) {
    get_coord(i, dim, &x, &y);
    cout << "\t\t\t\t\t>> x: " << x << " y: " << y << " = " << i+1 << "\n";
    arr[x][y] = i+1;
  }
  return;
}

bool invalidPos(int** arr, int r, int c, int dim) {
  if ((r < 0) || (c < 0) || (r >= dim) || (c >= dim) || 
    (arr[r][c] != 0)) {
      return 1;
    }
  return 0;
}

void spiral2(int** arr, int dim) {
  int dc[4] = {1, 0, -1, 0};
  int dr[4] = {0, 1, 0, -1};
  int dir = 0, m = dim * dim, val = 0;
  int r = 0, c = 0;
  while (val < m) {
    arr[r][c] = 1+val++;
    r += dr[dir];
    c += dc[dir];
    if (invalidPos(arr, r, c, dim)) {
      r -= dr[dir];
      c -= dc[dir];
      dir = (dir+1)%4;
      r += dr[dir];
      c += dc[dir];
    }
  }
}

int main() {
  int dim;
  int **arr;
  cout << "Enter dim: \n";
  cin >> dim;
  arr = new int*[dim];
  for (int k = 0; k < dim; ++k) {
    arr[k] = new int[dim]{0};
  }
  //spiral(arr, dim);
  spiral2(arr, dim);
  for (int i = 0; i < dim; ++i) {
    for (int j = 0; j < dim; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
