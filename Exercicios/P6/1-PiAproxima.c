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

double calculaPI(int termos){
    int i = 3, cont = 0;
    double pi; 
    double S = 0;

    while(cont != termos){
        if(cont%2 == 0)
            S = S + 1.0/pow(i, 3);
        else
            S = S - 1.0/pow(i, 3);

        i = i + 2;
        cont++;
    }
    pi = pow((1-S)*32.0, 1.0/3.0);

    return pi;
}

int main(int argc, char *argv[ ]){

    int termos;
    double pi;

    printf("Digite o numero de termos de pi: "); scanf("%i", &termos);

    printf("pi = %lf", calculaPI(termos));

    return 0;
}