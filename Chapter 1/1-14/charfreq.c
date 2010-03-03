/*
 * Filename:    charfreq.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        27-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 1-14, page 24
 *
 * Write a program to print a histogram of the frequencies of different
 * characters in its input.
 */

#include <stdio.h>
#include <stdlib.h>

#define NUMCHARS 128 /* number of characters in ASCII-I */

int main(void)
{
    int c, chars[NUMCHARS];

    for (c = 0; c < NUMCHARS; ++c)
        chars[c] = 0;

    while ((c = getchar()) != EOF)
        chars[c] += 1;

    /* horizontal histogram */
    for (c = 0; c < NUMCHARS; ++c) {
        if (chars[c] > 0) {
            if (c == '\b')          /* backspace */
                printf("\\b");
            else if (c == '\n')     /* new line*/
                printf("\\n");
            else if (c == '\t')     /* (horizontal) tab */
                printf("\\t)");
            else                    /* all other chars */
                printf("%2c", c);
            /* ASCII code & frequency */
            printf(" (%3d): %3d\n", c, chars[c]);
        }
    }
    return EXIT_SUCCESS;
}
