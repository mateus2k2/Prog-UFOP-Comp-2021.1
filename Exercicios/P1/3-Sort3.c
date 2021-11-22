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

    int a, b, c;

    printf("Digite os valores a, b, c: \n");
    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);

    printf("\n");

    if(a>b && a>c){
        if(b>c)
            printf("Menor: %i \nIntermediario: %i \nMaior: %i", c, b, a);
    
        else
            printf("Menor: %i \nIntermediario: %i \nMaior: %i", b, c, a);
    }

    else if(b>a && b>c){            
            if(c>a)
                printf("Menor: %i \nIntermediario: %i \nMaior: %i", a, c, b);

            else
                printf("Menor: %i \nIntermediario: %i \nMaior: %i", c, a, b);
    } 

    else if(c>a && c>b){     
            if(a>b)
                printf("Menor: %i \nIntermediario: %i \nMaior: %i", b, a, c);

            else
                printf("Menor: %i \nIntermediario: %i \nMaior: %i", a, b, c);
    } 
    else
        printf("Todos o numeros iguais");

    return 0;
}