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


int main(int argc, char *argv[ ]){
    int idade;
    float ingresso;

    printf("Digite idade: "); scanf("%i", &idade);
    printf("Digite ingresso: "); scanf("%f", &ingresso);

    if(idade < 18){
        if(idade < 5)
            ingresso = 0;
        else
            ingresso = ingresso/2;
    }
    else{
        if(idade > 70)
            ingresso = ingresso/2;
    }
    printf("ingresso: %f", ingresso);
    return 0;


    return 0;
}