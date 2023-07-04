#include <iostream>
using namespace std;

unsigned gcd(unsigned a, unsigned b) {
    unsigned tmp = a;
    a = (tmp > b ? tmp : b);
    b = (tmp > b ? b : tmp);

    if (b == 0) {
        return a;
    }

    else {
        a = a % b;
    }

    return gcd(a, b);
}

int main() {
    unsigned a = 13, b = 12;

    cout << gcd(a, b) << endl;

    return 0;
}
