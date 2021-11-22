// Faça   um   programa   que   armazene   informações   de restaurantes.  Cada  restaurante  é  identificado  pelo  nome,  o tipo  de  
// comida  (brasileira,  chinesa,  francesa,  italiana, japonesa, etc.) e uma nota para a cozinha (entre 0 e 5). 
// O programa deverá ler todas as informações e imprimir a lista de todos  os  restaurantes  e,  ao  final,  o  tipo  de  cozinha  do restaurante com maior nota.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    char nome[100];
    char tipoComida[100];
    int nota;
}restaurantes;

int main(){
    int QuantidadeRestalrante, maiorNota = -INFINITY, indiceMaior;
    restaurantes praca[10000];
    int c;

    printf("Digite a quantidade de restaltantes a serem analizados: ");
    scanf("%i", &QuantidadeRestalrante);

    //Remove the \n from input stream
    while ( (c = getchar()) != '\n' && c != EOF );

    printf("\n");

    for (int i = 0; i < QuantidadeRestalrante; i++){
        printf("\n");
        
        printf("Digite o nome do restalrante: ");
        gets(praca[i].nome);
        
        printf("Digite o tipo de comida do restalrante: ");
        gets(praca[i].tipoComida);

        printf("Digite a nota do restalrante: ");
        scanf("%i", &praca[i].nota);

        //Remove the \n from input stream
        while ( (c = getchar()) != '\n' && c != EOF );

        if(praca[i].nota > maiorNota){
            maiorNota = praca[i].nota;
            indiceMaior = i;
        }
    }

    for (int i = 0; i < QuantidadeRestalrante; i++){
        printf("\n-----------------------");
        printf("\nRESTALRANTE %i\n", i+1);

        printf("Nome: ");
        puts(praca[i].nome);
        
        printf("Tipo de comida: ");
        puts(praca[i].tipoComida);

        printf("Nota: %i", praca[i].nome);
    }

    printf("\n-----------------------\n");

    printf("\nO restaltante com maior nota teve nota: %i\n", praca[indiceMaior].nota);
    
    printf("Tipo de comida: ");
    puts(praca[indiceMaior].tipoComida);
    
    printf("Nome: ");
    puts(praca[indiceMaior].nome);
    
}
