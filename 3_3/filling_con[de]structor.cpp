#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(size_t number_of_symbols, char sym) {
        this->size = number_of_symbols;
        this->str = new char[number_of_symbols + 1];

        for (int i = 0; i < number_of_symbols; i++) {
            (this->str)[i] = sym;
        }

        (this->str)[number_of_symbols] = '\0';
    }

    ~String() {
        delete [] str;
    }

	size_t size;
	char *str;
};