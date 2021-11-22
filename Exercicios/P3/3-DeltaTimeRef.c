//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

//contagem de tempo para jogos que terminam no dia seguinte está errada.

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


int calculaTempo(int *horaInicio, int *minutoInicio, int *horaFim, int *minutoFim);

int main(int argc, char *argv[ ]){

    int horaInicio, minutoInicio, horaFim, minutoFim;
    int totalMinutos;

    printf("\nDigite as horas do jogo (formato 24h), no modelo (hh mm): \n");
    printf("Inicio: "); scanf("%i %i", &horaInicio, &minutoInicio);
    printf("Fim: "); scanf("%i %i", &horaFim, &minutoFim);

    totalMinutos = calculaTempo(&horaInicio, &minutoInicio, &horaFim, &minutoFim);

    printf("\nMinutos de duracao: %i", totalMinutos);
}

int calculaTempo(int *horaInicio, int *minutoInicio, int *horaFim, int *minutoFim){

    int total = (abs(*horaFim - *horaInicio) * 60) + abs(*minutoFim - *minutoInicio);

    if(*horaInicio >= *horaFim)
        total = total + (24 * 60); 

    return total;
}