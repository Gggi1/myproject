#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INISIZE 10


int main()
{
    int *line;



    line = (int *)malloc(sizeof(int) * 10);
    if (NULL == line)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }





    free(line);
    printf("%d\n", *line);

    return 0;
}












