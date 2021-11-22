// Faça um programa que crie uma matriz quadrada de inteiros de tamanho 3, inicialize-a como uma matriz identidade e imprima-a, organizando os elementos em linhas e colunas.
// Dica: utilize “%5d” no printf para imprimir cada inteiro alinhado à direita

// 1    0   0   0   0
// 0    1   0   0   0
// 0    0   1   0   0
// 0    0   0   1   0
// 0    0   0   0   1

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int main(){
    int mat[3][3];

    for (int i = 0; i < 3; i++){
        
        for (int j = 0; j < 3; j++){
        
            if(j==i){
                mat[i][j] = 1;

            }
            else{
                mat[i][j] = 0;
            }

        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%5i", mat[i][j]);
        }
        printf("\n");
    }

    
    return 0;

}