#include <stdio.h>
#include <stdlib.h>
int my_fgets(char *str, int num, FILE *stream);
int my_puts(char *str, FILE *stream);

int my_fgets(char *str, int num, FILE *stream)
{
    int ch, i;
    for (i = 0; i < num; i++)
    {
        ch = getc(stream);
        if (feof(stream))
            return EOF;
        else if (ferror(stream))
            return EOF;
        if (ch == '\n')
            break;
        str[i] = ch;
    }
    str[i] = '\0';
    return i;
}

int my_puts(char *str, FILE *stream)
{
    int i = 0;
    while (str[i] != '\0')
    {
        putc(str[i], stream);
        if (ferror(stream))
            return EOF;
        else if (feof(stream))
            return EOF;
        i++;
    }
    putc('\n', stream);
    return i;
}
char a[40];
my_fgets(a, 39, stdin);
