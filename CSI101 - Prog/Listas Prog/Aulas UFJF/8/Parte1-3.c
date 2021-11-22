// Faça um programa que crie uma matriz 4x2 de números reais, preencha-a com valores digitados pelo usuário e imprima-a, organizando os elementos em linhas e colunas.
// Dica: utilize “%8.2f” no printf para imprimir cada real alinhado à direita em um espaço de 8 casas, sendo duas decimais

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int main(){
    float mat[4][2];

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
            printf("digite o elemento linha %i coluna %i: ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
            printf("%8.2f", mat[i][j]);
        }
        printf("\n");
    }

    
    return 0;

}