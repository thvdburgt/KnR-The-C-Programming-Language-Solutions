/*
 * Filename:    itoa.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        04-MAR-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 5-6, page 107
 *
 * Rewrite appropriate programs from earlier chapters and exercises with
 * pointers instead of array indexing. Good possibilities include
 * getline (Chapters 1 and 4), atoi, itoa, and their variants
 * (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
 * (Chapter 4). 
 */

/* strindex:  return index of t in s, -1 if none */
int strindex(const char *s, const char *t)
{
    const char *i, *j, *k;

    for (i = s; *i != '\0'; i++) {      /* for each character in s */
        j = i, k = t;
        while(*k != '\0' && *j++ == *k++);
        if (k-t > 0 && *k == '\0')      /* if it is the start of t */
            return i-s;                 /* return its index */
    }
    return -1;                          /* t was not found return -1 */
}
