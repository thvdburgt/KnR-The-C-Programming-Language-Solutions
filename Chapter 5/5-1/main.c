/*
 * Filename:    main.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        01-MAR-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 5-1, page 97
 *
 * As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fix it to push such a character back on the
 * input.
 */

#include <stdio.h>
#include <stdlib.h>
#include "getint.h"

/* sample implementation of getint */
int main(void)
{
    int i, r;

    r = getint(&i);
    if (r > 0)
        printf("%d\n", i);
    else if (r == 0)
        printf("not a number\n");
    else if (r == EOF)
        printf("end of file\n");
    else
        printf("wtf happend?\n");
    return EXIT_SUCCESS;
}
