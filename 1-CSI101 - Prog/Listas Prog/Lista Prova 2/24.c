//Escreva uma função que receba um vetor de valores reais e seu tamanho e leia valores do teclado para preenchertodo o vetor apenas com valores positivos.
//Observe que valores negativos devem ser ignorados e a leitura deve ser encerrada assim que a última posição do vetor for preenchida

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

float preenche(int n1[], int tamN1){
   int valor;

    for (int i = 0; i < tamN1; i++){
        printf("Digite um valor: ");
        scanf("%i", &valor);

        if(valor >= 0)
            n1[i] = valor;

        if(valor < 0)
            i--;
    }

    for (int i = 0; i < tamN1; i++){
        printf("\nO valor %i do vetor e %i", i, n1[i]);
    }
    
}

int main(){
    int n1[5] = {0};
    
    preenche(n1, 5);

    return 0;
    
}