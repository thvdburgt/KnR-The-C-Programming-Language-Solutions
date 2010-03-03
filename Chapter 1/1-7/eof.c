/*
 * Filename:    eof.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        25-FEB-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 1-7, page 17
 *
 * Write a program to print the value of EOF.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("%d\n", EOF);
    return EXIT_SUCCESS;
}
