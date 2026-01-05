#include <stdio.h>


#define SPACE ' '

int detab()
{
    return 0;
}


int main()
{
    char c;
    int n, i;
    int pos;    //记录光标位置
    int spaces = 0;


    pos = 0;
    n = 4;


    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            spaces = n - (pos % n);
            for (i = 0;i < spaces;i++)
            {
                printf("%c", SPACE);
            }
            pos = pos + spaces;
        }
        else if (c == '\n')
        {
            printf("%c", c);
            pos = 0;
        }
        else
        {
            printf("%c", c);
            pos++;
        }
        if (pos >= n)
        {
            pos = pos % n;
        }
    }



    return 0;
}
