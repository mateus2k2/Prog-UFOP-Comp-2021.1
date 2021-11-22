#include <stdio.h>

int main(){
    int vetor[10];
    int j = 0, k = 0;

    for (int i = 0; i < 10; i++){
        printf("Digite o valor para o indice %i do vetor: ", i);
        scanf("%i", &vetor[i]);
    }

    printf("\n---------------------------\n");

    for (int j = 0; j < 10; j++){
        
        for (k = 0; k < 10; k++){
            if(j != k){
                if(vetor[j] == vetor[k])
                    printf("O vetor de indice %i e %i sao iguais e valem %i\n", j, k, vetor[j]);
            }
        }
        
    }
    
    return 0;
     
}