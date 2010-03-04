/*
 * Filename:    strncat.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        04-MAR-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 5-5, page 107
 *
 * Write versions of the library functions strncpy, strncat and strncmp,
 * which operate on at most the first n characters of their argument
 * strings. For example, strncpy(s,t,n) copies at most n characters of
 * t to s. Full descriptions are in Appendix B.
 */

/* strcat:  concatenate at most n characters of t to the end of s; s
            must be big enough */
void strcat(char *s, const char *t, int n)
{
    while (*s)              /* find end of s */
        s++;
    while (*t && n-- > 0)   /* copy at most n characters of t */
        *s++ = *t++;
    *s = '\0';
}
