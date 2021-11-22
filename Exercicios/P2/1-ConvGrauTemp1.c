//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

////conversão de kelvin para fahrenheit está errada, não existe uma opção para finalizar o loop de chamadas recursivas.

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

void menu();

void EscolhaTemp();
void EscolhaAngulo();

void orgGrau();
void orgRad();

void orgCelsius();
void orgKelvin();
void orgFahrenheit();


int main(int argc, char *argv[ ]){

    menu();

    return 0;
}

void menu(){
    
    int escolha;

    printf("\n");
    printf("\n### CONVERSOR DE UNIDADES ###\n");

    printf("\n1) Angulo \n2) Temperatura\n");
    printf("\nDigite uma opcao: "); scanf("%i", &escolha);

    switch (escolha){
    case 1: EscolhaAngulo();
        break;
    
    case 2: EscolhaTemp();
        break;

    default: printf("Opcao Invalida \nErro...");
        break;
    }

}

void EscolhaAngulo(){
    int escolha;

    printf("\nQual a unidade de Origem? \n");

    printf("\n1) Graus \n2) Radianos\n");
    printf("\nSelecione uma opcao: "); scanf("%i", &escolha);

    switch (escolha){
    case 1: orgGrau();
        break;
    case 2: orgRad();
        break;
    default: printf("Opcao Invalida \nErro...");
        break;
    }
}

void orgGrau(){

    float valorGrau;

    printf("\nDigite o valor em grau: "); scanf("%f", &valorGrau);
    printf("Valor em radianos: %.2f", valorGrau * (3.1415/180));

    menu();

}

void orgRad(){

    float valorRad;

    printf("\nDigite o valor em radianos: "); scanf("%f", &valorRad);
    printf("Valor em graus: %.2f", valorRad * (180/3.1415));

    menu();

}

void EscolhaTemp(){
    int escolha;

    printf("\nQual a unidade de Origem? \n");

    printf("\n1) Celsius \n2) Fahrenheit \n3) Kelvin\n");
    printf("\nSelecione uma opcao: "); scanf("%i", &escolha);
    printf("\n");

    switch (escolha){
    case 1: orgCelsius();
        break;
    case 2: orgFahrenheit();
        break;
    case 3: orgKelvin();
        break;
    default: printf("Opcao Invalida \nErro...");
        break;
    }
}

void orgCelsius(){

    float valorCelsius;

    printf("Digite o valor em Celsius: "); scanf("%f", &valorCelsius);

    if(valorCelsius < -273)
        printf("Valor menor que -273 C (zero absoluto) nao permitido.");

    else{
        printf("Valor em Fahrenheit: %.2f", (valorCelsius * (9.0/5.0)) + 32);
        printf("\nValor em Kelvin: %.2f", valorCelsius + 273.15);
    }

    menu();
}

void orgFahrenheit(){

    float valorFahrenhei;

    printf("Digite o valor em Fahrenhei: "); scanf("%f", &valorFahrenhei);

    if(valorFahrenhei < -459)
        printf("Valor menor que -459 F (zero absoluto) nao permitido.");

    else{   
        printf("Valor em Celsius: %.2f", (valorFahrenhei - 32) * 5.0/9.0);
        printf("\nValor em Kelvin: %.2f", ((valorFahrenhei - 32) * 5.0/9.0) + 273.15);
    }

    menu();
}

void orgKelvin(){

    float valorKelvin;

    printf("Digite o valor em Kelvin: "); scanf("%f", &valorKelvin);

    if(valorKelvin < 0)
        printf("Valor menor que 0 K (zero absoluto) nao permitido.");
    
    else{
        printf("Valor em Fahrenheit: %.2f", (valorKelvin  - 273,15) * (9.0/5.0) + 32);
        printf("\nValor em Celsius: %.2f", valorKelvin - 273.15);
    }

    menu();
}