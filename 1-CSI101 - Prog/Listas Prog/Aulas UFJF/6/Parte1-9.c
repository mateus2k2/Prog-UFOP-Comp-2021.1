/*
Elabore duas funções que façam respectivamente
a união e a interseção de duas sequências de
inteiros. Cada função deverá receber 4 parâmetros:
três vetores de valores inteiros, (A, B e C) e um
inteiro representando o tamanho dos dois primeiros
vetores (tamAB). Assuma que o tamanho do vetor C
é apropriado para cada operação.
Desenvolva um programa que crie quatro vetores,
sendo v1, v2 e vInter, de tamanho 10, e vUniao,
de tamanho 20. O programa deve preencher os
vetores v1 e v2 com valores do teclado e chamar as
funções acima. Após as chamadas de função, o
programa deve imprimir vInter e vUniao
*/


void intercecao(int vetAA[], int tamAA, int vetBB[], int tamBB, int vetCCC[], int tamCCC ){

    int i=0, ii=0, iii=0;

    for (i = 0; i < 10; i++){
        
        for (ii = 0; ii < 10; ii++){
            
            if(vetAA[iii] == vetBB[ii]){
                vetCCC[iii] = vetAA[iii];
                printf("\nO vetor de intercecao de A com B de indice %i e %i", i, vetCCC[iii]);    
            }
        }
        
        iii = iii + 1;
    }

}

void uniao(int vetAA[], int tamAA, int vetBB[], int tamBB, int vetCC[], int tamCC ){

    int i=0, ii=0;

    for (i = 0; i < 10; i++){
        vetCC[i] = vetAA[i];
    }
    for (i = 10; i <= 19; i++){
        vetCC[i] = vetBB[ii];
        ii = ii + 1;
    }
}

int main(){
    int i=0, ii=0;

    int vInter[10] = {0};
    int vUniao[10] = {0};

    int vetA[10]; 
    int vetB[10];

    for (i = 0; i < 10; i++){
        printf("Digite os valores para preencher o vetor A");
        scanf("%i", &vetA[i]);
    }

    for (i = 0; i < 10; i++){
        printf("Digite os valores para preencher o vetor B");
        scanf("%i", &vetB[i]);
    }

    intercecao(vetA, 10, vetB, 10, vInter, 10);
    uniao(vetA, 10, vetB, 10, vUniao, 10);

    // for (i = 0; i < 10; i++){
    //     printf("\nO vetor de intercecao de A com B de indice %i e %i", i, vInter[i]);
    // }

    printf("\n-------------------------------\n");

    for (i = 0; i < 20; i++){
        printf("\nO vetor de uniao de A com B de indice %i e %i", i, vUniao[i]);
    }
    
    return 0;
}