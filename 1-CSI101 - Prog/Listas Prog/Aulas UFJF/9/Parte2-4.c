// Utilize a estrutura definida abaixo nas questões a seguir: 

// typedef struct{
//     int codigo;
//     char nome[100];
//     int vendas[12];
// }Produto;

// a) Faça uma função que identifique o produto mais vendido em um ano. Esta função deve receber dois parâmetros: 
// um vetor com a lista de produtos (estrutura acima) e o seu tamanho. A função deve retornar a posição (índice) 
// na lista do produto mais vendido no ano. Para calcular a quantidade vendida de um produto, considere que o campo 
// vendas armazena a quantidade de vendas do produto em cada mês do ano. Por exemplo, a posição 0 armazena a quantidade 
// vendida em janeiro, a posição 3 armazena a quantidade de vendas em abril, etc.

// b) Faça um programa principal que declare um vetor de produtos, mas considere que a loja possui capacidade para no máximo 100 produtos. 
// O programa deve fazer a leitura de todos os produtos disponíveis através do teclado e depois chamar a função criada anteriormente para identificar 
// o produto mais vendido. Ao final, o programa deve imprimir o nome e o código do produto mais vendido.

#define MAX 2

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int codigo;
    char nome[100];
    int vendas[12];
}produto;

int verificaMaisVendido(produto prod[], int tamanho){
    int maior = -INFINITY, total = 0, indice;

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < 12; j++){
            total = total + prod[i].vendas[j];
        }
        if(total > maior){
            maior = total;
            indice = i;
            total = 0;
        }
    }

    return indice;
    
}

int main(){
    produto prod[MAX];
    int indice, total = 0, c; 

    for (int i = 0; i < MAX; i++){
        printf("\nPRODUTO %i\n", i+1);

        printf("Digite o codigo: ");
        scanf("%i", &prod[i].codigo);

        //Remove the \n from input stream
        while ( (c = getchar()) != '\n' && c != EOF );

        printf("Digite o nome: ");
        gets(prod[i].nome);

        printf("Digite o numero de vendas no mes em sequencia: ");
        scanf("%i %i %i %i %i %i %i %i %i %i %i %i", &prod[i].vendas[0], &prod[i].vendas[1], &prod[i].vendas[2], &prod[i].vendas[3], &prod[i].vendas[4], &prod[i].vendas[5], &prod[i].vendas[6], &prod[i].vendas[7], &prod[i].vendas[8], &prod[i].vendas[9], &prod[i].vendas[10], &prod[i].vendas[11]);

        // for (int j = 0; j < 12; j++){
        //     printf("Digite o numero de vendas no mes %i: ", j+1);
        //     scanf("%i", &prod[i].vendas[j]);
        // }   
    }

    indice = verificaMaisVendido(prod, MAX);

    for (int i = 0; i < 12; i++){
        total = total + prod[indice].vendas[i];
    }    

    printf("\nO produto %s -- Codigo %i -- Vendas %i. Foi o mais vendido\n", prod[indice].nome, prod[indice].codigo, total);
    

}

//34 234 323 324 324 54 534 43 54 675 54 35
//645 653 634 24 64 2 35 34 342 532 234 34 