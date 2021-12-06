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

typedef struct{
    int **mat;
    int lin;
    int col;
}matrizes;


int main(int argc, char *argv[ ]){
    matrizes matriz1, matriz2;
    int **mult;

    FILE *arquivo = fopen("matrizes.txt", "r");
    FILE *arquivoDat = fopen("matrizes.dat", "w");

    for (int t = 0; fscanf(arquivo, "%i %i", &matriz1.lin, &matriz1.col) != EOF; t++){
        //------------------------------------------------------------------------
        

        matriz1.mat = malloc(matriz1.lin * sizeof(int*));
        for (int i = 0; i < matriz1.lin; i++)
            matriz1.mat[i] = malloc(matriz1.col * sizeof(int*));  

        for (int i = 0; i < matriz1.lin; i++){
            for (int j = 0; j < matriz1.col; j++){
                fscanf(arquivo, "%i", &matriz1.mat[i][j]);
                //printf("%i ", matriz1.mat[i][j]);
            }
            //printf("\n");            
        }

        //------------------------------------------------------------------------
        //printf("\n");

        fscanf(arquivo, "%i %i", &matriz2.lin, &matriz2.col);

        matriz2.mat = malloc(matriz2.lin * sizeof(int*));
        for (int i = 0; i < matriz2.lin; i++)
            matriz2.mat[i] = malloc(matriz2.col * sizeof(int*));  

        for (int i = 0; i < matriz2.lin; i++){
            for (int j = 0; j < matriz2.col; j++){
                fscanf(arquivo, "%i", &matriz2.mat[i][j]);
                //printf("%i ", matriz2.mat[i][j]);
            }
            //printf("\n");            
        }

        //------------------------------------------------------------------------
        //printf("\n");
        fwrite(&matriz1.lin, sizeof(int), 1, arquivoDat);
        fwrite(&matriz2.col, sizeof(int), 1, arquivoDat);


        if(matriz1.col == matriz2.lin){

            mult = malloc(matriz1.lin* sizeof(int*));
            for (int i = 0; i < matriz1.lin; i++)
                mult[i] = malloc(matriz2.col* sizeof(int*));

            for (int i = 0; i < matriz1.lin; ++i) {
                for (int j = 0; j < matriz2.col; ++j) {
                    mult[i][j] = 0;
                }
            }
        
            for (int i = 0; i < matriz1.lin; i++){
                for (int j = 0; j < matriz2.col; j++){
                    for (int k = 0; k < matriz1.col; k++){
                        mult[i][j] = mult[i][j] + (matriz1.mat[i][k] * matriz2.mat[k][j]);
                    }
                    //printf("%i ", mult[i][j]);
                    fwrite(&mult[i][j], sizeof(int), 1, arquivoDat);
                }
                //printf("\n");                
            }
                     
        }
        //else
            //printf("\nMatrizes tem tamanho errados");


        for (int i = 0; i < matriz1.lin; i++){
            free(matriz1.mat[i]);
        }
            free(matriz1.mat);
        for (int i = 0; i < matriz2.lin; i++){
            free(matriz2.mat[i]);
        }
            free(matriz2.mat);
        for (int i = 0; i < matriz1.lin; i++){
            free(mult[i]);
        }
            free(mult);
        
    }

    fclose(arquivoDat);
    fclose(arquivo);
    
    //printf("\n");


    return 0;

    
}
