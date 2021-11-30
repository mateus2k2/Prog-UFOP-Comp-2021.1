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

typedef struct{
    int numerador;
    int denominador;
}Racional;

int compara(Racional r1, Racional r2){

    int mdc1, mdc2;

    for (int i = 1; i <= r1.numerador && i <= r1.denominador; i++){
        if(r1.numerador % i == 0 && r1.denominador % i == 0)
            mdc1 = i;
    }

    for (int i = 1; i <= r2.numerador && i <= r2.denominador; i++){
        if(r2.numerador % i == 0 && r2.denominador % i == 0)
            mdc2 = i;
    }

    printf("r1: %i/%i   %i\n", r1.numerador/mdc1, r1.denominador/mdc1, mdc1);
    printf("r2: %i/%i   %i\n", r2.numerador/mdc2, r2.denominador/mdc2, mdc2);


    if(r1.numerador/mdc1 == r2.numerador/mdc2 && r1.denominador/mdc1 == r2.denominador/mdc2)
        return 1;

    return 0;
    
}


int main(int argc, char *argv[ ]){
    Racional r1, r2;
    int retorno;

    printf("Digite numerador e denominador de r1: "); scanf("%i %i", &r1.numerador, &r1.denominador);
    printf("Digite numerador e denominador de r2: "); scanf("%i %i", &r2.numerador, &r2.denominador);

    retorno = compara(r1, r2);

    if(retorno == 1)
        printf("Os dois numero sao iquais\n");
    else
        printf("Os dois numero sao diferentes\n");


    return 0;
}