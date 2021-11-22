//Faça um programa que leia uma matriz 7 x 5 e imprima a terceira coluna.

int main(){
    int mat[4][3];

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){
            printf("Digite o elemtno Linha %i coluna %i: ", i, j);
            scanf("%i", &mat[i][j]);
        }        
        printf("\n");
    }

    for (int i = 0; i <4; i++){
        printf("\nA coluna 3 linha %i e %i", i, mat[i][2]);
    }

}