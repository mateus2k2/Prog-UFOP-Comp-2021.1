#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define MAX 4


void trasposta(float mat1[MAX][MAX], float mat2[MAX][MAX]){
    
    printf("\nMATRIZ TRANSPOSTA\n");

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            mat2[i][j] = mat1[j][i];
            printf("%.2f  ", mat2[i][j]);
        }
        printf("\n");                                    
    }
}

void diagonal (float mat1[MAX][MAX], float mat2[MAX][MAX]){

    printf("\nDIAGONAL PRINCIPAL\n");

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if(i==j){
                mat2[i][j] = mat1[i][j];
                printf("%.2f  ", mat2[i][j]);
            }
            if(i != j){
                mat2[i][j] = 0;
                printf("%.2f   ", mat2[i][j]);
            }
        }
        printf("\n");                                    
    }
}

void soma (float mat1[MAX][MAX], float mat2[MAX][MAX]){

    printf("\nMATRIZ SOMA\n");

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            mat2[i][j] = mat1[i][j]*2;
            printf("%.2f    ",  mat2[i][j]);
            }
        printf("\n");                                    
        }
    }

void media (float mat1[MAX][MAX], float mat2[MAX][MAX]){
    float media = 0;
    int i = 0, j = 0;
    int k = 0, l = 0;

    printf("\nMATRIZ MEDIA\n");

    for (i = 0; i < MAX; i++){
        for (j = 0; j < MAX; j++){
            media = media + mat1[i][j];
            if(j==MAX-1){
                mat2[k][l] = media/MAX;
                k++;
                l++;
                media = 0;
            }
            if(j != i)
                mat2[i][j] = 0;
        }
    }

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            printf("%.2f    ",  mat2[i][j]);
        }
        printf("\n");                                    
    }
}

void MaiorMenor (float mat1[MAX][MAX], float mat2[MAX][MAX]){
    float maior = -INFINITY, menor = INFINITY;

    printf("\nMATRIZ MAIOR MENOR\n");

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if(mat1[i][j] > maior)
                maior = mat1[i][j];
            if(mat1[i][j] < menor)
                menor = mat1[i][j];
        }
    }
    
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if(i%2 == 0)
                mat2[i][j] = maior;

            if(i%2 != 0)
                mat2[i][j] = menor;

            printf("%.2f    ", mat2[i][j]);
        }
        printf("\n");                                 
    }
    
}

void acimaMedia (float mat1[MAX][MAX], float mat2[MAX][MAX]){
    float media=0;

    printf("\nMATRIZ ACIMA DA MEDIA\n");

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            media = media + mat1[i][j];
        }
    }

    media = media / (MAX*MAX);
    
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if(mat1[i][j] > media)
                mat2[i][j] = mat1[i][j];
            else{
                mat2[i][j] = 0;
            } 
            printf("%.2f   ", mat2[i][j]);
        }
        printf("\n");
    }        
}

void ordenacao (float mat1[MAX][MAX], float mat2[MAX][MAX]){
    int i, j, k, l;
    float tmp;

    printf("\nMATRIZ ORDENADA\n");

        for (i = 0; i < MAX; i++) {
                for (j = 0; j < MAX; j++) {
                        mat2[i][j] = mat1[i][j];
                }
        }

        for (i = 0; i < MAX; i++) {
                for (j = 0; j < MAX; j++) {
                        tmp = mat2[i][j];
                        l = j + 1;
                        for (k = i; k < MAX; k++) {
                                while (l < MAX) {
                                        if (tmp > mat1[k][l]) {
                                                tmp = mat2[k][l];
                                                mat2[k][l] = mat2[i][j];
                                                mat2[i][j] = tmp;
                                        }
                                        l++;
                                }
                                l = 0;
                        }
                }
        }

        for (i = 0; i < MAX; i++) {
                for (j = 0; j < MAX; j++) {
                        printf("%.2f ", mat2[i][j]);
                }
                printf("\n");
        }
}


int main(){
    float mat1[MAX][MAX], mat2[MAX][MAX];

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            printf("Elemento linha %i coluna %i: ", i+1, j+1);
            scanf("%f", &mat1[i][j]);
        }
        printf("\n");  
    }

    printf("\nMATRIZ 1 ORIGINAL\n");

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            printf("%.2f  ", mat1[i][j]);
        }
        printf("\n");                                    
    }

    printf("\n--------------------------------------------\n");

    trasposta(mat1, mat2);
    diagonal(mat1, mat2);
    soma(mat1, mat2);
    media(mat1, mat2);
    MaiorMenor(mat1, mat2);
    acimaMedia(mat1, mat2);
    ordenacao(mat1, mat2);


}