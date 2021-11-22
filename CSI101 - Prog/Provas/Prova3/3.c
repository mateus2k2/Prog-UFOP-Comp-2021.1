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

/*

*/

int main(int argc, char *argv[ ]){
    int tamanho;
    int produtoUV = 0, produtoVU = 0 ;
    int *vetorU, *vetorV;

    printf("Digite o tamanho dos vetores: ");
    scanf("%i", &tamanho);

    vetorU = (int*)malloc(tamanho * sizeof(int));
    vetorV = (int*)malloc(tamanho * sizeof(int));

    printf("\n");

    printf("Digite os valores de vetor U: \n");
    for (int i = 0; i < tamanho; i++){
        printf("%i: ", i+1);
        scanf("%i", vetorU+i);
    }
    
    printf("\n");

    printf("Digite os valores de vetor V: \n");
    for (int i = 0; i < tamanho; i++){
        printf("%i: ", i+1);
        scanf("%i", vetorV+i);
    }

    for (int i = 0; i < tamanho; i++){
        produtoUV = produtoUV + (vetorU[i])*(vetorV[i]);
    }

    for (int i = 0; i < tamanho; i++){
        produtoVU = produtoVU + (vetorV[i])*(vetorU[i]);
    }

    printf("\n");

    printf("PRODUTO UV IGUAL A %i\n", produtoUV);
    printf("PRODUTO VU IGUAL A %i\n", produtoVU);


    if(produtoUV == produtoVU)
        printf("A propriedade e verdadeira");
    else
        printf("A propriedade e falsa");

    return 0;
}