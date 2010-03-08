/*
 * Filename:    strrindex.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        08-MAR-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 4-1, page 71
 *
 * Write the function strrindex(s,t), which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none. 
 */

/* strrindex:  return index of rightmost t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k, rindex;
    
    rindex = -1;
    for (i = 0; s[i] != '\0'; i++) {
        /* check if t starts at this index in s */
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if (k > 0 && t[k] == '\0')  /* if it does ...*/
            rindex = i;             /* replace rindex with our find */
    }
    return rindex;
}
