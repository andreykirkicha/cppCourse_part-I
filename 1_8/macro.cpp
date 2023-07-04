#include <iostream>

#define MAX(x, y, r) {int old_x = (x), old_y = (y); r = (old_x > old_y ? old_x : old_y);}

int main() {
    int a = 10, b = 20, c = 0;
    
    MAX(a, b, c)
    std::cout << c << std::endl;

    MAX(a += b, b, c)
    std::cout << a << std::endl;
    std::cout << c << std::endl;

    return 0;
}
