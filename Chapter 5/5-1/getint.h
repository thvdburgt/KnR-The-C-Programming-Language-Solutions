/*
 * Filename:    getint.h
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        01-MAR-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 5-1, page 97
 *
 * As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fix it to push such a character back on the
 * input.
 */

int getint(int *pn);
