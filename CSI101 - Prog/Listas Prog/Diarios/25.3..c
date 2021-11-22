// Você trabalha em uma empresa de desenvolvimento de software de controle de estoque. Sua empresa foi contratada para fazer um programa de controle para uma loja de presentes que tem apenas um vendedor, 
// que é o próprio dono, e comercializa 15 tipos diferentes de produtos. O dono faz uma retirada mensal de R$3.550,00, acrescido de 3% do valor total de suas vendas. 
// O valor unitário dos objetos deve ser informado e armazenado em um vetor; a quantidade vendida de cada peça deve ficar em outro vetor, mas na mesma posição. 
// Você deverá então criar um programa que receberá os preços e as quantidades vendidas e armazenar nos respectivos vetores (ambos com tamanho igual a 15). 

// Então o programa deverá determinar e mostrar:

// a) Deverá ser emitido um relatório contendo: quantidade vendida, valor unitário e valor total de cada objeto. Ao final deverá ser mostrado o valor geral das vendas e o valor da comissão que será paga ao vendedor; e

// b) O valor do objeto que vendeu menos e sua posição no vetor ( não se preocupe com empates).


#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int CodProdutos[15], quantidadeVendida[15], indiceMenor;
    float valorTotal = 0, ValorUni[15];
    float valorMenor = INFINITY;

    printf("\n");

    for (int i = 0; i < 15; i++){
        printf("Digite o valor do produto %i: ", i+1);
        scanf("%f", &ValorUni[i]);

        printf("Digite a quantidade vendida do produto %i: ", i+1);
        scanf("%i", &quantidadeVendida[i]);

        printf("\n");
    }

        printf("\n");

    printf("%*s |        %*s      | %*s    | %*s\n", -3, "PRODUTO", -10, "VALOR UNITARIO", 10, "QUANTIDADE VENDIDA", 10, "TOTAL VENDIDO");
    printf("%*c     |             %*c     | %*c            | %*c\n", -3, ' ', -10, ' ', 10, ' ', 10, ' ');
    
    for (int i = 0; i < 15; ++i) {
        printf("%-3i     |             %-10.2f     | %10i            | %10.2f\n", i+1, ValorUni[i], quantidadeVendida[i], ValorUni[i]*quantidadeVendida[i]);
    }

    printf("-----------------------------------------------------------------------------------------");

    for (int i = 0; i < 15; i++){
        valorTotal = valorTotal + (ValorUni[i] * quantidadeVendida[i]);

        if(ValorUni[i] * quantidadeVendida[i] < valorMenor){
            valorMenor = ValorUni[i] * quantidadeVendida[i];
            indiceMenor = i;
        }
    }

    printf("\n");

    printf("\nVALOR TOTAL VENDIDO =========== %.2f", valorTotal);
    printf("\nVALOR PRODUTO MENOS VENDIDO === %.2f = (INDICE %i) = (PRODUTO %i)", valorMenor, indiceMenor, indiceMenor+1);
    printf("\nCOMISAO DO VENDEDOS =========== %.2f", 3550+(valorTotal*0.03));

    printf("\n");
    

return 0;

}
    
    



   