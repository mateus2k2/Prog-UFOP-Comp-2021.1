#include <stdio.h>

int main(){
    int vetor[20];
    int menor, indice;

    for (int i = 0; i < 20; i++){
        printf("\nDigite um valor: ");
        scanf("%i", &vetor[i]);
    }
    
    menor = vetor[1];

    for (int i = 0; i < 20; i++){
        
        if(vetor[i] < menor){
            menor = vetor[i]; 
            indice = i; 
            }
    }

    printf("O menor valor e %i e tem indice %i", menor, indice);

    return 0;
}