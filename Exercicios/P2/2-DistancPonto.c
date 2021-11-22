//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

//faltou definir os tipos dos parâmetros da função e o calculo da distância está sendo feito como inteiro (int) e deveria ser ponto flutuante (float/double).

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

int calculaDistancia(x1, x2, y1, y2);

int main(int argc, char *argv[ ]){

    int x1, x2, y1, y2;

    printf("\nPronto 1: ");
    printf("(x, y): "); scanf("%i %i", &x1, &y1);

    printf("\nPronto 2: ");
    printf("(x, y): "); scanf("%i %i", &x2, &y2);

    printf("Distancia entre os pontos: %i", calculaDistancia(x1, x2, y1, y2));

    return 0;
}

int calculaDistancia(int x1, int x2, int  y1, int y2) {

    int distancia;

    distancia = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

    return distancia;

}