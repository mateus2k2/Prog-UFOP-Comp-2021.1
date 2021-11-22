// Elabore um programa em C que l^e o valor das variaveis a, b, c e d do tipo float e, em seguida, calcula a seguir:

// O resultado deve ser impresso no formato do exemplo abaixo (o texto destacado em azul indica o que foi digitado pelo usuario):

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

    float a, b, c, d;
    float x;

    printf("Digite as valores de a, b, c, d:\n");

    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);

    x = (a * a * a) * ((b+c)/d);  

    printf("\n");

    printf("a = %.0f, b = %.0f, c = %.0f, d = %.0f\n", a, b, c, d);
    printf("x = %.0f\n", x);




    return 0;
}