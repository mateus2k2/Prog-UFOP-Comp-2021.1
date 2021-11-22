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

    int valores1[10], valores2[10];
    int soma = 0;

    printf("\nDIGETE OS PRIMEIROS VALORES: \n");
    for (int i = 0; i < 10; i++){
        scanf("%i", &valores1[i]);
    }

    printf("\nDIGETE OS SEGUNDOS VALORES: \n");
    for (int i = 0; i < 10; i++){
        scanf("%i", &valores2[i]);
    }    

    for (int i = 0; i < 10; i++){
        soma = soma + (valores1[i] * valores2[i]);
    }

    printf("\nSoma: %i\n\n", soma);
    

    return 0;
} 