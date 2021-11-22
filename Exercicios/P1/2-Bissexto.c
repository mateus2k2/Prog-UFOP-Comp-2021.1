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


int main(int argc, char *argv[]){

    int ano;

    printf("Digite a ano: ");
    scanf("%i", &ano);

    if((ano%4 == 0 && ano%100 != 0) || (ano%100 == 0 && ano%400 == 0)) 
        printf("Ano eh bissexto.");
    else
        printf("Ano nao eh bissexto");

    return 0;
}