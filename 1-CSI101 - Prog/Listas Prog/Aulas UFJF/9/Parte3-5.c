// Faça  um  programa  que  permita  comparar  o  preço  de  um eletrodoméstico  em  diferentes  lojas  da  cidade.  Para  cada  loja,  
// os seguintes campos devem ser armazenados: nome da loja, endereço (estrutura  com  rua,  número  e  bairro),  telefone  e  preço  do eletrodoméstico.  
// Utilize  funções  para:  

// (1)  ler  do  teclado  todas  as informações de todas as lojas; 
// (2) ler do teclado o nome de uma loja já cadastrada, localizar e imprimir suas informações; 
// (3) calcular, imprimir e  retornar  a  média  dos  preços  cadastrados;  
// (4)  imprimir  nome  e telefone das lojas em que o preço está abaixo da média (use a função anterior para obter o valor da média); 
// (5) imprimir todas as informações da  loja  que  tem  o  menor  preço.  
//Faça  um  programa  principal  que apresente um menu com as opções acima


#define MAX 10

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    char rua[100];
    int numero;
    char bairro[100];

}endereco;

typedef struct{
    char nome[100];
    endereco enderecoLoja;
    int telefone;
    float preco;
}loja;


void procuraLoja(loja grupo[], int tamanho){
    float novoPreco;
    int c;
    char loja[100];

    printf("\n");
    printf("DIGITE A LOJA A SER PROCURADA: ");
    gets(loja);

    for (int i = 0; i < tamanho; i++){
        if(strcmp(loja, grupo[i].nome)==0){
            printf("\nNome: %s", grupo[i].nome);
            printf("\nEndereco --- Bairro: %s || Rua: %s || Numero: %i", grupo[i].enderecoLoja.bairro, grupo[i].enderecoLoja.rua, grupo[i].enderecoLoja.numero);
            printf("\nTelefone: %i", grupo[i].telefone);
            printf("\nPreco: %.2f", grupo[i].preco);                                
        }
    }

} 

void lerInfo(loja grupo[], int tamanho){

    int c;

    for (int i = 0; i < tamanho; i++){
        printf("\nLOJA NUMERO %i\n", i+1);

        printf("Digite o nome: ");
        gets(grupo[i].nome);

        printf("Digite a rua: ");
        gets(grupo[i].enderecoLoja.rua);
        printf("Digite a bairro: ");
        gets(grupo[i].enderecoLoja.bairro);
        printf("Digite a numero: ");
        scanf("%i", &grupo[i].enderecoLoja.numero);

        printf("Digite o telefone de comunicacao: ");
        scanf("%i", &grupo[i].telefone);

        printf("Digite o preco do produto: ");
        scanf("%f", &grupo[i].preco);

        //Remove the \n from input stream
        while ( (c = getchar()) != '\n' && c != EOF );

    }
    
} 

float mediaPrecos(loja grupo[], int tamanho){
    float media = 0;

    for (int i = 0; i < tamanho; i++){
        media = media + grupo[i].preco;
        if(tamanho == i-1)
            media = media/tamanho;
    }

    printf("\n");
    printf("\nMEDIA DOS PRODUTOS E %f", media);
    return media;    
}

void abaixoMedia(loja grupo[], int tamanho, float media){
    
    printf("\n");
    printf("\nLOJAS ABAIXO MEDIA");

    for (int i = 0; i < tamanho; i++){
        if(grupo[i].preco < media){
            printf("\nLoja abaixo da media --- Nome: %s || Telegone: %i", grupo[i].nome, grupo[i].telefone);
        }
    }
}

void menorPreco(loja grupo[], int tamanho){
    float valorMenor = INFINITY;
    int indiceMenor;
    
    printf("\n");
    printf("\nLOJAS MENOR PRECO");

    for (int i = 0; i < tamanho; i++){
        if(grupo[i].preco < valorMenor){
            valorMenor = grupo[i].preco;
            indiceMenor = i;
        }
    }    

    printf("\nNome: %s", grupo[indiceMenor].nome);
    printf("\nEndereco --- Bairro: %s || Rua: %s || Numero: %i", grupo[indiceMenor].enderecoLoja.bairro, grupo[indiceMenor].enderecoLoja.rua, grupo[indiceMenor].enderecoLoja.numero);
    printf("\nTelefone: %i", grupo[indiceMenor].telefone);
    printf("\nPreco: %.2f", grupo[indiceMenor].preco);
}

int main(){
    loja grupo[MAX];
    float media;

    lerInfo(grupo, MAX);

    procuraLoja(grupo, MAX);

    media = mediaPrecos(grupo, MAX);

    abaixoMedia(grupo, MAX, media);

    menorPreco(grupo, MAX);

    return 0;

}
