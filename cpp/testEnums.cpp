#include <iostream>

using namespace std;

enum abc {
    ONE = 1,
    TWO = 2,
    BOTH = ONE|TWO
};

void testEnum(abc en) {
    if (en | ONE) cout << "ONE \n";
    if (en | TWO) cout << "TWO \n";
}

int main()
{
    abc a = ONE;
    abc b = TWO;
    abc c = BOTH;
    //cout << a << " " << b << " " << c << "\n";
    testEnum(ONE);
    return 0;
}
