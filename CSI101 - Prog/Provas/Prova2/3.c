// Você trabalha em uma empresa que está fazendo um programa para uma empresa de crédito. 
// Você ficou responsável pela parte do programa utilizado para calcular o valor da dívida e 
// mostrar uma tabela com o valor da dívida, valor dos juros, quantidade de parcelas e valor da parcela.

// Os juros e quantidade de parcelas são apresentados na tabela a seguir:

// Quantidade de parcelas	% de juros sobre o valor inicial da dívida
// 2	                    5
// 4	                    15
// 7	                    20
// 10		                25
// 13	                    30


// Exemplo de saída:

// Valor da dívida	Valor dos juros	    Quantidade de parcelas	    Valor da parcela
// R$ 10.500,00 	R$500,00	        2	                        R$5.250,00
// R$ 11.550,00	    R$1050,00   	    3	                        R$3.850,00
 

//Matrícula 20.2.8093
//Nome: Mateus Filipe Moreira Silva

/*
Entrdas: valor da divida e o numero de parcelas

Saidas: valor os juros e valores das parcelas

Objetivo: Calcular o valor dos juros e valor das parcelas. Dependendo do valor das parcelas escolhido a percentagem do juros varia, oque e calculado e mostrado no fim 

OBS: 3 parcelas são 15 de juros? Não ficou claro. Considerei os intervalor
OBS: Exemplo Errado? 5% de 10500 = 525 e 15% de 11550 e 1732. 

*/


#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    float divida, juros = -1;
    int parcela;

    printf("Digite o valor da sua divida: ");
    scanf("%f", &divida);
    
    printf("\nQuantidade de parcelas	Percentagem de juros sobre o valor inicial da dívida");
    printf("\n      2                                        5");
    printf("\n      4                                        15");
    printf("\n      7                                        20");
    printf("\n      10                                       25");
    printf("\n      13                                       30");
    printf("\nEscolha: ");
    scanf("%i", &parcela);

    if(parcela > 0 && parcela <= 2)
        juros = 0.05;
    else if(parcela > 2 && parcela <= 4)
        juros = 0.15;
    else if(parcela > 4 && parcela <= 7)
        juros = 0.20;
    else if(parcela > 7 && parcela <= 10)
        juros = 0.25;
    else if(parcela > 10 && parcela <= 13)
        juros = 0.30;
    else
        printf("\nNumero de parcelas invalido");

    printf("\n");

    if(juros != -1){
    printf("\nValor da divida      Valor dos juros     Quantidade de parcelas      Valor da parcela");
    printf("\n%.2f                 %.2f                %i                          %.2f", divida, (divida*juros), parcela, divida/parcela);
    }

    return 0;

}