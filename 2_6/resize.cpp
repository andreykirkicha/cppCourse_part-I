#include <iostream>
#include <cstdlib>

using namespace std;

void str_cpy(char *dest, const char *src, unsigned src_size, unsigned dest_size) {
    unsigned i = 0;

    if (dest == NULL or src == NULL)
        return;

    do {
        *dest++ = *src++;
        i++;
    } while (i < src_size && i < dest_size);
}

char *resize(const char *str, unsigned size, unsigned new_size) {
    char *new_str;

    new_str = new char[new_size];
    str_cpy(new_str, str, size, new_size);
    
    delete [] str;
    return new_str;
}

int main() {
    int i = 0;
    char *str;
    char *new_str;

    str = new char[8];
    str[0] = 'c';
    str[1] = 'h';
    str[2] = 'a';
    str[3] = 'r';

    for (i = 4; i < 8; i++) {
        str[i] = '0';
    }

    for (i = 0; i < 8; i++) {
        cout << str[i] << " ";
    }

    cout << endl;

    new_str = resize(str, 8, 6);

    for (i = 0; i < 10; i++) {
        cout << new_str[i] << "_";
    }

    cout << endl;

    return 0;
}