/*
 * Filename:    eof.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        25-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 1-6, page 17
 *
 * Verify that the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter a char\n");
    printf("getchar() != EOF : %d\n", getchar() != EOF);
    return EXIT_SUCCESS;
}
