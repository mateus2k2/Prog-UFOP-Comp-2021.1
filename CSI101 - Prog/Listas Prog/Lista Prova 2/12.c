// Escreva uma função que recebe um valor N inteiro e positivo e que calcula o valor aproximado de PI considerando N termos na equação:
// PI = 4 ( 1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13 ... )
// A função deve imprimir a expressão (com cada termo utilizado no cálculo) e o resultado obtido.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

float calculo(int N){
    float S = 1;
    int sinal = 0, i = 3;

    while(i + 2 <= N){

        if(sinal == 0){
            S = S - 1.0f/i;
            printf("\ni --- %i S ---- %f", i, S);
            sinal = 1;
            i = i + 2;
            //printf("\n*************");
            
        }

        else{
            S = S + 1.0f/i;
            printf("\ni --- %i S ---- %f", i, S);
            sinal = 0;
            i = i + 2;
            //printf("\n!!!!!!!!!!!!!!!!");
        }      
        
    }

    printf("\ni --- %i S ---- %f", i, S);
    
    return S; 
}

int main(){
    int N;
    float soma;

    printf("Digite um valor: ");
    scanf("%i", &N);

    soma = calculo(N);

    printf("\nO valor de PI %f", 4 * soma);

    return 0;
}