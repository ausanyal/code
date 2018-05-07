#include <iostream>
#include <string>

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

unsigned int parseIp2(string ip) {
  unsigned int ret_ip;
  string oct;
  for (int i = 0; i < ip.size(); ++i) {
    char c = ip[i];
    cout << "i: " << i << " c " << c << "\n";
    if (c == '.' || i == ip.size()-1) {
      if (i == ip.size()-1) oct+=c;
      ret_ip = ret_ip << 8 | stoi(oct);
      oct.clear();
    } else {
      oct += c;
    }
  }
  return ret_ip;
}

int main()
{
  //cout << parseIp("255.255.255.255");
  cout << hex << parseIp2("1.2.3.4") << "\n";
  return 0;
}
