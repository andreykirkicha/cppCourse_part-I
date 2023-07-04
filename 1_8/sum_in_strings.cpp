#include <iostream>
using namespace std;

int main()
{
    int T = 0, a = 0, b = 0;

    cin >> T;
    while (T-- != 0) {
        cin >> a >> b;
        cout << (a + b) << endl;
    }

    return 0;
}
