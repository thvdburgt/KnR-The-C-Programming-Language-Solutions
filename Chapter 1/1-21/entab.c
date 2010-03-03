/*
 * Filename:    entab.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        27-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 1-21, page 34
 *
 * Write a program entab that replaces strings of blanks with the
 * minimum number of tabs and blanks to achieve the same spacing. Use
 * the same stops as for detab. When either a tab or a single blank
 * would suffice to reach a tab stop, which should be given preference?
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * This program will print a tab if either a tab or a single blank would
 * suffice, except if the single space is between two words.
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0
#define TABWIDTH 4

int main(void)
{
    int i;
    int c, col, blanks, numtabs;

    col = blanks = 0;
    while((c = getchar()) != EOF) {
        if (c == ' ') {
            blanks = blanks + 1;
            col = col + 1;
        } else {
            if (blanks == 1)
                putchar(' ');
            else if (blanks > 1) {
                numtabs = col/TABWIDTH - (col-blanks)/TABWIDTH;
                for (i = 0; i < numtabs; ++i)
                    putchar('\t');
                if (numtabs >= 1)
                    blanks = col - (col/TABWIDTH)*TABWIDTH;
                for (i = 0; i < blanks; ++i)
                    putchar(' ');
            }
            blanks = 0;
            putchar(c);
            col = col + 1;
            if (c == '\n')
                col = 0;
        }
    }
    return EXIT_SUCCESS;
}
