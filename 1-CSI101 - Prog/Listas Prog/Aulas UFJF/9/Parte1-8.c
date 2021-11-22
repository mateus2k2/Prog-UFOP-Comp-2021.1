// Faça um programa que receba três nomes (de no máximo 100 caracteres cada) e as idades das respectivas pessoas em um vetor de estruturas. 
// Após o recebimento, listar os três nomes armazenados neste vetor por ordem crescente de idades.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    char nome[100];
    int idade;
}pessoa;

int main(){
    pessoa grupo[3];
    int idadeMenor = INFINITY, indiceMenor;
    int c;

    for (int i = 0; i < 3; i++){
        printf("\n");

        printf("Digite a idade da pessoa %i: ", i+1);
        scanf("%i", &grupo[i].idade);

        //Remove the \n from input stream
        while ( (c = getchar()) != '\n' && c != EOF );

        printf("Digite o nome da pessoa %i: ", i+1);
        gets(grupo[i].nome);

        if(grupo[i].idade < idadeMenor){
            idadeMenor = grupo[i].idade;
            indiceMenor = i;
        }
    }

    printf("\n");
    printf("O nome da pessoa com menor idade (%i) e ", idadeMenor);
    puts(grupo[indiceMenor].nome);

}
