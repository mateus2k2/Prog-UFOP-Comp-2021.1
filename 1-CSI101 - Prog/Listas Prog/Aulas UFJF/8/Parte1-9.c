// a) Faça uma função que leia do teclado uma matriz quadrada de tamanho N.    
// b) Faça uma função que receba duas matrizes e inicialize a segunda matriz com a transposta da primeira (linhas e colunas invertidas). 
// c) Faça um programa que crie as matrizes, chame as funções e imprima a segunda matriz

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 10


void lematriz(float mat[MAX][MAX], int tamanho){
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            printf("Digite o elemento linha %i coluna %i: ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }        
    }

    printf("\n");
}

void imprimeInvertida(float matA[MAX][MAX], float matB[MAX][MAX], int tamanho){

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            matB[j][i] = matA[i][j];              
        }    
    }

    printf("\n");   

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            printf("%8.2f", matB[i][j]);
        } 
        printf("\n");   
    }
}



int  main(){
    
    float matA[MAX][MAX], matB[MAX][MAX];    
    int tamanho;   
    
    printf("\nDigite o no de linhas e de colunas das matrizes: ");  
    scanf("%d", &tamanho);   
    
    printf("\nForneca os elementos da matriz a:\n");
    lematriz(matA, tamanho);    
    
    printf("\nA matriz invertido e: ");
    imprimeInvertida(matA, matB, tamanho);  

    return 0;

}