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

    int x,y,z;
    int cont = 0;

    printf("Digite o intervalo: "); scanf("%i %i", &x, &y);
    printf("Digite o numero: "); scanf("%i", &z);

    calculaIntervalo(&cont, x, y, z);

    printf("Quantidade de multiplos: %i", cont);    

    return 0;
}

void calculaIntervalo(int *cont, int x, int y, int z){
    int i = x;

    while(i <= y){
        if(i % z == 0){
            *cont = *cont + 1;
        }

        i++;
    }
}
