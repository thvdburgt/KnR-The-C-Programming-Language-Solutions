/*
 * Answer to Exercise 2-9, page 51
 *
 * In a two's complement number system, x &= (x-1) deletes the rightmost
 * 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount . 
 */

#include <stdio.h>

int bitcount(unsigned x);

main()
{
    printf("%d\n", bitcount(0777));

    return 0;
}

/* bitcount:  count 1 bits in x */
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;
}

