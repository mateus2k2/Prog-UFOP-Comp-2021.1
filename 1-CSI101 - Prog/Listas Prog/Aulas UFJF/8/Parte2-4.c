// Faça um programa que leia uma matriz 6 x 3 e uma função que gere duas matrizes 3 x 3, a primeira com as 3 primeiras linhas e a segunda com as 3 linhas restantes. 
// Chame na função principal funções para imprimir as duas matrizes 3 x 3 geradas

#include <math.h>


void geral3Comeco(float mat[6][3]){
    float matComeco[3][3];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matComeco[i][j] = mat[i][j];
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%8.2f", matComeco[i][j]);
        }
        printf("\n");
    }
}



void geral3Final(float mat[6][3]){
    float matFim[3][3];
    int k = 0;

    for (int i = 3; i < 6; i++){
        for (int j = 0; j < 3; j++){
            matFim[k][j] = mat[i][j];
        }
        k++;
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%8.2f", matFim[i][j]);
        }
        printf("\n");
    }
}

int main(){
    float mat[6][3];

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            printf("Digite o elemento linha %i conluna %i: ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            printf("%8.2f", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    geral3Comeco(mat);
    printf("\n");
    geral3Final(mat);
    
}