#include <stdio.h>
#include <math.h>


int main()
{
    int a, b, c;
    float d, x1, x2;
    char ch;

    do
    {
        printf("Please enter the 3 coefficients of the quadratic equation with one variable:\n");
        scanf("%d %d %d", &a, &b, &c);
        printf("The input quadratic equation with one variable is (%d)x^2 + (%d)x + %d = 0.\n", a, b, c);

        d = b * b - 4 * a * c;
        if (d > 0)
        {
            x1 = (- b + sqrt(d)) / (2 * a);
            x2 = (- b - sqrt(d)) / (2 * a);
            printf("There are two solutions to this equation: x1 = %f, x2 = %f.\n", x1, x2);
        }
        else if (d == 0)
        {
            x1 = (- b) / (2 * a);
            x2 = (- b) / (2 * a);
            printf("There is a unique solution to this equation: x1 = x2 = %f.\n", x1);
        }
        else
        {
            printf("There is no solution to this equation.\n");
        }
        printf("Whether to continue:(Y/N)\n");
        scanf(" %c", &ch);
    }
    while('Y' == ch || 'y' == ch);



    return 0;
}
