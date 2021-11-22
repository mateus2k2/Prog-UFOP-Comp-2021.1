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

void converterCelsius(float celsius, float *fahrenheit, float *kelvin);

int main(int argc, char *argv[]){

    float c;
    float f, k;

    printf("Digite o Valor em Celsius: "); scanf("%f", &c);

    converterCelsius(c, &f, &k);

    printf("\nValor em fahrenheit: %.2f \nValor em Kelvin: %.2f", f, k);


    return 0;
}

void converterCelsius(float celsius, float *fahrenheit, float *kelvin){

    *fahrenheit = (celsius * (9.0/5.0)) + 32;
    *kelvin = celsius + 273;
}