// Faça um programa que mostre a soma de dois vetores. O seu programa deverá ler o tamanho dos vetores e depois ler cada um dos elementos dos vetores. 
// Lembrando que a soma de dois vetores e feita somando-se cada um dos elementos.

/*
NOME: Mateus Filipe Moreira Silva
Matriculo: 20.2.8093
*/

#include <stdio.h>
#include <string.h>

int main(){

    int tam; 

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &tam);

    int vet1[tam];
    int vet2[tam];

    printf("\n");

    for (int i = 0; i < tam; i++){
        printf("Digite o valor do elemento %i do vetor 1: ", i);
        scanf("%i", &vet1[i]);
    }

    printf("\n");

    for (int i = 0; i < tam; i++){
        printf("Digite o valor do elemento %i do vetor 2: ", i);
        scanf("%i", &vet2[i]);
    }

    printf("\n");

    printf("A soma dos vetores e: ");
    for (int i = 0; i < tam; i++){
        printf("\nO elemento %i da soma e %i", i, vet1[i] + vet2[i]);
    }
    
    return 0;   

}