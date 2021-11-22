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

void menorMaior(float n1, float n2, float n3, float *maior, float *menor){
    if(n1 >= n2 && n1 >= n3){
        *maior = n1;
        if(n2 <= n3)
            *menor = n2;
        else
            *menor = n3;
    }

    if(n2 >= n1 && n2 >= n3){
        *maior = n2;
        if(n1 <= n3)
            *menor = n1;
        else
            *menor = n3;
    }

    if(n3 >= n1 && n3 >= n2){
        *maior = n3;
        if(n2 <= n1)
            *menor = n2;
        else
            *menor = n1;
    }

}

int main(int argc, char *argv[ ]){
    float n1, n2, n3;
    float maior, menor;

    printf("Digite os 3 numeros: "); scanf("%f %f %f", &n1, &n2, &n3);

    menorMaior(n1, n2, n3, &maior, &menor);

    printf("Maior: %f \nMenor: %f", maior, menor);
    
    if(maior == n1 && menor == n2 )
        printf("Logo");

    if(maior == n2 && menor == n3)
        printf("Logo");

    if(maior == n1 && menor == n2)
        printf("Logo");

    printf("\n");

    return 0;
}