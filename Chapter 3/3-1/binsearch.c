/*
 * Filename:    binsearch.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        24-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 3-1, page 58
 *
 * Our binary search makes two tests inside the loop, when one would
 * suffice (at the price of more tests outside). Write a version with
 * only one test inside the loop and measure the difference in run-time.
 */

#include <stdio.h>
#include <stdlib.h>

/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n-1;
    while(low < high) {
        mid = (low + high) / 2;
        if(x <= v[mid])
            high = mid;
        else 
            low = mid+1;
    }
    return (x == v[low]) ? low : -1;
}

int main(void)
{
    int v[5] = {3, 6, 9, 12, 4};
    int x = 36;
    printf("%d\n", binsearch(x, v, 5));
    return EXIT_SUCCESS;
}
