// Faça um programa para ler a quantidade de um total de 5 produtos que uma empresa tem em suas 7 lojas e imprimir em uma tabela:   
// a) o total de cada produto em toda a empresa    
// b) a loja que tem menos produtos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PRODUTOS 5
#define LOJAS 2


int main(){
    float inventario[PRODUTOS][LOJAS];
    float acumula;

    float valorMenor = INFINITY;
    int lojaMenor;

    for (int i = 0; i < LOJAS; i++){
        for (int j = 0; j < PRODUTOS; j++){
            printf("Digite a quantidade de produto %i na loja %i: ",j+1, i+1);
            scanf("%f", &inventario[j][i]);
        }

        printf("\n");
    }

    for (int i = 0; i < PRODUTOS; i++){
        for (int j = 0; j < LOJAS; j++){
            acumula = acumula + inventario[i][j];

            if(j == LOJAS - 1){
                printf("\nO total do produto %i em toda a empresa e: %f", i+1, acumula);
                acumula = 0;
            }
        }
    }

    printf("\n");

    for (int i = 0; i < LOJAS; i++){
        for (int j = 0; j < PRODUTOS; j++){
            acumula = acumula + inventario[i][j];

            if(j == LOJAS - 1){
                printf("\nO total de produto na loja %i: %f", i+1, acumula);

                if(acumula < valorMenor){
                    valorMenor = acumula;
                    lojaMenor = i;
                }
                acumula = 0;
            }
        }
    }
    printf("\n");
    printf("\nA loja com menor numero de produtos e a loja %i com %.2f produtor\n", lojaMenor, valorMenor);


    return 0;

}