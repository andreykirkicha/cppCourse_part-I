#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a = 0, b = 0, c = 0, D = 0, x_1 = 0, x_2 = 0;
    cin >> a >> b >> c;

    D = b * b - 4 * a * c;

    if (D < 0) {
        cout << "No real roots" << endl;
        return 0;
    }

    x_1 = (-b + sqrt(D))/(2*a);
    x_2 = (-b - sqrt(D))/(2*a);

    cout << x_1 << " " << x_2 << endl;

    return 0;
}
