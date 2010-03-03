/*
 * Answer to Exercise 2-7, page 49
 *
 * Write a function invert(x,p,n) that returns x with the n bits that
 * begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged. 
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
    printf("%u\n", invert(240, 4, 3));
    return 0;
}

/* invert:  */
unsigned invert(unsigned x, int p, int n)
{
    int mask;
    /* Mask with leftmost n bits of p set XOR x. */
    return ~(~0U << n) << p ^ x;
}

