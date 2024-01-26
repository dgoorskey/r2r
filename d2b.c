#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

#define BIN "d2b"
#define VALUE_T unsigned long long
#define VALUE_T_MAX ULLONG_MAX

VALUE_T process (char *literal)
{
    /* make sure all characters are legal */
    long long i; /* size_t cannot be wider than long */
    for (i = 0; i < (long long) strlen (literal); i++)
    {
        char c = literal[i];
        if (c != '_' && !isdigit(c) && c != '\n')
        {
            printf ("%s: illegal character \"%c\" (0x%x) in decimal number\n", BIN, c, c);
            exit (EXIT_FAILURE);
        }
    }

    /* make sure string length is legal */
    if (strlen (literal) > VALUE_T_MAX / 10)
    {
        printf ("%s: decimal number is too long (max digits is %llu)",
                BIN, VALUE_T_MAX / 10);
        exit (EXIT_FAILURE);
    }

    /* calculate actual number */
    VALUE_T value = 0;
    VALUE_T place = 1;
    for (i = (long long) strlen (literal) - 1; i >= 0; i--)
    {
        char c = literal[i];

        if (c == '_' || c == '\n')
            continue;

        if (isdigit(c))
        {
            value += (c - '0') * place;
        }

        place *= 10;
    }

    return value;
}

void print_binary (VALUE_T value)
{
    int i;
    for (i = sizeof (VALUE_T) * 8 - 1; i >= 0; i--)
    {
        int bit = (value >> i) & 1;
        printf ("%d", bit);

        if (i % 8 == 0 && i > 0)
            printf ("_");
    }
}

int main (int argc, char **argv)
{
    if (argc < 2)
    {
        /*
        printf ("Usage: %s [DECIMAL_NUMBER]\n", BIN);
        return EXIT_FAILURE;
        */

        while (1)
        {
            char *line = NULL;
            size_t length = 0;

            errno = 0;
            int r = getline (&line, &length, stdin);

            if (r == -1)
            {
                if (errno != 0)
                {
                    perror (BIN);
                    free (line);
                    exit (EXIT_FAILURE);
                }

                free (line);
                exit (EXIT_SUCCESS);
            }

            VALUE_T v = process (line);
            print_binary (v);
            printf ("\n");

            free (line);
            exit (EXIT_SUCCESS);
        }
    }

    int i;
    for (i = 1; i < argc; i++)
    {
        VALUE_T v = process (argv[i]);
        print_binary (v);
        printf ("\n");
    }

    return EXIT_SUCCESS;
}

