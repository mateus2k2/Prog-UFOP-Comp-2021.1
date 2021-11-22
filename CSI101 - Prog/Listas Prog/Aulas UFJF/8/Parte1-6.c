// Implemente uma função que receba por parâmetro uma matriz quadrada de números reais (dimensão máxima 100) e um inteiro N que indica quantas linhas/colunas desta matriz serão consideradas. 
// Essa função deverá calcular e imprimir, separadamente, a soma dos elementos da diagonal principal e da diagonal secundária desta matriz.
// Faça, também, um programa principal que declare e preencha as variáveis necessárias para utilizar a função desenvolvida. 
// Note que é necessário ler o valor N antes da leitura da matriz e preencher apenas a quantidade de linhas/colunas que o usuário desejar

// 1 1 1 1 1 1
// 1 1 1 1 1 1
// 1 1 1 1 1 1
// 1 1 1 1 1 1
// 1 1 1 1 1 1
// 1 1 1 1 1 1

void somaDiagonal(int mat[100][100], int linhas, int colunas, int N){
    int somaPricipal = 0;
    int somaSegundaria = 0;
    int k = 0, m = 0;

    m = N-1;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(i == j){
                somaPricipal = somaPricipal + mat[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(i == k && j == m){
                somaSegundaria = somaSegundaria + mat[i][j];
                k++;
                m--;
            }
        }
    }

    printf("\nSoma Diagonal principal: %i", somaPricipal);
    printf("\nSoma Diagonal segundaria: %i", somaSegundaria);


    
}


int main(){
    int N, mat[100][100];

    printf("\n");        

    printf("Digite o numero de colunas e linhas que serao utilizadas: ");
    scanf("%i", &N);

    printf("\n");        

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("Digite o elemento linha %i coluna %i: ", i+1, j+1);
            scanf("%i", &mat[i][j]);
        }
        printf("\n");        
    }
    
    printf("\n");        


    somaDiagonal(mat, 100, 100, N);

    return 0;
        
}