#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

using namespace std;

struct String {
    String(const char *str = "") {
        this->size = strlen(str);
        this->str = new char[this->size + 1];

        for (int i = 0; i < this->size; i++) {
            (this->str)[i] = str[i];
        }

        (this->str)[this->size] = '\0';
    }
    ~String() {
        delete [] str;
    }

    void append(String &argument) {
        char *extended_string = new char[this->size + argument.size + 1];
        int i = 0;

        for (i = 0; i < this->size; i++) {
            extended_string[i] = (this->str)[i];
        }

        for (int j = 0; j < argument.size; j++) {
            extended_string[j + i] = (argument.str)[j];
        }

        extended_string[this->size + argument.size] = '\0';
        delete [] this->str;

        this->str = extended_string;
        this->size += argument.size;
    }

	size_t size;
	char *str;
};

int main() {
    String s("Hello");
    s.append(s); // теперь s хранит "HelloHello"

    for (int i = 0; i < s.size; i++) {
        cout << (s.str)[i];
    }

    cout << endl;

    return 0;
}