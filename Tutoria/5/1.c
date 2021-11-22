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


void troca(double *xp, double *yp){
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main(int argc, char *argv[ ]){
    double vetor[100];
    int quantidade;

    printf("Qual numero pretende ordernar: "); scanf("%i", &quantidade);

    printf("DIGITE OS NUMEROS\n");
    for (int i = 0; i < quantidade; i++){
        printf("%i: ", i+1); scanf("%lf", &vetor[i]);
    }

    int i, j;
    for (i = 0; i < quantidade-1; i++)     
        for (j = 0; j < quantidade-i-1; j++)
            if (vetor[j] > vetor[j+1])
                troca(&vetor[j], &vetor[j+1]);

    printf("\nVETOR ORDENADO\n");
    for (int i = 0; i < quantidade; i++){
        printf("%.2lf ", vetor[i]); 
    }
    
    printf("\n");



    return 0;
}