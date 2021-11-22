// Faça um programa que leia os dados de N ingressos (sendo N definido com a diretiva define).  
// As informações que deverão ser lidas de cada ingresso são: preço, local e atração. Ao final, informe os eventos de ingresso mais barato e mais caro.

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

int main(){
    float maior = -INFINITY, menor = INFINITY;
    int indiceMaior, indiceMenor, c;
    ingreco grupo[N];

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

        if(grupo[i].preco > maior){
            maior = grupo[i].preco;
            indiceMaior = i;
        }
        
        if(grupo[i].preco < menor){
            menor = grupo[i].preco;
            indiceMenor = i;
        }
    }

    printf("\nO ingresso de preco %.2f local %s e atrcao %s foi o de maior valor", grupo[indiceMaior].preco, grupo[indiceMaior].local, grupo[indiceMaior].atracao );
    printf("\nO ingresso de preco %.2f local %s e atrcao %s foi o de menor valor", grupo[indiceMenor].preco, grupo[indiceMenor].local, grupo[indiceMenor].atracao );
    

}
