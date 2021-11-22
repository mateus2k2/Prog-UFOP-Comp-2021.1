#include <stdio.h>

int main(){
    int vetor[10];

    for (int i = 0; i < 10; i++){
        printf("Digite o valor para o indice %i do vetor: ", i);
        scanf("%i", &vetor[i]);

    }

    for (int i = 0; i < 10; i++){
        if(i%2==0){
            if(vetor[i]%2 != 0)
                printf("\nO vetor de indice %i eh par e comtem %i que eh impar", i, vetor[i]);
        }

    }
    
    return 0;
     
}