#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "") {
        this->size = strlen(str);
        this->str = new char[this->size + 1];

        for (int i = 0; i < this->size; i++) {
            (this->str)[i] = str[i];
        }

        (this->str)[this->size] = '\0';
    }

	size_t size;
	char *str;
};