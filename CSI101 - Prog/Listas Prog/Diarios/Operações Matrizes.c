// Você está trabalhando com ciência de dados e precisa fazer algumas operações com matrizes. 
//Para isto você solicitará ao usuário que digite a ordem n de uma matriz n x n com números inteiros. 
//A ordem da matriz deverá ser maior do que 4. O seu programa deverá executar as trocas pedidas abaixo e mostrar cada uma das matrizes resultantes:

// a)	A linha 1 com a linha n;
// b)	A linha 4 com a linha n-1;
// c)	A diagonal principal com a diagonal secundária;
// d)	A linha 3 com a coluna n.

/*
NOME: Mateus Filipe Moreira Silva
Matricula:
*/

#include <stdlib.h>
#include <stdio.h>


int main(){
    int i = 0, j = 0;
    int tamN;
    int tmp;

    //Obter o tamanho da matriz
    printf("Digite o tamanho da matriz (maior que 4): ");
    scanf("%i", &tamN);

    printf("\n");

    int mat[tamN][tamN];
    int matBKP[tamN][tamN];

    //Preencher a matriz
    for (i = 0; i < tamN; i++){
        for (j = 0; j < tamN; j++){
            printf("Digite o elemento linha %i coluna %i: ", i, j);
            scanf("%i", &mat[i][j]);
        }
        printf("\n");        
    }

    //Cópia a matriz mat para a matBKP
    for (i = 0; i < tamN; i++){
        for (j = 0; j < tamN; j++){
            matBKP[i][j] = mat[i][j];
        }        
    }

    //print da matriz original 
    printf("\nA matriz original e:\n");
    for (i = 0; i < tamN; i++){
        for (j = 0; j < tamN; j++){
            printf("%8.2i ",mat[i][j]);
        }
        printf("\n");
    }
 
    //Realiza as operações e o mesamo padrão se repete
    printf("\n------------------------------------------------------------------");
    printf("\nA linha 1 com a linha n (n-1)");
    for (i = 0; i < tamN; i++){
        
        tmp = mat[1][i];

        mat[1][i] = mat[tamN-1][i];
        mat[tamN-1][i] = tmp;
    }

    printf("\n");

    //print da nova matriz
    for (i = 0; i < tamN; i++){
        for (j = 0; j < tamN; j++){
            printf("%8.2i ",mat[i][j]);
        }
        printf("\n");
    }

    //Copia a matriz matBKP para a matriz mat 
    for (i = 0; i < tamN; i++){
        for (j = 0; j < tamN; j++){
            mat[i][j] = matBKP[i][j];
        }        
    }

    printf("\n------------------------------------------------------------------");
    printf("\nA linha 4 com a linha n-1");
    for (i = 0; i < tamN; i++){
        tmp = mat[4][i];

        mat[4][i] = mat[tamN-1][i];
        mat[tamN-1][i] = tmp;
    }

    printf("\n");

    for (i = 0; i < tamN; i++){
        for (j = 0; j < tamN; j++){
            printf("%8.2i ",mat[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < tamN; i++){
        for (j = 0; j < tamN; j++){
            mat[i][j] = matBKP[i][j];
        }        
    }

    printf("\n------------------------------------------------------------------");
    printf("\nA diagonal principal com a diagonal secundaria");
    for (i = 0; i < tamN; i++){
        for (j = 0; j < tamN; j++){  
            tmp = mat[i][i];
            mat[i][i] = mat[i][tamN - i - 1];
            mat[i][tamN - i - 1] = tmp;     
        }
    }

    printf("\n");

    for (i = 0; i < tamN; i++){
        for (j = 0; j < tamN; j++){
            printf("%8.2i ",mat[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < tamN; i++){
        for (j = 0; j < tamN; j++){
            mat[i][j] = matBKP[i][j];
        }        
    }

    printf("\n------------------------------------------------------------------");
    printf("\nA linha 3 com a coluna n (n-1)");
    for (i = 0; i < tamN; i++){
        tmp = mat[3][i];
        mat[3][i] = mat[i][tamN-1];
        mat[i][tamN-1] = tmp;
    }
    mat[tamN-1][tamN-1]=matBKP[tamN/2][tamN-1];

    printf("\n");

    for (i = 0; i < tamN; i++){
        for (j = 0; j < tamN; j++){
            printf("%8.2i ",mat[i][j]);
        }
        printf("\n");
    }

    return 0;

}