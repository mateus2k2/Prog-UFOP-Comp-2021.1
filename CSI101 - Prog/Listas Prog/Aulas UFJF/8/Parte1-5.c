// Faça um programa que crie uma matriz NxM e inicialize-a com valores digitados pelo usuário. 
// Seu programa deve calcular e imprimir a soma dos valores de cada linha e a média dos valores de cada coluna

// 1 1 1 1
// 1 1 1 1
// 1 1 1 1

#define linha 3
#define coluna 4

int main(){
    int mat[linha][coluna];
    int somaLinhas = 0; 
    float mediaColunas = 0;
    int i, j;

    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("Digite o elemento linha %i coluna %i: ", i+1, j+1);
            scanf("%i", &mat[i][j]);
        }
        printf("\n");
    }


    for (i = 0; i < coluna; i++){
        for (j = 0; j < linha; j++){
            mediaColunas = mediaColunas + mat[j][i];

                if(j == linha-1){
                printf("\nA media da coluna %i e %.2f", i+1, mediaColunas/linha);
                mediaColunas = 0;
            }
        }
    }

    printf("\n");


    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            somaLinhas = somaLinhas + mat[i][j];

            if(j == coluna - 1){
                printf("\nA soma da linha %i e %i", i+1, somaLinhas);
                somaLinhas = 0;
            }            
        }
    }
    
    return 0;

}


