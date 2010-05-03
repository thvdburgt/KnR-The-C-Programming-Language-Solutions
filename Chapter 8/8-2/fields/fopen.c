/*
 * Filename:    fopen.c
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>
 * Date:        03-MAY-2010
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 8-2, page 178
 *
 * Rewrite fopen and _fillbuf with fields instead of explicit bit operations.
 * Compare code size and execution speed.
 */

#include <fcntl.h>
#include "syscalls.h"
#define PERMS 0666   /* RW for owner, group, others*/

/* fopen:  open file, return file ptr */
FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;
    
    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if (fp->flags.read == 0 || fp->flags.write == 0)
            break;        /* found free slot */
    if (fp >= _iob + OPEN_MAX)    /* no free slots */
        return NULL;
    
    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, O_RDONLY, 0);
    if (fd == -1)         /* couldn't access name */
        return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    if (*mode == 'r')
        fp->flags.read = 1;
    else
        fp->flags.write = 1;
    return fp;
}

int main(void)
{
    FILE *fp;
    char mode;
    mode = 'w';
    fp = fopen("foo", &mode);
    return 0;
}
