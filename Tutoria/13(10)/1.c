//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

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


typedef struct{
    char tipo[30];
    char marca[30];
    int quantidade;
    double preco;
}Produto;

Produto* aloca_vetor(int tam);
void desaloca_matriz(Produto *produtos);

Produto *ler_dados(Produto *produtos, int quantidade);
double calcula_valor(Produto *produtos, int quantidade);
void imprime(Produto *produtos, int quantidade, double total);


int main(int argc, char *argv[ ]){
    Produto *produtos;
    double total;
    int quantidade;

    printf("Digite a quantiade de produtos: "); scanf("%i", &quantidade);
    while ((getchar()) != '\n');
    printf("\n");

    produtos = aloca_vetor(quantidade);
    produtos = ler_dados(produtos, quantidade);
    total = calcula_valor(produtos,quantidade);
    imprime(produtos, quantidade, total);
    desaloca_matriz(produtos);

    printf("\n");

    return 0;
}

void imprime(Produto *produtos, int quantidade, double total){
    
    printf("PRINT");
    for (int i = 0; i < quantidade; i++){
        printf("\nTipo: %s", produtos[i].tipo); 
        printf("\nMarca: %s", produtos[i].marca); 
        printf("\nQuantidade: %i", produtos[i].quantidade); 
        printf("\nPreco: %lf", produtos[i].preco); 

        printf("\n");
    }
    printf("\n");
    printf("Total: %lf", total);    
}

double calcula_valor(Produto *produtos, int quantidade){
    double total = 0;

    for (int i = 0; i < quantidade; i++){
        total = total + (produtos[i].quantidade)*(produtos[i].preco);
    }

    return total;
}

Produto *ler_dados(Produto *produtos, int quantidade){

    printf("LER\n");
    for (int i = 0; i < quantidade; i++){
        printf("Tipo: "); fgets(produtos[i].tipo, 30, stdin);
        produtos[i].tipo[strlen(produtos[i].tipo)-1] = '\0';

        printf("Marca: "); fgets(produtos[i].marca, 30, stdin);
        produtos[i].marca[strlen(produtos[i].marca)-1] = '\0';

        printf("Quantidade: "); scanf("%i", &produtos[i].quantidade);
        printf("Preco: "); scanf("%lf", &produtos[i].preco);
        while ((getchar()) != '\n');

        printf("\n");
    }    

    return produtos;

}

Produto* aloca_vetor(int tam){
    Produto* vet;
    vet = malloc(tam * sizeof(int));
    return vet;
}

void desaloca_matriz(Produto *produtos){
    free(produtos);
}