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


int main(int argc, char *argv[ ]){

    int fibo[10];

    fibo[0] = 1;
    fibo[1] = 1;

    for (int i = 2; i < 10; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    printf("\n");
    
    for (int i = 0; i < 10; i++){
        printf("%i ", fibo[i]);
    }
    
    printf("\n");



    return 0;
}