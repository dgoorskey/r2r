#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>

#define BASE_BIN 0
#define BASE_DEC 1
#define BASE_OCT 2
#define BASE_HEX 3

/* set to one of the base constants when building */
#ifndef IBASE
#error "IBASE not defined"
#endif

/* set to one of the base constants when building */
#ifndef OBASE
#error "OBASE not defined"
#endif

/* set to a string literal of the binary's name when building */
#ifndef BIN
#error "BIN not defined"
#endif

#define VALUE_T unsigned long long

void print_bin (VALUE_T value)
{
    int i;
    int l = 0;

    if (value == 0)
    {
        printf ("0");
        return;
    }

    for (i = sizeof (value) * 8 - 1; i >= 0; i--)
    {
        int bit = (value >> i) & 1;
        if (bit)
            l = 1;

        /* skip leading zeroes */
        if (!l)
            continue;

        printf ("%d", bit);
    }
}

void print_dec (VALUE_T value)
{
    printf ("%llu", value);
}

void print_oct (VALUE_T value)
{
    printf ("%llo", value);
}

void print_hex (VALUE_T value)
{
    printf ("%llX", value);
}

VALUE_T parse_bin (char *str)
{
    long long i;
    char c;
    unsigned int digits = 0;
    VALUE_T value = 0;
    VALUE_T place = 1;

    /* check input */
    for (i = 0; i < (long long) strlen (str); i++)
    {
        c = str[i];
        if (c != '0' && c != '1' && c != '_' && c != '\n')
        {
            fprintf (stderr, BIN ": invalid binary digit \"%c\" (0x%X)\n", c, c);
            exit (EXIT_FAILURE);
        }

        if (c == '0' || c == '1')
            digits++;
    }
    if (digits > sizeof (VALUE_T) * 8)
    {
        errno = ERANGE;
        perror (BIN);
        exit (EXIT_FAILURE);
    }

    for (i = strlen (str) - 1; i >= 0; i--)
    {
        c = str[i];
        if (c == '0' || c == '1')
        {
            value += (c - '0') * place;
            place *= 2; /* will overflow on last digit but idc */
        }
    }

    return value;
}

VALUE_T parse_dec (char *str)
{
    VALUE_T result;
    char c;
    int i;

    /* check input */
    for (i = 0; i < (long long) strlen (str); i++)
    {
        c = str[i];
        if (!isdigit (c) && c != '_' && c != '\n')
        {
            fprintf (stderr, BIN ": invalid decimal digit \"%c\" (0x%X)\n", c, c);
            exit (EXIT_FAILURE);
        }
    }

    errno = 0;
    sscanf (str, "%llu", &result);
    if (errno != 0)
    {
        perror (BIN);
        exit (EXIT_FAILURE);
    }

    return result;
}

VALUE_T parse_oct (char *str)
{
    VALUE_T result;
    char c;
    int i;

    /* check input */
    for (i = 0; i < (long long) strlen (str); i++)
    {
        c = str[i];
        if (!(c >= '0' && c <= '7') && c != '_' && c != '\n')
        {
            fprintf (stderr, BIN ": invalid hex digit \"%c\" (0x%X)\n", c, c);
            exit (EXIT_FAILURE);
        }
    }

    errno = 0;
    sscanf (str, "%llo", &result);
    if (errno != 0)
    {
        perror (BIN);
        exit (EXIT_FAILURE);
    }

    return result;
}

VALUE_T parse_hex (char *str)
{
    VALUE_T result;
    char c;
    int i;

    /* check input */
    for (i = 0; i < (long long) strlen (str); i++)
    {
        c = str[i];
        if (!isxdigit (c) && c != '_' && c != '\n')
        {
            fprintf (stderr, BIN ": invalid hex digit \"%c\" (0x%X)\n", c, c);
            exit (EXIT_FAILURE);
        }
    }

    errno = 0;
    sscanf (str, "%llx", &result);
    if (errno != 0)
    {
        perror (BIN);
        exit (EXIT_FAILURE);
    }

    return result;
}

void r2r (char *str)
{
    VALUE_T v;

#if IBASE == BASE_BIN
    v = parse_bin (str);
#elif IBASE == BASE_DEC
    v = parse_dec (str);
#elif IBASE == BASE_OCT
    v = parse_oct (str);
#elif IBASE == BASE_HEX
    v = parse_hex (str);
#else
#error
#endif

#if OBASE == BASE_BIN
    print_bin (v);
#elif OBASE == BASE_DEC
    print_dec (v);
#elif OBASE == BASE_OCT
    print_oct (v);
#elif OBASE == BASE_HEX
    print_hex (v);
#else
#error
#endif

    printf ("\n");
}

int main (int argc, char **argv)
{
    /* read from argv */
    int i;
    for (i = 1; i < argc; i++)
        r2r (argv [i]);

    if (argc > 1)
        exit (EXIT_SUCCESS);

    /* read from stdin */
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

        r2r (line);

        free (line);
    }

    exit (EXIT_SUCCESS);
}

