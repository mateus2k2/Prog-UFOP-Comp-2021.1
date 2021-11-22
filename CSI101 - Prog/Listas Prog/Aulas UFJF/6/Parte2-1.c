#include <stdio.h>

int main(){
    int vetor[5], mult[5];
    int escalar;

    for (int i = 0; i < 5; i++){
        printf("Digite o valor para os indices do vetor: ");
        scanf("%i", &vetor[i]);

    }

    printf("Digite o valor escalar");
    scanf("%i", &escalar);

    for (int i = 0; i < 5; i++){

        mult[i] = vetor[i] * escalar;
        printf("\nA multiplicacao %i vale %i", i, mult[i]);

    }

    return 0;
     
}