#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m;

	printf("n = ");
	scanf("%d", &n);
    m = n;

    while ((n != 1) && (n != 4))
    {
        // Calculate the squared digit's sum.
        int i, sum = 0;
        while (n >= 10)
        {
            i = n % 10;
            sum += i*i;

            n -= i;
            n /= 10;
        }
        sum += n*n;

        n = sum;
        printf("%d\n", n);
    }

	if(n==1) printf("%d is a happy number.\n", m);
	else printf("%d is NOT a happy number.\n", m);
	return 0;
}
