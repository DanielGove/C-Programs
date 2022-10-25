#include <stdio.h>
#include <stdlib.h>

long exp(int n, int a)
{
    long n_exp = 1;
    for (int i = 0; i < a; i++)
    {
        n_exp *= n;
    }
    return n_exp;
}

int main()
{
	int n, i;

	printf("n = ");
	scanf("%d", &n);

	double pi = 0.;

    for (i = 0; i <= n; i++)
    {
        pi += ( (4/ (double)(1+8*i)) -
                (2/ (double)(4+8*i)) -
                (1/ (double)(5+8*i)) -
                (1/ (double)(6+8*i)) ) / (double)exp(16, i);
    }

	printf("PI = %.10f\n", pi);
	return 0;
}
