#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIN "b2d"
#define VALUE_T unsigned long long

VALUE_T process (char *literal)
{
    /* make sure all characters are legal */
    long long i; /* size_t cannot be wider than long */
    for (i = 0; i < (long long) strlen (literal); i++)
    {
        char c = literal[i];
        if (c != '_' && c != '0' && c != '1')
        {
            printf ("%s: illegal character \"%c\" (0x%x) in binary number\n", BIN, c, c);
            exit (EXIT_FAILURE);
        }
    }

    /* make sure string length is legal */
    if (strlen (literal) > sizeof (VALUE_T) * 8)
    {
        printf ("%s: binary number is too long (max bits is %lu)",
                BIN, sizeof (VALUE_T) * 8);
        exit (EXIT_FAILURE);
    }

    /* calculate actual number */
    VALUE_T value = 0;
    VALUE_T place = 1;
    for (i = (long long) strlen (literal) - 1; i >= 0; i--)
    {
        if (literal[i] == '_')
            continue;

        if (literal[i] == '1')
            value += place;

        place *= 2;
    }

    return value;
}

int main (int argc, char **argv)
{
    if (argc < 2)
    {
        printf ("Usage: %s [BINARY_NUMBER]\n", BIN);
        return EXIT_FAILURE;
    }

    int i;
    for (i = 1; i < argc; i++)
    {
        VALUE_T v = process (argv[i]);
        printf ("%llu\n", v);
    }

    return EXIT_SUCCESS;
}

