#include <iostream>
using namespace std;

int log_2(int a) {
    int p = 0;
    int test_point = 1;

    while (test_point <= a) {
        test_point *= 2;
        p++;
    }

    return p - 1;
}

int main() {
    int T = 0;
    int a = 0;

    cin >> T;
    while (T-- > 0) {
        cin >> a;
        cout << log_2(a) << endl;
    }

    return 0;
}
