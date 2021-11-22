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
    int quantiade = -1;
    double vetor[20];


    printf("Digite um numero n menor ou igual a 20: ");
    while(quantiade > 20 || quantiade < 0){
        scanf("%i", &quantiade);

        if(quantiade > 20 || quantiade < 0){
            printf("Numero invalido, tente novamente: ");
        }
    }

    printf("\nDIGITE OS NUMEROS: \n");
    for (int i = 0; i < quantiade; i++){
        printf("%i: ", i+1); scanf("%lf", &vetor[i]);
    }

    int aux[quantiade];
    for (int i = 0; i < quantiade; i++){
        aux[quantiade - 1 - i] = vetor[i];
    }
    for (int i = 0; i < quantiade; i++) {
        vetor[i] = aux[i];
    }
    
    printf("\nVETOR INVERTIDO: \n");
    for (int i = 0; i < quantiade; i++){
        printf("%.1lf ", vetor[i]); 
    }




    return 0;
}