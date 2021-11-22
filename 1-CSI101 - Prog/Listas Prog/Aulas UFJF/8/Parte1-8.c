// Faça um programa para exibir a soma de duas matrizes quadradas 3 x 3.  Deverá ser criada uma função para ler uma matriz 
// (será chamado duas vezes com parâmetros diferentes) e uma segunda função que irá imprimir a soma das matrizes passadas como parâmetro.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 10


void lematriz(float mat[MAX][MAX], int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("Digite o elemento linha %i coluna %i: ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }        
    }

    printf("\n");
}

void imprimeSoma(float matA[MAX][MAX], float matB[MAX][MAX], int linhas, int colunas){

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("\nO elemento linha %i coluna %i: %f", i+1, j+1, matA[i][j] + matB[i][j]);              
        }    
    }

    printf("\n");
}



int  main(){
    
    float matA[MAX][MAX], matB[MAX][MAX];    
    int linhas, colunas;   
    
    printf("\nDigite o no de linhas e de colunas das matrizes: ");  
    scanf("%d%d",&linhas, &colunas);   
    
    printf("\nForneca os elementos da matriz a:\n");
    lematriz(matA,linhas,colunas);    

    printf("\nForneca os elementos da matriz b:\n");
    lematriz(matB,linhas,colunas); 
    
    printf("\nA soma dos elementos da matriz e: ");
    imprimeSoma(matA,matB,linhas,colunas);  

    return 0;

}