// Escreva uma função que recebe um valor N inteiro e positivo e que retorna a seguinte soma:
// S = 1 + 1/2 + 1/3 + 1/4 + ... + 1/N
// A função deve imprimir cada termo gerado e o valor final de S.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

float calculo(int N){
    float S = 1;

    for (int i = 2; i <= N; i++){
        S = S + 1.0/i; 
        printf("\n i --- %i S ---- %f", i, S);
    }

    return S; 

}

int main(){
    int N;
    float soma;

    printf("Digite um valor: ");
    scanf("%i", &N);

    soma = calculo(N);

    printf("\nA soma e %f", soma);

    return 0;
}