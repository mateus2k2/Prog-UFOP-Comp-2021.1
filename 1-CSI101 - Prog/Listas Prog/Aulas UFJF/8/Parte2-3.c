// Faça um programa que leia uma matriz quadrada de dimensão MAX, uma função que encontre o maior valor desta matriz e uma função que encontre o menor valor. 
// Imprima os valores encontrados na função principal.
#include <math.h>

#define MAX 3

void leMatriz(float mat[MAX][MAX]){

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            printf("Digite o elemento linha %i e coluna %i: ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }
}

float encontraMaior(float mat[MAX][MAX]){
    float maior = -INFINITY;

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if(mat[i][j] > maior)
                maior = mat[i][j];                 
        }
    }

    return maior;
}

float encontraMenor(float mat[MAX][MAX]){
    float menor = INFINITY;

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if(mat[i][j] < menor)
                menor = mat[i][j];                 
        }
    }

    return menor;

}

int main(){
    float mat[MAX][MAX];
    float maior, menor;

    printf("\nEscreva os valores da matriz\n");
    leMatriz(mat);

    maior = encontraMaior(mat);
    menor = encontraMenor(mat);

    printf("\nO maior numero da matriz e %.2f", maior);
    printf("\nO menor numero da matriz e %.2f", menor);

    return 0;

}