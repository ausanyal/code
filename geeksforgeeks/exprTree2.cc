#include <iostream>

using namespace std;

void constructTree(char postfix[]) {
  cout << "\n" << postfix << "\n";
}

int main()
{
  char postfix[] = "ab+ef*g*-";
  constructTree(postfix);

  return 0;
}
