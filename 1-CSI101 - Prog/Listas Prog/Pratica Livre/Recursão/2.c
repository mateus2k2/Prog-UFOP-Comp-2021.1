// Write a program in C to calculate the sum of numbers from 1 to n using recursion

// Test Data :
// Input the last number of the range starting from 1 : 5

// Expected Output :
// The sum of numbers from 1 to 5 :  15


#include <stdio.h>
#include <string.h>

int soma(int n){

    if(n == 0)
        return n;
    else{
        return n + soma(n-1);
    } 

}

int main(){
    int n = 5;

    printf("Digite o numero: ");
    scanf("%i", &n);

    printf("%i", soma(n));

}