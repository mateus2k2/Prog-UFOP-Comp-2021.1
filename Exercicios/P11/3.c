//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <assert.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int multiplica_matrizes(int ***resultado, int **matA, int linA, int colA, int **matB, int linB, int colB);

int main(int argc, char *argv[ ]){
    int **matA, **matB, **resultado;
    int linA, colA, linB, colB;

    printf("Digite os tamanhos da matriz A: "); scanf("%i %i", &linA, &colA);
    
    matA = malloc(linA * sizeof(int*));
        for (int i = 0; i < linA; i++)
            matA[i] = malloc(colA * sizeof(int*)); 
    
    for (int i = 0; i < linA; i++){
        printf("Linha %i: ", i+1);
        for (int j = 0; j < colA; j++){
            scanf("%i", &matA[i][j]);
        }        
    }

    printf("\n");
    printf("Digite os tamanhos da matriz B: "); scanf("%i %i", &linB, &colB);
    
    matB = malloc(linB * sizeof(int*));
        for (int i = 0; i < linB; i++)
            matB[i] = malloc(colB * sizeof(int*)); 
    
    for (int i = 0; i < linB; i++){
        printf("Linha %i: ", i+1);
        for (int j = 0; j < colB; j++){
            scanf("%i", &matB[i][j]);
        }        
    }

    multiplica_matrizes(&resultado, matA, linA, colA, matB, linB, colB);
    printf("\n");

    printf("\nMatrizA: \n");
    for (int i = 0; i < linA; i++){
        for (int j = 0; j < colA; j++){
            printf("%i ", matA[i][j]);
        }        
        printf("\n");
    }

    printf("\nMatrizB: \n");
    for (int i = 0; i < linB; i++){
        for (int j = 0; j < colB; j++){
            printf("%i ", matB[i][j]);
        }        
        printf("\n");
    }

    printf("\nMultiplicada: \n");
    for (int i = 0; i < linA; i++){
        for (int j = 0; j < colB; j++){
            printf("%i ", resultado[i][j]);
        }        
        printf("\n");
    }

    for (int i = 0; i < linA; i++)
        free(matA[i]);
    free(matA);

    for (int i = 0; i < linB; i++)
        free(matB[i]);
    free(matB);

    for (int i = 0; i < linA; i++)
        free(resultado[i]);
    free(resultado);



    return 0;
}

int multiplica_matrizes(int ***resultado, int **matA, int linA, int colA, int **matB, int linB, int colB){

    if(colA == linB){

        *resultado = malloc(linA * sizeof(int*));
        for (int i = 0; i < linA; i++)
            *resultado[i] = malloc(colB * sizeof(int*));

        for (int i = 0; i < linA; i++){
            for (int j = 0; j < colB; j++){
                *resultado[i][j] = 0;
                for (int k = 0; k < colA; k++){
                    *resultado[i][j] = *resultado[i][j] + ((matA[i][k]) * (matB[k][j]));
                }
                printf("%i ", *resultado[i][j]);
            }
            printf("\n");                
        }

        return 1;
    }
    else
        return 0;
}

// ./3.exe < entrada.txt