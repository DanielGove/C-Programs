#include <stdio.h>
#include <stdlib.h>

int x = 0,y = 0;
double two_d_random(int n){

	//TODO
	//Fill in code below
	//When deciding which way to go for the next step, generate a random number as follows.
	//r = rand() % 4;
	//Treat r = 0, 1, 2, 3$ as up, right, down and left respectively.

	//The random walk should stop once the x coordinate or y coordinate reaches $-n$ or $n$. 
	//The function should return the fraction of the visited $(x, y)$ coordinates inside (not including) the square.
    n = 2*n;
    int square[n][n];
    
    int i=0, j=0, count=0, offset=n/2;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            square[i][j] = 0;
        }
    }

    x=y= offset;
    while(x > 0 && x < n && y > 0 && y < n) {
        square[x][y] = 1;
        int k = rand() % 4;
        switch (k) {
            case(0):
                ++y;
                break;
            case(1):
                ++x;
                break;
            case(2):
                --y;
                break;
            case(3):
                --x;
                break;
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(square[i][j] == 1) {
                ++count;
            }
        }
    }
    return (double)count / ((n-1) * (n-1));
}
    

//Do not change the code below
int main()
{
	int trials = 1000;

	srand(12345);
	for(int n=1; n<=64; n*=2)
	{	
		double sum = 0.;
		for(int i=0; i < trials; i++)
		{
			double p = two_d_random(n);
			sum += p;
		}
		printf("%d %.3lf\n", n, sum/trials);
	}
	return 0;
}