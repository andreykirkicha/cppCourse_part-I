#include <iostream>

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

char *getline() {
    char sym;
    unsigned size = 10, i = 0;
    char *buffer = new char[size], *result_string = buffer;

    while (cin.get(sym) && sym != '\n') {
        *buffer = sym;
        buffer++;
        i++;

        if (i >= size) {
            result_string = resize(result_string, size, 2 * size);
            buffer = result_string + size;
            size += size;
        }
    }

    return result_string;
}

int main() {
    char *str = getline();

    cout << str << endl;
    
    return 0;
}