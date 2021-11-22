// Faça um programa que leia uma sequência de números positivos. 
// Calcule a quantidade de números pares e ímpares, a média de valores pares e a média geral dos números lidos. O número que encerrará a leitura será zero.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void calculo(){

    int i = 1, cont = 0; 
    int valor = 1;
    int mediaPares = 0, mediaGeral = 0, pares = 0, impares= 0;

    while (i == 1){
        printf("Digite o valor: ");
        scanf("%i", &valor);

        if(valor == 0)
            break;

        mediaGeral = mediaGeral + valor;
        cont++;

        if(valor % 2 == 0){
            pares++;
            mediaPares = mediaPares + valor;
        }
            
        else
            impares++;


    }
    
    printf("\nA media geral dos valores e de %i", mediaGeral / cont);
    
    printf("\n");

    printf("\nA quantidade de pares e de %i", pares);
    printf("\nA media dos pares e de %i", mediaPares/pares );

    printf("\n");

    printf("\nA quantidade de impares e de %i", impares);

}

int main(){

    calculo();
    return 0;
}