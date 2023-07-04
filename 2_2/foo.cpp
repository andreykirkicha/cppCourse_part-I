#include <iostream>
using namespace std;

int foo(int n) {
    cout << "." << endl;
    
    if (n <= 0)
        return 1;
    return foo((n * 2) / 3) + foo(n - 2);
}

int main() {
    cout << foo(3) << endl;

    return 0;
}
