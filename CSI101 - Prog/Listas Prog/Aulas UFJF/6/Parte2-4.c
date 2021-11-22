// Modifique o programa anterior para que este exiba apenas
// um par de índices de elementos repetidos, mesmo que haja
// mais repetições. Ao final, se nenhum par de índices repetidos
// foi encontrado, imprima a mensagem "não há elementos
// repetidos no vetor".

#include <stdio.h>

int main(){
    int vetor[10];
    int j = 0, k = 0, l = 0;

    for (int i = 0; i < 10; i++){
        printf("Digite o valor para o indice %i do vetor: ", i);
        scanf("%i", &vetor[i]);
    }

    printf("\n---------------------------\n");

    for (j = 0; j < 10; j++){
        
        for (k = 0; k < 10; k++){
            if(j != k){
                if(vetor[j] == vetor[k]){
                    printf("\nO vetor de indice %i e %i sao iguais e valem %i\n", j, k, vetor[j]);
                    j=10;
                    l = 1;
                    break;
                }
            }    
        }
    }
    
    if(l == 0){
        printf("\nNao existe elementos repetidos\n");
    }

    return 0;
     
}