//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <stdio.h>
#include <stdlib.h>

int verifica(int **mat, int tam){

    int l, c, soma, total;

    soma = 0;
    for(l = 0; l < tam; l++){ // soma da diagonal principal
        soma += mat[l][l];
    }
    //printf("Diag. principal: %d\n", soma);
    total = soma; // salva a soma da diagonal principal na variável total

    soma = 0;
    for(l = 0; l < tam; l++){ // soma da diagonal secundária
        soma += mat[l][tam - 1 - l];
    }
    //printf("Diag. secundaria: %d\n", soma);

    if(total != soma)
        //printf("Diagonal secundaria eh diferente!\n");

    for(l = 0; l < tam; l++){ // soma da linhas
        soma = 0;
        for(c = 0; c < tam; c++)
            soma += mat[l][c];
        //printf("Linha %d: %d\n", l, soma);

        if(total != soma){
            //printf("Linha %d eh diferente\n", l);
            return 1;
        }
    }

    for(c = 0; c < tam; c++){ // soma das colunas são iguais
        soma = 0;
        for(l = 0; l < tam; l++)
            soma += mat[l][c];
        //printf("Coluna %d: %d\n", c, soma);

        if(total != soma){
            //printf("Coluna %d eh diferente\n", c);
            return 1;
        }
    }
    return 0;
}

int main(){
    int tam = 4;
    int **mat;

    printf("Digite o valor de n: "); scanf("%i", &tam);

    mat = malloc(tam * sizeof(int*));
        for (int i = 0; i < tam; i++)
            mat[i] = malloc(tam * sizeof(int*)); 
    
    printf("\nDigite os valores da matriz n x n: \n");
    for (int i = 0; i < tam; i++){
        printf("Linha %i: ", i+1);
        for (int j = 0; j < tam; j++){
            scanf("%i", &mat[i][j]);
        }        
    }
    
    printf("\n");

    if(verifica(mat, tam) == 0)
        printf("\nHe um quadrado magico!!!!\n");

    for (int i = 0; i < tam; i++)
        free(mat[i]);
    free(mat);

    return 0;
}