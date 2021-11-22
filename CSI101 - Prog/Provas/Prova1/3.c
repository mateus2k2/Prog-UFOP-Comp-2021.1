//Matrícula 20.2.8093
//Nome: Mateus Filipe Moreira Silva

/*
Você trabalha em uma empresa e o seu gerente diz para você desenvolver um programa para controle do gasto com energia consumida em vários domicílios diferente. 
O seu programa deverá receber a quantidade de quilowatts gasto por cada consumidor e o tipo de consumidor sendo , 1 - comercial, 2 - residencial ou 3 - industrial. O programa deve calcular e mostrar:

a) o valor de cada quilowatt, sabe-se que o quilowatt custa um quarto do salário mínimo, o seu programa deverá ler o valor do salário mínimo;

b) o valor a ser pago pelo consumidor (conta final mais acréscimo). O acréscimo encontra-se na tabela abaixo:

Tipo	% de acréscimo sobre o valor gasto
1	10
2	15
3	20
c) o faturamento geral da empresa;

d) a quantidade de consumidores que irão pagar entre R$1.000,00 e R$1.500,00.

O programa deve finalizar quando o valor entrado para a quantidade de quilowatts for igual a zero. 
*/

//


#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int kwConsumido, salarioMinimo, custoKw, valorPago;
    int faturameno = 0, quantidade1500 = 0;
    int  cont = 1, tipoConsumidor;

    printf("Digite o valor do salario minimo: ");
    scanf("%i", &salarioMinimo);

    custoKw = salarioMinimo / 4;

    printf("O custo de cada kW de acordo com o salario minimo inserio e %i\n", custoKw);

    //Apenas para deixar mais organizado
    printf("\n-----------------------------------------------------\n");

    while(cont == 1){

        //Entrada
        printf("Digite a quantidade de kw consumidos: ");
        scanf("%i", &kwConsumido);

        //Condicao para parar o programa
        if(kwConsumido == 0)
            break;

        //Entrada
        printf("Digite o tipo de consumidor 1 - comercial, 2 - residencial ou 3 - industrial: ");
        scanf("%i", &tipoConsumidor);

        //Calcula o custo para o cunsumidor 
        if(tipoConsumidor == 1 || tipoConsumidor == 2 || tipoConsumidor == 3 ){
            if(tipoConsumidor == 1)
                valorPago = (kwConsumido * custoKw) + (kwConsumido * 0.1);
            if(tipoConsumidor == 2)
                valorPago = (kwConsumido * custoKw) + (kwConsumido * 0.15);
            if(tipoConsumidor == 3)
                valorPago = (kwConsumido * custoKw) + (kwConsumido * 0.2);
        }
        //Caso o valor do tipoConsumidor inserido nao seja valido o programa sai do loop  
        else{
            printf("\nValor do tipo do comsumidor invalido");
            break;
        }

        //Escreve o custo do consumidor autal
        printf("\nO valor a ser pago por esse cliente e de %i\n", valorPago);

        //Soma de todos valres a serem pagos pelos clientes
        faturameno = faturameno + valorPago; 

        //Verifica a quantidade de consumidores que irao pagar entre R$1.000,00 e R$1.500,00
        if(valorPago >= 1000 && valorPago <= 1500)
            quantidade1500 = quantidade1500 + 1;

        //Apenas para deixar mais organizado
        printf("\n-----------------------------------------------------\n");
    }

    //Escreve a quantidade de consumidores que irao pagar entre R$1.000,00 e R$1.500,00
    //Escreve o faturamento total da empresa
    printf("\nO faturamento geral da empresa e de %i", faturameno);
    printf("\nA quantidade de consumidores que irao pagar entre R$1.000,00 e R$1.500,00 e %i", quantidade1500);

    return 0;

}