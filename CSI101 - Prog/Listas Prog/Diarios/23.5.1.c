// Sabendo que a multiplicação escalar de dois vetores é dado pela fórmula:

// \mathbf{x}\cdot\mathbf{y} = \sum_{i=1}^nx_i*y_i.

// Faça um programa para realizar a operação acima com dois vetores lidos do usuário. Você deverá ler o tamanho, que é o mesmo para os dois vetores, e o cada um dos elementos dos dois vetores

/*
NOME: Mateus Filipe Moreira Silva
Matricula: 20.2.8093
*/

#include <stdio.h>
#include <string.h>

int main(){

    int tam, mult = 0; 

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

    for (int i = 0; i < tam; i++){
        mult = mult + (vet1[i] * vet2[i]);
    }

    printf("A multiplicação dos dois vetores e %i", mult);
    
    return 0;   

}