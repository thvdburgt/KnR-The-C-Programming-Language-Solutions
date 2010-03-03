/*
 * Filename:    copy.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        25-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 1-9, page 20
 *
 * Write a program to copy its input to its output, replacing each string
 * of one or more blanks by a sinle blank.
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int main(void)
{
    int c, prevblank;

    prevblank = FALSE;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (prevblank == FALSE) {
                putchar(c);
                prevblank = TRUE;
            }
        }
        if (c != ' ') {
            putchar(c);
            prevblank = FALSE;
        }
    }
    return EXIT_SUCCESS;
}
