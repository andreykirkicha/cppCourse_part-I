#include <cstddef>
#include <cstring>
#include <iostream>

struct String
{
	String(const char *str = "")
    {
        this->size = strlen(str);
        this->str = new char[this->size + 1];

        for (int i = 0; i < this->size; i++) { (this->str)[i] = str[i]; }

        (this->str)[this->size] = '\0';
    }
	String(size_t number_of_symbols, char sym)
    {
        this->size = number_of_symbols;
        this->str = new char[number_of_symbols + 1];

        for (int i = 0; i < number_of_symbols; i++) { (this->str)[i] = sym; }

        (this->str)[number_of_symbols] = '\0';
    }
	~String() { delete [] str; }

    String(const String &other) 
    {
        size_t size = other.size;
        this->size = size;
        this->str = new char[size + 1];

        for (int i = 0; i < size; i++) { (this->str)[i] = other.str[i]; }

        (this->str)[size] = '\0';
    }
    String &operator=(const String &other)
    {
        if (this != &other) 
        {
            delete [] this->str;
            this->size = other.size;
            size_t size = other.size;
            this->str = new char[size + 1];

            for (int i = 0; i < size; i++) { (this->str)[i] = other.str[i]; }

            (this->str)[size] = '\0';
		}

		return *this;
    }

	void append(String &argument) 
    {
        char *extended_string = new char[this->size + argument.size + 1];
        int i = 0;

        for (i = 0; i < this->size; i++) { extended_string[i] = (this->str)[i]; }

        for (int j = 0; j < argument.size; j++) { extended_string[j + i] = (argument.str)[j]; }

        extended_string[this->size + argument.size] = '\0';
        delete [] this->str;

        this->str = extended_string;
        this->size += argument.size;
    }

    struct Proxy
    {
        Proxy(const char *proxy_str = "")
        {
            this->proxy_size = strlen(proxy_str);
            this->proxy_str = new char[this->proxy_size + 1];
            this->proxy_i = 0;

            for (int i = 0; i < this->proxy_size; i++) { (this->proxy_str)[i] = proxy_str[i]; }

            (this->proxy_str)[this->proxy_size] = '\0';
        }
        ~Proxy() { delete [] proxy_str; }

        String operator[](size_t j) const
        {
            size_t new_len = j - this->proxy_i;
            char *new_str = new char[new_len + 1];

            for (int k = 0; k < new_len; k++) { new_str[k] = (this->proxy_str)[this->proxy_i + k]; }

            new_str[new_len] = '\0';

            String new_string(new_str);

            delete [] new_str;

            return new_string;
        }

        size_t proxy_i;
        size_t proxy_size;
        char *proxy_str;
    };

    Proxy operator[](size_t i) const
    {
        Proxy new_proxy(this->str);
        new_proxy.proxy_i = i;

        return new_proxy;
    }
    
    size_t size;
    char *str;
};

int main()
{
    String const hello("hello");
    String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
    String const ell  = hello[1][4]; // теперь в ell хранится подстрока "ell"

    std::cout << hell.str << std::endl;
    std::cout << ell.str << std::endl;

    return 0;
}