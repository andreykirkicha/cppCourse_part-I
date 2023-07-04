#include <iostream>
using namespace std;

void get_number() {
    int num = 0;

    cin >> num;

    if (num != 0) {
        get_number();
        cout << num << ' ';
    }
}

int main() {
    get_number();
    return 0;
}
