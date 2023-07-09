#include <algorithm> 
#include <cstddef>   
#include <cstring>   

using namespace std;

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	String(const String &other);
	~String();

	String &operator=(const String &other) {
        if (this != &other) {
			delete [] this->str;
			this->size = other.size;
			size_t size = other.size;
			this->str = new char[size + 1];

			for (int i = 0; i < size; i++) {
				(this->str)[i] = other.str[i];
			}

			(this->str)[size] = '\0';
		}

		return *this;
    }

	void append(const String &other);

	size_t size;
	char *str;
};