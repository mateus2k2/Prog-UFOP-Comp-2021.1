//Crie um programa que converte um valor em graus Celsius para graus Fahrenheit e Kevin.

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

    float C, F, K;

    printf("Digite o valor em grau Celsius: ");
    scanf("%f", &C);

    F = (9.0/5.0)*C + 32;
    K = C + 273.15;

    printf("\n");
    printf("\nTemperatura em Kelvin: %0.f", K);
    printf("\nTemperatura em Fahrenheit: %0.f", F);


    return 0;
}