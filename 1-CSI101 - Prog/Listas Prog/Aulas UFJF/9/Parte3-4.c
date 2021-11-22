// Utilizando a estrutura definida no exercício anterior. Faça uma função que receba como parâmetro um vetor de ingressos e o nome de uma atração. 
// A função deve localizar a atração no vetor, ler do teclado o novo preço do ingresso e atualizar o preço da atração. 
// Faça também uma função que receba como parâmetro um único ingresso e imprima suas  informações.  
// Modifique  o  programa  principal  para  atualizar  o preço das cinco primeiras atrações e imprimir os dados de todos os ingressos, chamando obrigatoriamente as funções anteriores.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define N 2

typedef struct{
    float preco;
    char local[100];
    char atracao[100];
}ingreco;

void atualiza(ingreco grupo[], int tamanho, char atracaoAtualizar[]){
    float novoPreco;
    int c;

    for (int i = 0; i < 5; i++){
        if(strcmp(atracaoAtualizar, grupo[i].atracao)==0){
            printf("Digite o novo preco do ingreso de atraacao %s: ", atracaoAtualizar);
            scanf("%f", &novoPreco);
            grupo[i].preco = novoPreco;
        }
    }

    //Remove the \n from input stream
    while ( (c = getchar()) != '\n' && c != EOF );
}

void imprime(ingreco grupo[], int indice){
    printf("\nO preco do evento e %.2f --- Local %s ----Atracao %s", grupo[indice].preco, grupo[indice].local, grupo[indice].atracao);
}

int main(){
    ingreco grupo[N];
    char atracaoAtualizar[100];
    int c;

    for (int i = 0; i < N; i++){
        printf("\nINFORMACOES INGRECO %i\n", i+1);

        printf("Preco: ");
        scanf("%f", &grupo[i].preco);

        //Remove the \n from input stream
        while ( (c = getchar()) != '\n' && c != EOF );

        printf("Local: ");
        gets(grupo[i].local);

        printf("Atracao: ");
        gets(grupo[i].atracao);
    }

    printf("Digite o nome da atracao para modificar o preco: ");
    gets(atracaoAtualizar);

    printf("\n");

    atualiza(grupo, N, atracaoAtualizar);
    
    for (int i = 0; i < N; i++)        
        imprime(grupo, i);

}