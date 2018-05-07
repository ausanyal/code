#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int parseIpAddrStr(string ip) {
  int ret = 0;
  size_t pos = 0;
  for (int i = 0; i < 4; ++i) {
    if (i == 3) pos = string::npos;
    else pos = ip.find('.');
    string oct = ip.substr(0, pos);
    ret = ret<<8 | atoi(oct.c_str());
    ip.erase(0, pos+1);
  }
  return ret;
}

int main() {
  string ip;
  cout << "Enter ip: ";
  cin >> ip;
  cout << "0x" << hex << parseIpAddrStr(ip) << "\n";;
  return 0;
}
