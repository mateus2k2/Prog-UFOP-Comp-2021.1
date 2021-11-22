//Implemente as funções abaixo para que o programa funcione corretamente.#include 

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

void copiazera (float matA[MAX][MAX], float matB[MAX][MAX], int linhas, int colunas){
    
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matA[i][j] = matB[i][j];  
        }    
    }

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matB[i][j] = 0;  
        }    
    }
    printf("\n");
}

void imprimematriz (float mat[MAX][MAX], int linhas, int colunas){

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("\nO elemento linha %i coluna %i e: %f", i+1, j+1, mat[i][j]);
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
    lematriz(matA,linhas,colunas);    // leitura da matriz a   

    printf("\nForneca os elementos da matriz b:\n");
    lematriz(matB,linhas,colunas); // leitura da matriz b
    
    copiazera(matA,matB,linhas,colunas); // a matriz a “recebe” b e b é zerada.   

    printf("\nMatriz a:\n");   
    imprimematriz(matA,linhas,colunas);   
    
    printf("\nMatriz b:\n");
    imprimematriz(matB,linhas,colunas);   
    
    return 0;

}

