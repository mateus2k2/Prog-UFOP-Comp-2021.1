// Faça uma função para calcular a multiplicação de uma matriz 3 x 4 por um escalar. Faça também uma função capaz de imprimir esta matriz. Ao final, 
// desenvolva a função principal onde será criada e lida uma matriz 3 x 4. A função principal deverá chamar as duas funções criadas anteriormente.


#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void multiplica(int mat[3][4]){
    int i, j, escalar;

    printf("Digite o escalar: ");
    scanf("%i", &escalar);
    
    for (i = 0; i < 3; i++){
        for (j = 0; i < 4; i++){
            mat[i][j] = mat[i][j] * escalar;
        }
        
    }
}

void imprime(int mat[3][4]){
    int i, j;

     for (i = 0; i < 3; i++){
        for (j = 0; i < 4; i++){
            printf("O novo elemetno linha %i coluna %i e %i", i, j, mat[i][j]);
        }   
    }
}


int main(){
    int i = 0, j = 0;
    int mat[3][4];

    for (i = 0; i < 3; i++){
        for (j = 0; i < 4; i++){
            printf("Digite o elemento linha %i coluno %i", i, j);
            scanf("%i", &mat[i][j]);
        }
        
    }

    multiplica(mat);
    implime(mat);
    

}