//Entrada: 
//Objetivo: 
//Saida:

#include <assert.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*

*/

#define MAX 15

typedef struct{
    char nome[30];
    int codigo;
    float preco;
    float percentLucro;
}loja;


int main(int argc, char *argv[]){
    loja produtos[MAX];

    int maiorLucro = -INFINITY, menorLucro = INFINITY;
    int codigoMaior, codigoMenor;
    float lucroTotal = 0;
    
    int c;

    printf("\nLEITURA DE CADA PRODUTO\n");
    for (int i = 0; i < MAX; i++){

        printf("\nPRODUTO %i\n", i+1);

        printf("Digite o nome: ");
        gets(produtos[i].nome);

        printf("Digite o codigo: ");
        scanf("%i", &produtos[i].codigo);

        printf("Digite o preco: ");
        scanf("%f", &produtos[i].preco);

        printf("Digite o percentual de lucro: ");
        scanf("%f", &produtos[i].percentLucro);

        while ( (c = getchar()) != '\n' && c != EOF );

    }
    
    printf("\n---------------------------------------------\n");


    printf("\nRELATORIO DE CADA PRODUTO\n");
    for (int i = 0; i < MAX; i++){
        printf("\nPRODUTO %i\n", i+1);

        printf("\nCodigo: %i", produtos[i].codigo);
        printf("\nPreco: %f", produtos[i].preco);
        printf("\nPercentual de lucro: %f", produtos[i].percentLucro);

        printf("\nNome: ");
        puts(produtos[i].nome);

        if((produtos[i].percentLucro * produtos[i].preco) > maiorLucro){
            maiorLucro = produtos[i].percentLucro * produtos[i].preco;
            codigoMaior = produtos[i].codigo;
        }
        
        if((produtos[i].percentLucro * produtos[i].preco) < maiorLucro){
            menorLucro = produtos[i].percentLucro * produtos[i].preco;
            codigoMenor = produtos[i].codigo;
        }

        lucroTotal = lucroTotal + (produtos[i].percentLucro * produtos[i].preco);

    }

    printf("\n---------------------------------------------\n");


    printf("\nRELATORIO GERAL");
    printf("\nLucro total da loja com a venda de um exemplar de cada produto: %f", lucroTotal);
    printf("\nProduto com maior lucro tem codigo %i", codigoMaior);
    printf("\nProduto com menor lucro tem codigo %i", codigoMenor);


    return 0;
}