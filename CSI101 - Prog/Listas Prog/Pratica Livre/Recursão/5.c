// Write a program in C to count the digits of a given number using recursion.

// Test Data :
// Input a number : 50

// Expected Output :
// The number of digits in the number is :  2

#include <stdio.h>
#include <string.h>

int contaDigitos(int numero){
    static int cont=0;

    if(numero != 0){
        cont++;
        contaDigitos(numero/10);
    }

    return cont;  

}

int main(){
    int numero, digitos;

    printf("Digite o numero: ");
    scanf("%i", &numero);

    digitos = contaDigitos(numero);
    
    printf("%i", digitos);

}

// while (n != 0) {
//     n /= 10;     // n = n/10
//     ++count;
//}