#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BIN "h2d"
#define VALUE_T unsigned long long

VALUE_T process (char *literal)
{
    /* make sure all characters are legal */
    long long i; /* size_t cannot be wider than long */
    for (i = 0; i < (long long) strlen (literal); i++)
    {
        char c = literal[i];
        if (c != '_' && !isxdigit(c))
        {
            printf ("%s: illegal character \"%c\" (0x%x) in hexadecimal number\n", BIN, c, c);
            exit (EXIT_FAILURE);
        }

    }

    /* make sure string length is legal */
    if (strlen (literal) > sizeof (VALUE_T) * 2)
    {
        printf ("%s: binary number is too long (max digits is %lu)",
                BIN, sizeof (VALUE_T) * 2);
        exit (EXIT_FAILURE);
    }

    /* calculate actual number */
    VALUE_T value = 0;
    VALUE_T place = 1;
    for (i = (long long) strlen (literal) - 1; i >= 0; i--)
    {
        char c = literal[i];

        if (c == '_')
            continue;

        switch (c)
        {
            case '0':
                break;
            case '1':
                value += 1 * place;
                break;
            case '2':
                value += 2 * place;
                break;
            case '3':
                value += 3 * place;
                break;
            case '4':
                value += 4 * place;
                break;
            case '5':
                value += 5 * place;
                break;
            case '6':
                value += 6 * place;
                break;
            case '7':
                value += 7 * place;
                break;
            case '8':
                value += 8 * place;
                break;
            case '9':
                value += 9 * place;
                break;
            case 'a':
            case 'A':
                value += 10 * place;
                break;
            case 'b':
            case 'B':
                value += 11 * place;
                break;
            case 'c':
            case 'C':
                value += 12 * place;
                break;
            case 'd':
            case 'D':
                value += 13 * place;
                break;
            case 'e':
            case 'E':
                value += 14 * place;
                break;
            case 'f':
            case 'F':
                value += 15 * place;
                break;
        }

        place *= 16;
    }

    return value;
}

int main (int argc, char **argv)
{
    if (argc < 2)
    {
        printf ("Usage: %s [HEXADECIMAL_NUMBER]\n", BIN);
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

