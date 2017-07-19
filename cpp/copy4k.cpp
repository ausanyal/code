#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int copy20B(char * dest, const char* src, int sz = 20) {
  memcpy(dest, src, sz);
  return sz;
}

char* myCopy(const char* src) {
  char *dest;
  int copiedSoFar = 20, sz = strlen(src);
  dest = (char *)calloc(1, copiedSoFar * sizeof(char));
  while (copiedSoFar < sz) {
    if (copiedSoFar + 20 > sz) {
      copiedSoFar += copy20B(dest+copiedSoFar, src + copiedSoFar);
    } else {
      copiedSoFar += copy20B(dest+copiedSoFar, src + copiedSoFar, src-copiedSoFar);
      break;
    }
    dest = (char *)realloc(dest, copiedSoFar);
  }
  return dest;
}

int main()
{
  ifstream file1Stream("/Users/asanyal/Desktop/PolicyDocuments.pdf");
  char a[80];
  string a1, b;
  int count = 0;
  if (!file1Stream) {
    cout << "Error \n";
  } else {
    while(!file1Stream.eof() && count <= 125) {
      file1Stream >> a;
      count ++;
      a1 += a;
    }
    cout << a1 << " " << a1.size() << "\n";
  }
  a1 += '\n';
  char *dest = myCopy(a1.c_str());
  cout << "Dest: " << dest << "\n";
  return 0;
}
