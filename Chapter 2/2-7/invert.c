/*
 * Filename:    invert.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        23-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 2-7, page 49
 *
 * Write a function invert(x,p,n) that returns x with the n bits that
 * begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged. 
 */

#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
    printf("%u\n", invert(240, 4, 3));
    return EXIT_SUCCESS;
}

/* invert:  returns x with n bits that begin at position p inverted */
unsigned invert(unsigned x, int p, int n)
{
    int mask;
    /* Mask with leftmost n bits of p set */
    mask = (~(~0U << n)) << (p-n+1);
    return mask ^ x;
}
