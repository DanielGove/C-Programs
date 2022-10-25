#include <stdio.h>
#include <stdlib.h>

/* This program should print the sum of the elements
 *     1^2, 2^2, 3^2, ..., n^2
 * where n is an integer provided by the user on the
 * command line. Hunt down the bugs and squash them!
 * Seek out the memory leaks and plug them up! */

/* Computes the sum of the first n elements in the array. */
int sum(int n, int* arr)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    
    return sum;
}

/* Fills the given array with the values
 * 1^2, 2^2, 3^2, ..., (n-1)^2, n^2. */
void fillSquares(int n, int* arr)
{
    for(int i = 1; i <= n; i++)
        arr[i-1] = i*i;
}

/* Reads an integer n from arguments,
 * fills array with squares, and computes
 * the sum of the squares. Prints out the
 * sum before freeing all used memory. */
int main(int argc, char* argv[]) {
    int n, arr_sum;
    int* arr;

    // Make sure there are arguments
    if(argc <= 1) {
        printf("usage: ./squares n\n");
        return 1;
    }

    // convert string input to an int type
    n = atoi(argv[1]);
    if (n <= 0) {
        printf("n must be positive.");
        return 1;
    }

    arr = (int*) malloc(n * sizeof(int));
    fillSquares(n, arr);
    arr_sum = sum(n, arr);
    printf("total: %d\n", arr_sum);
    free(arr);
    return 0;
}