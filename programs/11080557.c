#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INISIZE 10

int reverse(char **s)
{
    char *re_line;
    int len;
    int i;


    if (*s == NULL)
    {
        fprintf(stderr, "Line is NULL!");
        return 1;
    }
    len = strlen(*s);
    re_line = malloc(sizeof(char) * (len + 1));
    if (re_line == NULL)
    {
        fprintf(stderr, "Memory allocation failed!");
        return 1;
    }
    for (i = 0;i < len;i++)
    {
        re_line[i] = (*s)[len - i - 1];
    }
    re_line[len] = '\0';

    free(*s);
    *s = re_line;

    return 0;
}

int main()
{
    char *line;
    size_t bufsize;
    ssize_t len;
    int i;


    bufsize = INISIZE;

    line = (char *)malloc(bufsize * sizeof(line));
    if (NULL == line)
    {
        fprintf(stderr, "Memory allocation failed!");
        return 1;
    }
    printf("Enter text(Ctrl + D to end):\n");
    while ((len = getline(&line, &bufsize, stdin)) != -1)
    {
        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
            len--;
        }
        if (reverse(&line))
        {
            fprintf(stderr, "Reverse line failed!");
            return 1;
        }
        printf("颠倒后行:%s\n", line);
    }


    free(line);

    return 0;
}












