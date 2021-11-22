// Faça uma função para manipulação de matrizes quadradas NxN com o seguinte “Menu”:

// Escolha uma opção de cálculo para matrizes:      
// 1) Soma      
// 2) Diferença      
// 3) Transposta       
// 4) Produto      
// 5) Sair      
// Opção:__

// Na opção (3) o usuário só precisa fornecer uma matriz, nas opções(1), (2) e (4) o usuário deve fornecer duas matrizes. O resultado deve apenas ser impresso.

#include <stdio.h>

void soma(){
    float mat1[2][2], mat2[2][2];

    printf("\n-----------------------------------------------------------------\n");

    printf("\nDigite o valor da primeira matriz: \n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("Digite a linha %i coluna %i: ", i+1,j+1);
            scanf("%f", &mat1[i][j]);
        }
    }

    printf("\n");        


    printf("Digite o valor da segunda matriz: \n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("Digite a linha %i coluna %i: ", i+1,j+1);
            scanf("%f", &mat2[i][j]);
        }
    }   

    printf("\n");        


    printf("A soma da matriz e: \n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("%8.2f", mat1[i][j] + mat2[i][j]);
        }
        printf("\n");
    }

    menu();

}

void diferenca(){
    float mat1[2][2], mat2[2][2];

    printf("\n-----------------------------------------------------------------\n");

    printf("\nDigite o valor da primeira matriz: \n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("Digite a linha %i coluna %i: ", i+1,j+1);
            scanf("%f", &mat1[i][j]);
        }
    }

    printf("\n");        
      

    printf("Digite o valor da segunda matriz: \n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("Digite a linha %i coluna %i: ", i+1,j+1);
            scanf("%f", &mat2[i][j]);
        }
    }   

    printf("\n");        


    printf("A diferenca da matriz e: \n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("%8.2f", mat1[i][j] - mat2[i][j]);
        }
        printf("\n");
    }
    menu();
}

void transposta(){
    float mat[10][10], transposta[10][10]; 
    int linhas, colunas;

    printf("\n-----------------------------------------------------------------\n");

    printf("Entre numero de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);

    printf("\nEntre com os elementos da matriz:\n");
    for (int i = 0; i < linhas; ++i)
        for (int j = 0; j < colunas; ++j) {
            printf("entre com o elemento linha %i conluna %i: ", i + 1, j + 1);
            scanf("%f", &mat[i][j]);
    }

    printf("\nMatriz entrada: \n");
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%8.2f", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < linhas; ++i)
        for (int j = 0; j < colunas; ++j) {
        transposta[j][i] = mat[i][j];
    }

    printf("\nA matriz transposta e:\n");
    for (int i = 0; i < colunas; i++){
        for (int j = 0; j < linhas; j++){
            printf("%8.2f", transposta[i][j]);
        }
        printf("\n");
    
    }

    menu();

}

void produto(){
    float mat1[2][2], mat2[2][2], res[2][2];
    int i, j, k;

    printf("\n-----------------------------------------------------------------\n");

    printf("\nDigite o valor da primeira matriz: \n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("Digite a linha %i coluna %i: ", i+1,j+1);
            scanf("%f", &mat1[i][j]);
        }
    }

    printf("\n");        
      

    printf("Digite o valor da segunda matriz: \n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("Digite a linha %i coluna %i: ", i+1,j+1);
            scanf("%f", &mat2[i][j]);
        }
    }   

    printf("\n");        

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            res[i][j] = 0;
            for (k = 0; k < 2; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }

    printf("\nA matriz multiplicada e:\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("%8.2f", res[i][j]);
        }
        printf("\n");
    }

    menu();
}

int menu(){
    int escolha;

    printf("\n-----------------------------------------------------------------\n");

    printf("\nEscolha uma opcao de calculo para matrizes: ");
    printf("\n1) Soma");
    printf("\n2) Diferenca");
    printf("\n3) Transposta");
    printf("\n4) Produto");
    printf("\n5) Sair");
    printf("\nOpcao: ");
    scanf("%i", &escolha);
    
    while(1){
        switch(escolha){
        case 1: soma();
            break;
        case 2: diferenca();
            break;
        case 3: transposta();
            break;
        case 4: produto();
            break;
        case 5: return 0;
            break;
        default: printf("\nOpcao nao definida, tente outra: ");
                 printf("\nOpcao: ");
                 scanf("%i", &escolha);               
                 break;
        }
    }

    printf("\n-----------------------------------------------------------------\n");

}

int main(){

    menu();
    return 0;
}
