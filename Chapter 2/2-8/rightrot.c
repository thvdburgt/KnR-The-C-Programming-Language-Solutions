/*
 * Filename:    rightrot.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        23-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 2-8, page 49
 *
 * Write a function rightrot(x,n) that returns the value of the integer
 * x rotated to the right by n bit positions.
 */

#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(unsigned x, unsigned n);

int main(void)
{
    printf("%u\n", rightrot(3, 1));
    return EXIT_SUCCESS+;
}

/*rightrot:  rotates x to the right by n bit positions */
unsigned rightrot(unsigned x, unsigned n)
{
    while (n > 0) {
        if(x & 1)   /* rightmost bit of x is 1 */
            x = (x >> 1) | ~(~0U >> 1);
        else        /* rightmost bit of x is 0 */
            x = x >> 1;
        --n;
    }
    return x;
}

