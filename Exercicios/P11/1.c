//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

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

    int *vet1, *vetBaixa, *vetAlta;
    int contBaixa = 0, contAlta = 0, tam;
    double media = 0;

    printf("Digite o tamanho do vetor: "); scanf("%i", &tam);

    vet1 = malloc(tam * sizeof(int));

    printf("Digite os valores do vetor: ");
    for (int i = 0; i < tam; i++){
        scanf("%i", &vet1[i]);
        media = vet1[i] + media;
    }
    media = media/(double)tam;
    printf("\nA media e: %lf\n", media);

    for (int i = 0; i < tam; i++){
        if(vet1[i] >= media) 
            contAlta++;
        else 
            contBaixa++;       
    }
    vetBaixa = malloc(contBaixa * sizeof(int));
    vetAlta = malloc(contAlta * sizeof(int));

    for (int i = 0; i < tam; i++){
        if(vet1[i] >= media)
            vetAlta[i] = vet1[i];
        else
            vetBaixa[i] = vet1[i];
    }

    printf("Vetor com os valores abaixo da media: [ ");
    for (int i = 0; i < tam; i++){
        if(vet1[i] < media)
            printf("%i ", vetBaixa[i]);
    }
    printf("]");

    printf("\n");

    printf("Vetor com os valores iguais ou acima da media: [ ");
    for (int i = 0; i < tam; i++){
        if(vet1[i] >= media)
            printf("%i ", vetAlta[i]);
    }
    printf("]");
    
    printf("\n");

    free(vet1);
    free(vetAlta);
    free(vetBaixa);


    return 0;
}