/*
 * Filename:    wordlength.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        25-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 1-13, page 24
 *
 * Write a program to print a histogram of the lengths of words in it's
 * input. It is easy to draw a histogram with the bars horizontal; a
 * vertical orientation is more challenging.
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * I created both a horizontal and a vertical histogram.
 */

#include <stdio.h>
#include <stdlib.h>

#define IN  1    /* inside a word */
#define OUT 0    /* inside a word */
#define MAXWORDLEN 15

int main(void)
{
    int i, j;
    int c, wl, state, maxval;
    int length[MAXWORDLEN+1];

    for (i = 0; i <= MAXWORDLEN; ++i)
        length[i] = 0;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                if (wl <= MAXWORDLEN)
                    length[wl-1] += 1;
                else
                    length[MAXWORDLEN] += 1;
                state = OUT;
            }
        } else {
            if (state == OUT) {
                wl = 0;
                state = IN;
            }
            wl +=1;
        }
    }

    /* Horizontal histogram */

    printf("Horizontal histogram\n\n");

    for (i = 0; i <= MAXWORDLEN; ++i) {
        if (i != MAXWORDLEN)
            printf(" %2d: ", i+1);
        else
            printf(">%d: ", MAXWORDLEN);

        for (j = 0; j < length[i]; ++j)
            putchar('#');
        putchar('\n');
    }

    /* Vertical histogram */

    printf("\nVertical histogram\n\n");

    /* get maximum wordlength count */
    maxval = 0;
    for (i = 0; i <= MAXWORDLEN; ++i)
        if (length[i] > maxval)
            maxval = length[i];

    /* print a line per count result */
    for (i = 0; i < maxval; ++i) {
        printf(" %2d |", maxval - i);
        for (j = 0; j <= MAXWORDLEN; ++j) {
            if (length[j] >= maxval - i)
                printf("  #");
            else
                printf("   ");
        }
        printf("\n");
    }

    /* print bottom line */
    printf("     ");
    for (i = 0; i <= MAXWORDLEN; ++i)
        printf("---");
    printf("-\n");

    /* print the word lengths */
    printf("     ");
    for (i = 0; i <= MAXWORDLEN; ++i)
        if (i != MAXWORDLEN)
            printf(" %2d", i+1);
        else
            printf(" %2d>", i);
    printf("\n");

    return EXIT_SUCCESS;
}
