//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <assert.h> <ctype.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int calculaRaizes(float a, float  b, float  c, float *x1, float *x2);

int main(int argc, char *argv[ ]){

    float a, b, c;
    float x1, x2;
    int ret;

    printf("Digite os valores A, B, C: "); scanf("%f %f %f", &a, &b, &c);

    ret = calculaRaizes(a, b, c, &x1, &x2);

    if(ret == 0)
        printf("\nErro. Delta Negativo");

    else{
        printf("\nX1: %.2f", x1);
        printf("\nX2: %.2f", x2);
    }
    
    return 0;
}

int calculaRaizes(float a, float  b, float  c, float *x1, float *x2){

    float delta = (b*b) - (4 * a * c);

    if(delta < 0)
        return 0;
    
    else{
        *x1 = (-b + sqrt(delta)) / 2 * a;
        *x2 = (-b - sqrt(delta)) / 2 * a;
        return 1;
    }
}
