//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

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

float grauRad(float valorGrau){
    return valorGrau * (3.14/180);
}

float RadGrau(float valorRad){
    return valorRad * (180/3.14);
}

float CtF(valorC){
    return (valorC * (9.0/5.0)) + 32;
}

float CtK(valorC){
    return valorC + 273,15;
}

float KtF(valorK){
    return (valorK  - 273,15) * (9.0/5.0) + 32;
}

float KtC(valorK){
    return valorK - 273,15;
}

float FtC(valorF){
    return (valorF - 32) * 5.0/9.0;
}

float FtK(valorF){
    return (valorF - 32) * (5.0/9.0) + 273.15;
}

int main(int argc, char *argv[]){

    int escolha, escolhaA, escolhaT;
    float valor;

    //Menu
    printf("\n### CONVERSOR DE UNIDADES ###\n");

    printf("\n1) Angulo \n2) Temperatura\n");
    printf("\nDigite uma opcao: "); scanf("%i", &escolha);

    //Escolha da conversão de angulos ou temperatura 
    switch (escolha){
    case 1: escolhaA = 1;
        break;
    
    case 2: escolhaT = 1;
        break;

    default: printf("Opcao Invalida \nErro...");
        break;
    }

    //Conversão entre ângulos
    if(escolhaA == 1){

        //Menu
        printf("\nQual a unidade de Origem? \n");

        printf("\n1) Graus \n2) Radianos\n");
        printf("\nSelecione uma opcao: "); scanf("%i", &escolha);

        //Escolha converter de grau para radianos ou radianos para grau
        //Chamando as funções para cada conversão
        switch (escolha){
        case 1: 
            printf("\nDigite o valor em grau: "); scanf("%f", &valor);
            printf("Valor em radianos: %.2f", grauRad(valor));
            break;

        case 2: 
            printf("\nDigite o valor em radianos: "); scanf("%f", &valor);
            printf("Valor em graus: %.2f", RadGrau(valor));
            break;

        default: printf("Erro... \nOpcao Invalida");
            break;
        }
    }

    //Conversão entre temperaturas
    if(escolhaT == 1){

        //Menu
        printf("\nQual a unidade de Origem? \n");

        printf("\n1) Celsius \n2) Fahrenheit \n3) Kelvin\n");
        printf("\nSelecione uma opcao: "); scanf("%i", &escolha);
        printf("\n");

        //Escolha entre converter celsius para kelvin e todos as outras possibilidades de conversões entre temperatura
        //Chamando as funções para cada conversão
        switch (escolha){
        case 1: 
            printf("Digite o valor em Celsius: "); scanf("%f", &valor);

            if(valor < -273)
                printf("Valor menor que -273 C (zero absoluto) nao permitido.");

            else{
                printf("Valor em Fahrenheit: %.2f", CtF(valor));
                printf("\nValor em Kelvin: %.2f", CtK(valor));
            }
            break;

        case 2:
            printf("Digite o valor em Fahrenhei: "); scanf("%f", &valor);

            if(valor < -459)
                printf("Valor menor que -459 F (zero absoluto) nao permitido.");

            else{   
                printf("Valor em Celsius: %.2f", FtC(valor));
                printf("\nValor em Kelvin: %.2f", FtK(valor));
            }      
            break;

        case 3: 
            printf("Digite o valor em Kelvin: "); scanf("%f", &valor);

            if(valor < 0)
                printf("Valor menor que 0 K (zero absoluto) nao permitido.");
            
            else{
                printf("Valor em Fahrenheit: %.2f", KtF(valor));
                printf("\nValor em Celsius: %.2f", CtF(valor));
            }
            break;

        default: printf("Erro... \nOpcao Invalida");
            break;
        }
    }
    return 0;

}