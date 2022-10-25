//In this assignment, we write code to convert decimal integers into hexadecimal numbers

//We pratice using arrays in this assignment

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//convert the decimal integer d to hexadecimal, the result is stored in hex[]

char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B','C', 'D', 'E', 'F'};
int k = 0;

void to_hex(int d, char hex[]) {
    
    while(d>0){
        int last_digit = d%16;
        hex[k] = digits[last_digit];
        d = d/16;
        k++;
    }

    // Reverse the digits' order.
    int i=0;
    while(i<k/2){
        char temp = hex[i];
        hex[i] = hex[k-i-1];
        hex[k-i-1] = temp;
        i++;
    }
    hex[k] = '\0';
}

// Do not change the code below

int main() {
    int d;
    char hex[8];

    printf("Enter a positive integer : ");
    scanf("%d", &d);
    to_hex(d, hex);
    printf("%s\n", hex);
    return 0;
}