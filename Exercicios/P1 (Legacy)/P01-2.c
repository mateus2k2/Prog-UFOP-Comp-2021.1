//Elabore um programa que l^e o valor de x1, x2 e x3 para calcular (e imprimir) o resultado da express~ao:
//Imprima o resultado na sada, utilizando um formato de sada de sua escolha.

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

    float x1, x2, x3;
    float y;

    printf("Digite as valores de x1, x2, x3:\n");

    scanf("%f", &x1);
    scanf("%f", &x2);
    scanf("%f", &x3);

    y = pow(x1 + (x2*x2) + (x3*x3), 2) - (x1 * x2 * x3);

    printf("\n");

    printf("x1 = %.0f, x2 = %.0f, x3 = %.0f\n", x1, x2, x3);
    printf("y = %.0f\n", y);




    return 0;
}