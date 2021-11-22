// Faça um programa que verifique se dois vetores, U e V do mesmo tamanho são perpendiculares entre si.
// O seu programa deverá ler os tamanhos e os elementos de cada um dos vetores e armazenar em um ponteiro com tamanho definido pelo número de elementos.

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


int main(int argc, char *argv[ ]){
    int tamanho;
    int produto = 0;
    int *vetor1, *vetor2;

    printf("Digite o tamanho dos vetores: ");
    scanf("%i", &tamanho);

    vetor1 = (int*)malloc(tamanho * sizeof(int));
    vetor2 = (int*)malloc(tamanho * sizeof(int));

    printf("Digite os valores de vetor 1: \n");
    for (int i = 0; i < tamanho; i++){
        printf("%i: ", i+1);
        scanf("%i", vetor1+i);
    }
    
    printf("\n");

    printf("Digite os valores de vetor 2: \n");
    for (int i = 0; i < tamanho; i++){
        printf("%i: ", i+1);
        scanf("%i", vetor2+i);
    }

    for (int i = 0; i < tamanho; i++){
        produto = produto + (vetor1[i])*(vetor2[i]);
    }

    printf("\n");

    printf("PRODUTO IGUAL A %i\n", produto);

    if(produto == 0)
        printf("VETORES SAO PERPENDICULARES");
    else
        printf("VETORES NAO SAO PERPENDICULARES");

    return 0;
}