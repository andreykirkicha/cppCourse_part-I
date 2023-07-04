#include <iostream>
using namespace std;

int main()
{
    int flag = 0;

    char c = '\0';
    while (cin.get(c)) {
        if (c == ' ' && flag == 1) {
            continue;
        }
        else if (c == ' ' && flag == 0) {
            flag = 1;
        }
        else {
            flag = 0;
        }

        cout << c;
    }

	return 0;
}