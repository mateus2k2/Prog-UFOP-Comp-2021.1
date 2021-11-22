// Faça uma função que leia um vetor de dimensão M e outra função que leia uma matriz quadrada de dimensão M. 
// Crie também uma função que multiplique o vetor pela matriz, atualizando-o. Faça um programa que chame as funções e imprima o resultado.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 10


void leMatriz(float mat[MAX][MAX], int tamanho){
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            printf("Digite o elemento linha %i coluna %i: ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }        
    }

    printf("\n");
}

void leVetor(float vet[MAX], int tamanho){
    for (int i = 0; i < tamanho; i++){
            printf("Digite o elemento %i: ", i+1);
            scanf("%f", &vet[i]);
    }

    printf("\n");
}

void multiplica(float mat[MAX][MAX], float vet[MAX], int tamanho){
    float vet2[MAX] = {0};

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            vet2[i] = vet2[i] + vet[j]*mat[j][i];              
        }    
    }

    for (int i = 0; i < tamanho; i++){
        vet[i] = vet2[i];
    }

    printf("\n");   

   
}



int  main(){
    
    float mat[MAX][MAX], vet[MAX];    
    int tamanho;   
    
    printf("\nDigite o tamanho da matriz quadrada e do vetor: ");  
    scanf("%d", &tamanho);   
    
    printf("\nForneca os elementos da matriz a:\n");
    leMatriz(mat, tamanho);  
    
    printf("\nForneca os elementos do vetor:\n");
    leVetor(vet, tamanho);    
    
    multiplica(mat, vet, tamanho);  
    printf("\nNovo vetor:");
    for (int i = 0; i < tamanho; i++){
        printf("\n%.2f", vet[i]);
    }

    return 0;

}