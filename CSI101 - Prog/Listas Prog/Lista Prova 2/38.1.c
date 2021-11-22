// Um teatrocom 250 lugarestem os seguintes critérios de preço:

// 1 A entrada inteira custa R$ 75,00;
// 2 Pagam meia entrada pessoas com até 18 anos e pessoas com 65 anos ou mais;
// 3 Pessoas cujo nome completo contém o nome da personagem principal do espetáculo em cartaz, pagam somente R$30,00.

// a) Faça uma função que receba duas strings, nomeCompleto e nomePers, e retorne verdadeiro(valor 1),se nomePers aparece em nomeCompleto,ou retorne falso (valor 0), caso contrário.

// b) Faça uma função que leia do teclado a idade e o nome completo de um espectador e retorne o preço 
// que este deverá pagar. Esta função deverá receber como parâmetro o nome da personagem principal do espetáculoe 
// deverá chamar a função anterior para verificar se haverá desconto no ingresso.

// c) Faça um programa que leia do teclado o nome da personagem principal do espetáculo e o número de ingressos vendidos. 
// A segunda função deverá ser chamada para computar o valor pago por cada ingresso. O programa deverá imprimir o total arrecadado pela bilheteria do teatro.

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int checkNome(char nomePers[], char nomeCompleto[]){

    if (strstr(nomeCompleto, nomePers) != NULL)
        return 1;
    else
        return 0;

}

calculaPreco(char nomePers[], int ingVendidos){

    char nomeCompleto[20];
    int idade, check, c;
    float preco;   

    for (int i = 0; i < ingVendidos; i++){
        
        printf("\n");

        printf("Digite sua idade: ");
        scanf("%i", &idade);

        //Remove the \n from input stream
        while ( (c = getchar()) != '\n' && c != EOF );

        printf("Digite o seu nome completo: ");
        fgets(nomeCompleto, 20, stdin);

        //fgets reads in the newline char ('\n').
        nomeCompleto[strlen(nomeCompleto) - 1] = '\0';

        check = checkNome(nomePers, nomeCompleto);

        if(check == 1)
            preco = 30.00;       

        else if(idade == 18 || idade >= 65)
            preco = 37.50;

        else
            preco = 75.00;

        printf("\nO preco a pagar dessa pessoa e de %0.2f", preco);

        printf("\n");

    }
    
}

int main(){
    char nomePers[20];
    int ingVendidos;

    printf("Digite o nome do personagem principal: ");
    fgets(nomePers, 20, stdin);

    printf("Digite o numero de ingrecos vendidos: ");
    scanf("%i", &ingVendidos);

    //fgets reads in the newline char ('\n').
    nomePers[strlen(nomePers) - 1] = '\0';

    calculaPreco(nomePers, ingVendidos);

    return 0;

}