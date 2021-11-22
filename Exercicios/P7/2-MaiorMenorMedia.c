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


#define MAX 30 

void calcula(double temp[], int tamanho){

    double media = 0;
    int contMaior = 0, contMenor = 0;


    for (int i = 0; i < tamanho; i++){
        media = media + temp[i];
    }

    media = media/(double)tamanho;

    for (int i = 0; i < tamanho; i++){
        if(temp[i] > media){
            contMaior++;
        }
        
        if(temp[i] < media){
            contMenor++;
        }
    }
    
    printf("\nNumero maiores que a media: %i", contMaior);
    printf("\nNumero menores que a media: %i", contMenor);
    printf("\n");

}



int main(int argc, char *argv[ ]){

    double temp[MAX];

    printf("\nDIGITE AS TEMPERATURA\n");
    for (int i = 0; i < MAX; i++){
        printf("%i: ", i+1); scanf("%lf", &temp[i]);
    }

    calcula(temp, MAX);
    
    return 0;
}

