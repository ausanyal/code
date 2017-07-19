#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

struct D {
  int t;
};

template <class T> class A {
public:
  A(string f) : filename(f) { cout << "\n\nA called " << endl; }
  virtual void parseProto() { cout << "In A's parseProto\n"; }
  void doEmit() {
    parseProto();
    T proto;
    cout << "In A's doEmit\n";
    cout << "type : " << typeid(proto).name() << "\n";
  }

private:
  string filename;
};

class B : public A<D> {
public:
  B(string f) : A(f) { cout << "B called \n"; }
  void parseProto() override { cout << "In B's parse proto \n"; }
};

class C : public A<char> {
public:
  C(string f) : A(f) { cout << "C called \n"; }
  void parseProto() override { cout << "In C's parse proto \n"; }
};

int main() {
  const string f = "testfile";
  B b(f);
  // b.parseProto();
  b.doEmit();

  C c(f);
  // c.parseProto();
  c.doEmit();

  return 0;
}
