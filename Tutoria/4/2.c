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
    int numero;

    printf("Digte um numero inteiro: "); scanf("%i", &numero);

    if(numero > 0){
        for (int i = numero; i != -1; i--){
            for (int j = numero; j != -1; j--){
                printf("\n(%i, %i)", numero-i, numero-j);
            }
        }
    }
    
    if(numero < 0){
        for (int i = 0; i != numero-1; i--){
            for (int j = 0; j != numero-1; j--){
                printf("\n(%i, %i)", numero-i, numero-j);
            }
        }
    }

    printf("\n");

    return 0;
}