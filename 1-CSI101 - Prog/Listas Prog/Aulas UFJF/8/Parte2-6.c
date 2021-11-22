// Faça um programa que leia 3 vetores reais de dimensão 10 e uma função que gere uma matriz (10 x 3) onde cada coluna é dada por um destes vetores.

void fazMatriz(float vet1[], int tam1, float vet2[], int tam2, float vet3[], int tam3){
    float mat[10][3];

    for (int i = 0; i < 10; i++){
        mat[i][0] = vet1[i];
    }
    for (int i = 0; i < 10; i++){
        mat[i][1] = vet2[i];
    }
    for (int i = 0; i < 10; i++){
        mat[i][2] = vet3[i];
    }

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 3; j++){
            printf("%8.2f", mat[i][j]);
        }
        printf("\n");
    }    

}

int main(){
    float vet1[10], vet2[10], vet3[10];

    printf("Digite o primeiro vetor de 10 valores: ");
    for (int i = 0; i < 10; i++){
        scanf("%f", &vet1[i]);
    }

    printf("\n");

    printf("Digite o segundo vetor de 10 valores: ");
    for (int i = 0; i < 10; i++){
        scanf("%f", &vet2[i]);
    }

    printf("\n");

    printf("Digite o terceiro vetor de 10 valores: ");
    for (int i = 0; i < 10; i++){
        scanf("%f", &vet3[i]);
    }

    printf("\n");

    fazMatriz(vet1, 10, vet2, 10, vet3, 10);

    return 0;    

}