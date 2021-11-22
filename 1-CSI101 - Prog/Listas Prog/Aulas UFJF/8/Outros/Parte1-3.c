// Faça um programa que crie uma matriz 4x2 de números reais, preencha-a com valores digitados pelo usuário e imprima-a, organizando os elementos em linhas e colunas.
// Dica: utilize “%8.2f” no printf para imprimir cada real alinhado à direita em um espaço de 8 casas, sendo duas decimais.

#include <stdlib.h>
#include <stdio.h>

int main(){
    float m[4][3];
    int i = 0, j = 0;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 3; j++){
            printf("Digite o elemento linha %i coluna %i: ", i, j);
            scanf("%f", &m[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    j = 0;
    i = 0;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 3; j++){
            printf("%8.2f ",m[i][j]);
        }
        printf("\n");
    }

    return 0;

}