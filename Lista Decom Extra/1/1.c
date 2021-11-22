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

    int numero, cont = 0;
    int menor = INFINITY;

    while (cont != 5){
        printf("Digite um numero: ");
        scanf("%i", &numero);

        if(numero < menor)
            menor = numero;

        cont++;
    }

    printf("O menor numero e %i", menor);
    printf("\n");
    


    return 0;
}