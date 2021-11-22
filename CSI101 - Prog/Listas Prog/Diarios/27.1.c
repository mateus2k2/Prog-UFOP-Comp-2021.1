//Entrada: Elementos do ponteiro (vetor) e tamanho dele.
//Objetivo: Ordenar ponteiro em ordem crescente
//Saida: Ponteiro em ordem crescente

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int *ponteiro;
    int tamanho;
    int i, j, t;


    printf("Digite o quantidade de numeros a serem ordenados: ");
    scanf("%i", &tamanho);

    ponteiro = (int*)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++){
        printf("Digite o elemento %i: ", i+1);
        scanf("%d", (ponteiro+i));
    }
      
    for (i = 0; i < tamanho; i++) {
  
        for (j = i + 1; j < tamanho; j++) {
  
            if (*(ponteiro + j) < *(ponteiro + i)) {
  
                t = *(ponteiro + i);
                *(ponteiro + i) = *(ponteiro + j);
                *(ponteiro + j) = t;
            }
        }
    }
  
    for (i = 0; i < tamanho; i++){
        printf("%d ", *(ponteiro + i));
    }    

    return 0;
}
    
