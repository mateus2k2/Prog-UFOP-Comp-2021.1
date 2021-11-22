//Entrada: Elementos do ponteiro (vetor) e tamanho dele.
//Objetivo: Calcular Norma do vetor
//Saida: Norma do vetor

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int *ponteiro;
    int tamanho;
    float norma = 0;

    printf("Digite o quantidade de elementos do vetor: ");
    scanf("%i", &tamanho);

    ponteiro = (int*)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++){
        printf("Digite o elemento %i: ", i+1);
        scanf("%d", (ponteiro+i));
    }

    for (int i = 0; i < tamanho; i++){
        norma = norma + (ponteiro[i])*(ponteiro[i]);    
    }
        
    norma = sqrt(norma);

    printf("A norma do vetor e: %f", norma);

    return 0;
}
   