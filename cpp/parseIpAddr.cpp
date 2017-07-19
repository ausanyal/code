#include <iostream>

using namespace std;

string parseIp(string ip) {
  unsigned int oct[4], ipInt = 0;
  int octCount = 0;
  memset(oct, 0, sizeof(oct));
  for (char s: ip) {
    if (s == '.') {
      if (oct[octCount] > 255) {
        cout << "Error 1 \n";
        return string();
      }
      octCount++;
    } else {
      oct[octCount] = (oct[octCount] * 10) + (s  - '0');
    }
  }
  if (octCount != 3) {
    cout << "Error 2\n";
    return string();
  }
  for (int i = 0; i < 4; ++i) {
    ipInt |= oct[i] << ((3-i)*8);
    cout << hex << ipInt << "\n";
  }
  return "";
}

int main()
{
  cout << parseIp("255.255.255.255");
  return 0;
}
