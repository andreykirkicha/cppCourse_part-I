#include <cstddef>
#include <cstring>

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();

	String(const String &other) {
        size_t size = other.size;
        this->size = size;
        this->str = new char[size + 1];

        for (int i = 0; i < size; i++) {
            (this->str)[i] = other.str[i];
        }

        (this->str)[size] = '\0';
    }

	void append(const String &other);

	size_t size;
	char *str;
};