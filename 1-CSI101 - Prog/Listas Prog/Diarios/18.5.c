/*
Você trabalha em uma transportadora e precisa fazer um programa que calcula e mostra o peso da carga de um caminhão transformada para quilos, o valor da carga do caminhão,
o valor do imposto, sendo que o imposto é calculado sobre o valor da carga do caminhão e depende do estado que a carga veio, e o valor total transportado pelo caminhão, preço da carga mais impostos. 
Para fazer estes cálculos ler as seguintes informações:

A) O código do estado que a carga saiu, que é um número de 1 e 5;

B) O peso em toneladas do caminhão;

C) O código da carga que é um número de 10 a 40. 

O imposto e o preço por quilo é calculado com as tabelas:

Código do estado	  Imposto
1	                    40%
2                   	30%
3                   	20%
4	                    10%
5	                    5%
 

Código da carga	Preço por quilo
10 a 20	            1000
21 a 30	            2500
31 a 40	            340
*/


#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int codEstado, codCarga, n;
    float  pesoToneladas, pesoKg, valorCarga, valorImposto, impostoCobrado, valorTotal;

    n = 1;

    printf("\n---------------ENTRADAS----------------\n");

    printf("Digite o codigo do estado de saida: ");
    scanf("%i", &codEstado);
    
    printf("Digite peso em toneladas da carga: ");
    scanf("%f", &pesoToneladas);

    printf("Digite o codigo da carga: ");
    scanf("%i", &codCarga);

    printf("---------------SAIDA---------------------");

    pesoKg = pesoToneladas * 1000;
    printf("\nPeso em Killograma: %0.2f", pesoKg);

    if(n == 1){
        if(codCarga >= 10 && codCarga <= 20)
            valorCarga = pesoKg * 1000;
        if(codCarga >= 21 && codCarga <= 30)
            valorCarga = pesoKg * 2500;
        if(codCarga >= 31 && codCarga <= 40)
            valorCarga = pesoKg * 340;
    }
    else{
        printf("\nCodigo da carga e imvalido");
    }

    printf("\nValor da carga sem imposto e: %0.2f", valorCarga);

    switch (codEstado)
    {
    case 1: valorImposto = 40; 
        break;
    case 2: valorImposto = 30; 
        break;
    case 3: valorImposto = 20; 
        break;
    case 4: valorImposto = 10; 
        break;
    case 5: valorImposto = 5; 
        break;
    default: printf("\nCodigo do estado e invalido");
        break;
    }
    
    printf("\nA porcentagem de imposto pago e de %0.2f", valorImposto);

    impostoCobrado = valorCarga * (valorImposto/100);

    printf("\nO valor do imposto cobrado e de %0.2f", impostoCobrado);

    valorTotal = valorCarga + impostoCobrado;

    printf("\nO valor toal da carga do caminhao e de %0.2f", valorTotal);

    return 0;


}