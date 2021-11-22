#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define MAX 1

typedef struct{
    char nome[100];
    char avenidaRua[100];
    char numero[100];
    char bairro[100];
    char complemento[100];
    char CEP[100];
    char cidade[100];
    char UF[20];
    char telefone1[100];
    char telefone2[100];
}contato;



int main(){
    contato grupo[MAX];

    for (int i = 0; i < MAX; i++){
        printf("\nDIGITE OS INFORMACOES DA PESSOA %i\n", i+1);

        printf("Nome: ");
        gets(grupo[i].nome);

        printf("Avenida/Rua: ");
        gets(grupo[i].avenidaRua);

        printf("Numero da casa: ");
        gets(grupo[i].numero);

        printf("Bairro: ");
        gets(grupo[i].bairro);

        printf("Complemento: ");
        gets(grupo[i].complemento);

        printf("CEP: ");
        gets(grupo[i].CEP);

        printf("Cidade: ");
        gets(grupo[i].cidade);

        printf("UF: ");
        gets(grupo[i].UF);

        printf("Telefone 1: ");
        gets(grupo[i].telefone1);

        printf("Telefone 2: ");
        gets(grupo[i].telefone2);
    }

    printf("\n-----------------------------\n");

    for (int i = 0; i < MAX; i++){

        printf("\nPRINT DAS INFORMACOES PESSOA %i\n", i+1);

        printf("\nNOME: %s", grupo[i].nome);
        printf("\Avenida/Rua: %s", grupo[i].avenidaRua);
        printf("\Numero: %s", grupo[i].numero);
        printf("\nBairro: %s", grupo[i].bairro);
        printf("\nComplemento: %s", grupo[i].complemento);
        printf("\nCEP: %s", grupo[i].CEP);
        printf("\nCidade: %s", grupo[i].cidade);
        printf("\nUF: %s", grupo[i].UF);
        printf("\nTelefone 1: %s", grupo[i].telefone1);
        printf("\nTelefone 2: %s", grupo[i].telefone2);


    }
    
    return 0;
}