#include <iostream>
#include <stdlib.h>

using namespace std;

char *str_chr( const char *str, unsigned sym )
{
    if (str == NULL)
        return NULL;

    char *ptr = (char *)str;

    while (*ptr != sym && *ptr != '\0')
        ptr++;

    if (*ptr != sym)
        return NULL;

    return ptr;
}

unsigned str_len( const char *str )
{
    if (str == NULL)
        return 0;

    return str_chr(str, '\0') - str;
}

int str_str(const char *text, const char *pattern)
{
    const char *text_variable = text;

    unsigned pattern_len = str_len(pattern);
    if (pattern_len == 0) {
        return 0;
    }

    while (char *start_sym = str_chr(text_variable, pattern[0])) {
        int i = 0;
        while (i < pattern_len) {
            if (start_sym[i] != pattern[i]) {
                break;
            }
            i++;
        }

        if (i == pattern_len) {
            return start_sym - text;
        }
            
        text_variable = start_sym + 1;
    }

    return -1;
}

int main() {
    const char *text = "Cocooucaocal";
    const char *pattern = "ouc";

    cout << str_str(text, pattern) << endl;

    return 0;
}