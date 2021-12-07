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


double** cria_transposta (double **mat, int lin, int col);
double** cria_matriz(int lin, int col);
void desaloca_matriz(double **mat, int lin);

int main(int argc, char *argv[ ]){
    int lin, col;
    double **mat, **matT;

    printf("Digite o valor da linha e da coluna: "); scanf("%i %i", &lin, &col);

    mat = cria_matriz(lin, col);
    matT = cria_matriz(col, lin);

    printf("\n");
    for (int i = 0; i < lin; i++){
        printf("Linha %i: ", i+1);
        for (int j = 0; j < col; j++){
            scanf("%lf", &mat[i][j]);
        }        
    }

    printf("\nMatriz: \n");
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            printf("%.0lf ", mat[i][j]);
        }        
        printf("\n");
    }

    matT = cria_transposta (mat, lin, col);

    printf("\nTransposta: \n");
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            printf("%.0lf ", matT[i][j]);
        }        
        printf("\n");
    }

    desaloca_matriz(mat, lin);
    desaloca_matriz(matT, lin);


    return 0;
}

double** cria_matriz(int lin, int col){
    double** mat;

    mat = malloc(lin * sizeof(int*));
    for (int i = 0; i < lin; i++)
        mat[i] = malloc(col * sizeof(int*));    

    return mat;
}

double** cria_transposta (double **mat, int lin, int col){
    double** matT;

    matT = cria_matriz(col, lin);

    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            matT[i][j] = mat[j][i];
        }        
    }

    return matT;
}

void desaloca_matriz(double **mat, int lin){
    for (int i = 0; i < lin; i++)
            free(mat[i]);
        free(mat);
}
