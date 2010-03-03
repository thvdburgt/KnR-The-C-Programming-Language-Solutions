/*
 * Filename:    ftoc.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        27-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 1-15, page 27
 *
 * Rewrite the temperature conversion program of Section 1.2 to use a
 * function for conversion.
 */

#include <stdio.h>
#include <stdlib.h>

float ftoc(float f);

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("  F    C  \n");
    printf("----------\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = ftoc(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return EXIT_SUCCESS;
}

/* ftoc:  return Celsius conversion of a Fahrenheit temperature */
float ftoc(float f)
{
    float c;
    c = (5.0/9.0) * (f-32.0);
    return c;
}
