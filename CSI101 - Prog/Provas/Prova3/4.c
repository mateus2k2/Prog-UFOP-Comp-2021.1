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
    int *vetor;
    float media = 0;

    printf("Digite o tamanho do vetores: ");
    scanf("%i", &tamanho);

    vetor = (int*)malloc(tamanho * sizeof(int));

    printf("\n");

    printf("Digite os valores de vetor: \n");
    for (int i = 0; i < tamanho; i++){
        printf("%i: ", i+1);
        scanf("%i", &vetor[i]);

        if(vetor[i] < 0){
            while (vetor[i]<0){
                printf("Valor negativo digitado. Tente Novamente: ");
                scanf("%i", &vetor[i]);
            }
            printf("\n");
        }

        media = media + (vetor[i]);
    }
    
    printf("\n");
    printf("\nValores abaixo da media: %.2f\n", media/tamanho);
    for (int i = 0; i < tamanho; i++){
        if(vetor[i] < media/tamanho)
            printf("%i  ", vetor[i]);
    }
    
    

    return 0;
}