/*
 * Filename:    syscalls.h
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

#define NULL      0
#define EOF       (-1)
#define BUFSIZ    1024
#define OPEN_MAX  20 /* max #files open at once */

typedef struct _iobuf {
    int cnt;          /* characters left */
    char *ptr;        /* next character position */
    char *base;       /* location of buffer */
    int flag;         /* mode of file access */
    int fd;           /* file descriptor */
} FILE;
extern FILE _iob[OPEN_MAX];
#define stdin   (&iob[0])
#define stdout  (&iob[1])
#define stderr  (&iob[2])

enum _flags {
    _READ   = 01,    /* file open for reading */
    _WRITE  = 02,    /* file open for writing */
    _UNBUF  = 04,    /* file is unbuffered */
    _EOF    = 010,   /* EOF has occurred on this file */
    _ERR    = 020    /* error occurred on this file */
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)     (((p)->flag & _EOF) != 0)
#define ferror(p)   (((p)->flag & _ERR) != 0)
#define fileno(p)   ((p)->fd)

#define getc(p)   (--(p)->cnt >= 0 \
               ? (unsigned char) *(p)->ptr++ : _fillbuff(p))
#define putc(p)   (--(p)->cnt >= 0 \
               ? *(p)->ptr++ = (x) : _flushbuf((x), p))

#define getchar()   getc(stdin)
#define putchar(x)  putc(x), stdout)

FILE _iob[OPEN_MAX] = {    /* stdin, stdout, stderr: */
    { 0, (char *) 0, (char *) 0, _READ, 0 },
    { 0, (char *) 0, (char *) 0, _WRITE, 1 },
    { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};
