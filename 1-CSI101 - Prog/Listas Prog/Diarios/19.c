#include <stdlib.h>
#include <stdio.h>

/*
NOME: Mateus Filipe Moreira Silva
Matriculo: 20.2.8093
*/

/*
OBJETIVOS DO PROGRAMA
Recebe o o valor do (float) peso em KilloGrama do teclado e converte para grama (pesoGrama) 
Checa se pesoGrama e maior que 100000 se for entao escreve Voce precisa reducir o seu peso se nao escreve Voce nao precisa reducir o seu peso
*/

int main(){
    
    float peso, pesoGrama;

    printf("Digite o seu peso em kg: ");
    scanf("%f", &peso);
    
    pesoGrama = peso * 1000;

    if(pesoGrama > 100000)
        printf("Voce precisa reducir o seu peso");
    else
        printf("Voce nao precisa reducir o seu peso");
    
    return 0;

}