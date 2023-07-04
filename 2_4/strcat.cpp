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

char *strcat( char *to, const char *from )
{
    if (to == NULL || from == NULL)
        return NULL;

    char *ptr = str_chr(to, '\0');

    while (*from != '\0')
    {
        *ptr = *from;
        ptr++;
        from++;
    }

    *ptr = '\0';

    return to;
}