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

    double nota1[15], nota2[15];

    printf("\nNOTAS\n\n");
    for (int i = 0; i < 15; i++){
        printf("ALUNO %i\n", i+1);
        
        printf("P1: "); scanf("%lf", &nota1[i]);
        printf("P2: "); scanf("%lf", &nota2[i]);
        printf("\n");

    }

    printf("\nRESULTADOS\n");
    for (int i = 0; i < 15; i++){
        printf("ALUNO %i: ", i+1);
        
        if((nota1[i]+nota2[i])/2 >= 60)
            printf("Aprovado\n");
        else
            printf("Reprovado\n");

    }
    
    return 0;
}