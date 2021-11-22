#include <stdio.h>

int main(){
    int vetor1[5], vetor2[5], vetor3[5];
    int valor;

    for (int i = 0; i < 5; i++){
        printf("Digite o valor para os indices do vetor 1: ");
        scanf("%i", &vetor1[i]);

    }

    for (int i = 0; i < 5; i++){
        printf("Digite o valor para os indices do vetor 2: ");
        scanf("%i", &vetor2[i]);
    
    }

    for (int i = 0; i < 5; i++){

        vetor3[i] = vetor1[i]+vetor2[i];

        printf("\nvetor 3 de indice %i vale %i", i, vetor3[i]);

    }

    return 0;
     

}