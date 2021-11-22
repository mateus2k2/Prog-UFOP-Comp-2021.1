// Faça um programa (função principal) para leitura, via teclado, dos dados de um atleta. Os dados a serem guardados na estrutura atleta são os seguintes: 
// nome, medidas (estrutura definida no exercício 2), esporte praticado e idade. Ao final, imprima estas informações na tela

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

typedef struct{
    float peso;
    float altura;
}medida;

typedef struct{
    char nome[20];
    medida medidaAtleta;
    char esporte[20];
    int idade;
}atleta;

int main(){
    atleta atleta1;
    int c;

    printf("Digite o seu nome: ");
    gets(atleta1.nome);

    printf("Digite a sua idade: ");
    scanf("%i", &atleta1.idade);

    //Remove the \n from input stream
    while ( (c = getchar()) != '\n' && c != EOF );

    printf("Digite o seu esporte: ");
    gets(atleta1.esporte);

    printf("Digite seu peso: ");
    scanf("%f", &atleta1.medidaAtleta.peso);

    printf("Digite sua altura: ");
    scanf("%f", &atleta1.medidaAtleta.altura);

    printf("\n");

    printf("NOME ATLETA: ");
    puts(atleta1.nome);

    printf("\nIDADE ATLETA %i", atleta1.idade);

    printf("\nESPORTE ATLETA: ");
    puts(atleta1.esporte);
    
    printf("\nPESO ATLETA %f", atleta1.medidaAtleta.peso);

    printf("\nALTURA ATLETA %f", atleta1.medidaAtleta.altura);





    



}