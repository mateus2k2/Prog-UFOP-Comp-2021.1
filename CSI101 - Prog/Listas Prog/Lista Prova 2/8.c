// Escreva uma função que leia uma sequência de valores e calcule a média aritmética dos valores lidos, a quantidade de valores positivos, 
// a quantidade de valores negativos e o percentual de valores negativos e positivos. Mostre os resultados. O número que encerrará a leitura será zero. A função deve retornar a quantidade de números lidos.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void calculo(){

    int i = 1, cont = 0; 
    int valor = 1;
    int media = 0, positivos = 0, negativos= 0;

    while (i == 1){
        printf("Digite o valor: ");
        scanf("%i", &valor);

        if(valor == 0)
            break;

        media = media + valor;
        cont++;

        if(valor > 0)
            positivos++;
        else
            negativos++;


    }
    
    media = media / cont;
    printf("\nA media dos valores e de %i", media);
    
    printf("\n");

    printf("\nA quantidade de negativos e de %i", negativos);
    printf("\nO percentual de negativos e de %i", (negativos / cont)*100 );

    printf("\n");

    printf("\nA quantidade de positivos e de %i", positivos);
    printf("\nA percentual de positivos e de %i", (positivos / cont)*100 );


}

int main(){

    calculo();
    return 0;
}