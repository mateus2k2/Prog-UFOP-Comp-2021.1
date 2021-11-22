// Write a program in C to Print Fibonacci Series using recursion. Go to the editor

// Test Data :
// Input number of terms for the Series (< 20) : 10

// Expected Output :
// Input number of terms for the Series (< 20) : 10                                
// The Series are :                                                                
// 1  1  2  3  5  8  13  21  34  55  

#include <stdio.h>
#include <string.h>

int fibo (int n){
    
    if(n==1 || n==2){
        //printf("\n1");
        return 1;
    }
        
    else
        printf("\n%i", fibo(n-1) + fibo(n-2));

}

int main(){
    int n;

    printf("Digite o numero de termos da serie (<20): ");
    scanf("%i", &n);

    fibo(n);
}   