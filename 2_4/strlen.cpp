#include <stdlib.h>

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

unsigned strlen( const char *str )
{
    if (str == NULL)
        return 0;

    return str_chr(str, '\0') - str;
}