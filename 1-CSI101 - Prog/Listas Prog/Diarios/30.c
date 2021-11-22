//Faça um algoritmo que leia um ponteiro e que em seguida percorra o ponteiro e encontre o valorMenor e o valorMaior valor. 
//Mostre-os juntamente com seus respectivos índices no vetor. O número de elementos deste ponteiro deve ser definido pelo usuário.

//Entrada: 
//Objetivo: 
//Saida: 

#include <assert.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]){
    int tamanho;
    int *vetor;

    int valorMenor = INFINITY, valorMaior = -INFINITY;
    int indiceMaior, indiceMenor;

    printf("Digite o tamanho dos vetores: ");
    scanf("%i", &tamanho);

    vetor = (int*)malloc(tamanho * sizeof(int));

    printf("Digite os valores de vetor 1: \n");
    for (int i = 0; i < tamanho; i++){
        printf("%i: ", i);
        scanf("%i", vetor+i);

        if(*(vetor+i) > valorMaior){
            valorMaior = *(vetor+i);
            indiceMaior = i;
        }
        
        if(*(vetor+i) < valorMenor){
            valorMenor = *(vetor+i);
            indiceMenor = i;
        }
    }
    
    printf("\n");
    printf("O maior valor e: %i e tem indice %i\n", valorMaior, indiceMaior);
    printf("O menor valor e: %i e tem indice %i\n", valorMenor, indiceMenor);

    return 0;
}