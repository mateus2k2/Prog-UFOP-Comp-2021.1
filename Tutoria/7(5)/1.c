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

void leMats(double mat[][10], int linha, int coluna){

    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("L%i C%i: ", i+1, j+1); scanf("%lf", &mat[i][j]);
        }
        printf("\n");
    }
}

void imprimeMat(double mat[][10], int linha, int coluna){

    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("%.0lf ", mat[i][j]);
        }
        printf("\n");
    }
}


int main(int argc, char *argv[ ]){
    double matA[10][10], matB[10][10], matC[10][10];
    int linhaA, colunaA=1, linhaB=0, colunaB;


    while (colunaA != linhaB){
        printf("DIGITE AS DIMENCOES DA MATRIZ A: "); scanf("%i %i", &linhaA, &colunaA);
        printf("DIGITE AS DIMENCOES DA MATRIZ B: "); scanf("%i %i", &linhaB, &colunaB);

        if(colunaA != linhaB)
            printf("\nDimensao da coluna de A eh diferente da dimencao da linha de B. Tente novamente\n");

    }

    printf("\n");
    printf("DIGITE AS ELEMENTOS DA MATRIZ A\n");
    leMats(matA, linhaA, colunaA);
    
    printf("\n");
    printf("DIGITE AS ELEMENTOS DA MATRIZ B\n");
    leMats(matB, linhaB, colunaB);

    int aux = 0;
	for(int i = 0; i < linhaA; i++) {
		
        for(int j = 0; j < colunaB; j++) {
			
			matC[i][j] = 0;

			for(int x = 0; x < linhaB; x++) {
				aux +=  matA[i][x] * matB[x][j];
			}

			matC[i][j] = aux;
			aux = 0;
		}
	}
    
    printf("MATRIZ MULTIPLICADA\n");
    imprimeMat(matC, linhaA, colunaB);

    return 0;
}