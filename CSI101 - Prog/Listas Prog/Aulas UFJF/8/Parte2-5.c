// Faça um programa que leia uma matriz de caracteres 5 x 10 e uma função que conte quantas letras “a” aparecem na matriz.
// Você poderá fazer a leitura letra a letra ou considerar que cada linha da matriz é uma string

#include <stdio.h>

#define N   5
#define M   10

int main(){
    char mat[N][M];
    int cont = 0;
    int n = 0;

    printf("\nDigite 5 (Numero de linhas da matriz) frases de no maximo 10 caracteres cada (numero de colunas da matriz)\n");
    while(n < N && fgets( mat[n], sizeof(*mat), stdin) != NULL ) 
        ++n;

    for (int i = 0; i < N; i++ ){ 
        for (int j = 0; j < M; j++){
            if(mat[i][j] == 'a'){
                cont++;
            }
        }
    }

    printf("\nNumero de letras a na matriz e: %i\n", cont-3);

    return 0;
}