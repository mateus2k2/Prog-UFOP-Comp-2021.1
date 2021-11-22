//Escreva um programa que leia dois vetores de 7 posições e faça a multiplicação dos elementos de mesmo índice, colocando o resultado em um terceiro vetor. Mostre o vetor resultante.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int main(){
    int vet1[7], vet2[7], vet3[7];

    printf("\n");

    for (int i = 0; i < 7; i++){
        printf("Digite o elemetno %i do vetor 1: ", i+1);
        scanf("%i", &vet1[i]);
    }

    printf("\n");

    for (int i = 0; i < 7; i++){
        printf("Digite o elemetno %i do vetor 2: ", i+1);
        scanf("%i", &vet2[i]);
    }

    printf("\n");

    for (int i = 0; i < 7; i++){
        vet3[i] = vet1[i]*vet2[i];
    }

    printf("\n");

    for (int i = 0; i < 7; i++){
        printf("\nO vetor resultante do vetor 3 eleemnto %i e %i", i+1, vet3[i]);
    }
    
    return 0;

}