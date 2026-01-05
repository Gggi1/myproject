#include <stdio.h>
#include <string.h>

#define LIM 20
#define SIZE 81

char *s_gets(char *st, int n);
void ststr(char *strings[], int num);

int main()
{
    char input[LIM][SIZE];
    int ct = 0;
    char *trstr[LIM];
    int i;

    printf("Input no more than 20 sentences, and the program will sort them alphabetically.\n");
    while (ct < LIM && s_gets(input[ct], SIZE) && input[ct][0] != '\0')
    {
        trstr[ct] = input[ct];
        ct++;
    }
    ststr(trstr, ct);
    printf("The sorted sentences are as follows:\n");
    for (i = 0;i < ct;i++)
    {
        printf("%s\n", trstr[i]);
    }

    return 0;
}

void ststr(char *strings[], int num)
{
    int top, seek;
    char *temp;

    for (top = 0;top < num - 1;top++)
    {
        for (seek = top + 1;seek < num;seek++)
        {
            if (strcmp(strings[top], strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }
}

char *s_gets(char *st, int n)
{
    char *ret;
    int i = 0;

    ret = fgets(st, n, stdin);
    if (ret)
    {
        while ('\n' != st[i] && '\0' != st[i])
        {
            i++;
        }
        if ('\n' == st[i])
        {
            st[i] = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }

    return ret;
}












