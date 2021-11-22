// Faça um programa para realizar a operação acima com dois vetores lidos do usuário. Você deverá ler o tamanho, 
// que é o mesmo para os dois vetores, e o cada um dos elementos dos dois vetores e armazena-los em dois ponteiros com tamanhos definidos pelo usuário.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int *vetor1, *vetor2;
    int tamanho;
    int mult = 0;

    printf("Digite o quantidade de elementos do vetor: ");
    scanf("%i", &tamanho);

    vetor1 = (int*)malloc(tamanho * sizeof(int));
    vetor2 = (int*)malloc(tamanho * sizeof(int));

    printf("\nDigite os elementos do vetor 1: \n");
    for (int i = 0; i < tamanho; i++){
        printf("%i: ", i+1);
        scanf("%d", (vetor1+i));
    }

    printf("\nDigite os elementos do vetor 2: \n");
    for (int i = 0; i < tamanho; i++){
        printf("%i: ", i+1);
        scanf("%d", (vetor2+i));
    }

    for (int i = 0; i < tamanho; i++){
        mult = mult + (vetor1[i])*(vetor2[i]);    
    }

    printf("A multiplicacao dos vetores e: %i", mult);

    return 0;
}