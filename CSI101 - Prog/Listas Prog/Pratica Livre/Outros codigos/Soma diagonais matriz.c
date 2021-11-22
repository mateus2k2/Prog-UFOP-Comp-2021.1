/*
Faça um programa que crie uma matriz NxN de interios sendo N definido com a diretiva define. O programa deve inicializar a matriz com valores digitados pelo usuario e apos isso, imprimir
A-A soma dos elementos da diagonal proncipal 
B-A soma da diagonal secundaria da matriz
*/

#include <stdlib.h>
#include <stdio.h>
#define N 3

int main(){
    int m[N][N];
    int i = 0, j = 0, k = N-1;
    int principal=0, segundaria=0;

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf("Digite o elemento linha %i coluna %i: ", i, j);
            scanf("%i", &m[i][j]);
        }
        printf("\n");
    }

    i = 0;
    j = 0;

    for (i = 0; i < N; i++){
        
        for (j = 0; j < N; j++){
            if(i == j){
                principal = principal + m[i][j];
                printf("\n%i indice %i e %i", m[i][j], i, j);
            }
        }   
    }

    i = 0;
    j = 0;
    printf("\n");

    for (i = 0; i < N; i++){
        
        for (j = 0; j < N; j++){

            if(j == k){
                segundaria = segundaria + m[i][j]; 
                k--;
                printf("\n%i indice %i e %i e k %i", m[i][j], i, j, k);
                break;
            }
        }   
    }

    printf("\n");

    printf("\nA soma da diagonal principal e %i", principal);
    printf("\nA soma da diagonal segundaria e %i", segundaria);

    return 0;

}