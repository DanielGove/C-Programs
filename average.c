// Only this line of comment is provided
#include <stdio.h>

void main(void)
{
    double x, average, total = 0;
    int count = 0;

    while (scanf("%lf", &x) == 1)
    {
        total += x;
        average = total / (float)(++count);

        printf("Total=%f Average=%f\n", total, average);
    }
}