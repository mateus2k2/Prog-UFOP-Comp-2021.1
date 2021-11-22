// Em uma república de estudantes, após cada compra de supermercado, os estudantes anotam na nota fiscal seu nome (Artur, Bruno, Carlos ou Diego) 
// para identificar itens pessoais ou a palavra "Todos" para identificar bens comuns cujo custo deve ser dividido. 
// Faça um programa que leia do teclado os seguintes dados de cada item da nota fiscal: quantidade do produto, preço unitário e identificação de quem o adquiriu. 
// O programa deverá imprimir o valor total que cada estudante deverá pagar.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void leitor(float valorCadaUm[], int tamvalorCadaUms, int numeroComprar){
    char identificador[10];
    int ret1, ret2, ret3, ret4, c;
    float quantidadeProduto, precoUnitario, precoTotal;

    printf("\n");

    for (int i = 0; i < numeroComprar; i++){

        printf("\n");

        //Remove the \n from input stream
        while ( (c = getchar()) != '\n' && c != EOF );   

        printf("Digite identificador (Artur, Bruno, Carlos ou Diego): ");
        fgets(identificador, 10, stdin);
    
        printf("Digite a quantidade do produto: ");
        scanf("%f", &quantidadeProduto);

        printf("Digite o preco unitario: ");
        scanf("%f", &precoUnitario);

        precoTotal = quantidadeProduto * precoUnitario;


        ret1 = strncmp(identificador, "Artur", 5);
        ret2 = strncmp(identificador, "Bruno", 5);
        ret3 = strncmp(identificador, "Carlos", 6);
        ret4 = strncmp(identificador, "Diego", 5);

        if(ret1 == 0){
            valorCadaUm[1] = valorCadaUm[1] + precoTotal;
        }
        else if(ret2 == 0){
                valorCadaUm[2] = valorCadaUm[2] + precoTotal;
             }
        else if(ret3 == 0){
                valorCadaUm[3] = valorCadaUm[3] + precoTotal;
             }
        else if(ret4 == 0){
                valorCadaUm[4] = valorCadaUm[4] + precoTotal;
             }
        else
            valorCadaUm[0] = valorCadaUm[0] + precoTotal;
    }
}

void print(float valorCadaUm[], int tamValorCadaUm){


    printf("\nO valor a ser pago individualmente por Artur e de %0.2f", valorCadaUm[1]);
    printf("\nO valor a ser pago individualmente por Bruno e de %0.2f", valorCadaUm[2]);
    printf("\nO valor a ser pago individualmente por Carlos e de %0.2f", valorCadaUm[3]);
    printf("\nO valor a ser pago individualmente por Diego e de %0.2f", valorCadaUm[4]);

    printf("\n");

    printf("\nO O valor a ser pago em conjunto e de %0.2f", valorCadaUm[0]);

}

int main(){
    float valorCadaUm[5] = {0.0};
    int numeroComprar;

    printf("Digite a quantidade de comprar a serem imputadas: ");
    scanf("%i", &numeroComprar);

    leitor(valorCadaUm, 5, numeroComprar);
    print(valorCadaUm, 5);

    return 0;
}