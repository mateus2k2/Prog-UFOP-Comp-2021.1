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
    int tamanho, *vetor1, *vetor2;;
    int produto1 = 0, produto2 = 0, produto3 = 0;
    int numero;

    printf("\n");

    printf("Digite o tamanho dos vetores: ");
    scanf("%i", &tamanho);

    printf("Digite um numero qualquer (c) para checar a propriedade: ");
    scanf("%i", &numero);

    printf("\n");

    vetor1 = (int*)malloc(tamanho * sizeof(int));
    vetor2 = (int*)malloc(tamanho * sizeof(int));

    printf("Digite os valores de vetor U: \n");
    for (int i = 0; i < tamanho; i++){
        printf("%i: ", i+1);
        scanf("%i", vetor1+i);
    }
    
    printf("\n");

    printf("Digite os valores de vetor V: \n");
    for (int i = 0; i < tamanho; i++){
        printf("%i: ", i+1);
        scanf("%i", vetor2+i);
    }

    for (int i = 0; i < tamanho; i++){
        produto1 = produto1 + (vetor1[i])*(vetor2[i]);
        if(i==tamanho-1)
            produto1 = produto1 * numero;
    }
    
    for (int i = 0; i < tamanho; i++){
        produto2 = produto2 + ((numero)*(vetor1[i]))*vetor2[i];
    }

    for (int i = 0; i < tamanho; i++){
        produto3 = produto3 + (vetor1[i]) * ((numero)*(vetor2[i]));
    }

    printf("\n");

    printf("PRODUTO c(U.V)    IGUAL A %i\n", produto1);
    printf("PRODUTO (c.U).(V) IGUAL A %i\n", produto2);
    printf("PRODUTO (U).(c.V) IGUAL A %i\n", produto3);

    printf("\n");

    if(produto1 == produto2 == produto3)
        printf("VETORES OBEDECEM A PROPRIEDADE");
    else
        printf("VETORES NAO OBEDECEM A PROPRIEDADE");

    return 0;
}