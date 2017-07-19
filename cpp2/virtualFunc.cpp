//
//  virtualFunc.cpp
//  

#include <iostream>
using namespace std;

class testBase {
public:
    virtual void vFunc() {
        cout << "Base Class \n";
    }
};

class testDerived1 : public testBase {
public:
    virtual void vFunc() {
        cout << "Derived 1 \n";
    }
};

class testDerived2 : public testBase {
public:
    virtual void vFunc() {
        cout << "Derived 2 \n";
    }
};

void testVirtual(testBase *b1, testBase *b2) {
    b1->vFunc();
    b2->vFunc();
}

int main()
{
    testDerived1 *d1 = new testDerived1;
    testDerived2 *d2 = new testDerived2;
    //testVirtual(d1, d2);
    testBase b0 = testBase();
    testBase b1 = testDerived1();
    testBase b2 = testDerived2();
    b0.vFunc();
    b1.vFunc();
    b2.vFunc();

    testBase *b3 = new testDerived1;
    testBase *b4 = new testDerived2;
    b3->vFunc();
    b4->vFunc();
    delete(b3);
    delete(b4);

    b3 = d1;
    b4 = d2;
    b3->vFunc();
    b4->vFunc();
    
    delete(d1);
    delete(d2);
    
    return 0;
}
