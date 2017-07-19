// Example program
#include <iostream>
#include <string>
using namespace std;
void test_str(const char *s) {
    cout << strlen(s) << s << endl;
}

int main()
{
  std::string name = "Hello world";
  test_str(name.c_str() + 2);
}

