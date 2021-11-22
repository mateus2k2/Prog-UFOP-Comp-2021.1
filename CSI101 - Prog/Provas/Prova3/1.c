//Entrada: 
//Objetivo: 
//Saida:

#include <assert.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*

*/

int main(int argc, char *argv[ ]){
    float valorCarro, percentualAumento = 0;
    int quantidadeParcelas;

    printf("Digite o valor do carro: ");
    scanf("%f", &valorCarro);

    printf("\n");

    printf("Digite a quantidade de parcelas: ");
    scanf("%i", &quantidadeParcelas);

    while (1){

    
        switch (quantidadeParcelas){
        case 1: percentualAumento = 0.8; 
            break;
        case 6: percentualAumento = 1.04; 
            break;
        case 12: percentualAumento = 1.07; 
            break;
        case 18: percentualAumento = 1.1; 
            break;
        case 24: percentualAumento = 1.13; 
            break;
        case 30: percentualAumento = 1.16; 
            break;
        case 36: percentualAumento = 1.21; 
            break;
        case 42: percentualAumento = 1.22; 
            break;
        case 48: percentualAumento = 1.24; 
            break;
        case 54: percentualAumento = 1.28; 
            break;
        case 60: percentualAumento = 1.30; 
            break;
        default:    printf("Quantidade de parcelas invalidas. Tente Novamente: ");
                    scanf("%i", &quantidadeParcelas);
            break;
        }

        if(percentualAumento != 0)
            break;
    }
    
    printf("\nVALOR DO CARRO %.2f", valorCarro);
    printf("\nVALOR DO FINAL DO CARRO %.2f", valorCarro*percentualAumento);
    printf("\nQUANTIDADE DE PARCELAS %i", quantidadeParcelas);
    printf("\nVALOR DE CADA PARCELA %.2f", (valorCarro*percentualAumento)/quantidadeParcelas);



    return 0;
}