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
    double vetor[100];
    int quantidade;
    double soma = 0, sub = 0, mult = 1;

    printf("Qual numero pretende ordernar: "); scanf("%i", &quantidade);

    printf("DIGITE OS NUMEROS\n");
    for (int i = 0; i < quantidade; i++){
        printf("%i: ", i+1); scanf("%lf", &vetor[i]);
        
        if(i % 2 == 0)
            soma = soma + vetor[i];

        if(i % 3 == 0)
            sub = sub - vetor[i];

        if(i % 6 == 0)
            mult = mult * vetor[i];
    }

    printf("\nRESULTADO: ");
    printf("%.0lf %.0lf %.0lf", soma, sub, mult);
    
    printf("\n");

    return 0;
}