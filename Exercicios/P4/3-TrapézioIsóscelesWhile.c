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

int main(){
    int x=3, y=3;
    int x1;
    int espaco1;
    int espaco2;


    while (x > y || x % 2 != 0 || y % 2 != 0){
    
        printf("Digite os valores de x e y: "); scanf("%i %i", &x, &y);

        if(x > y)
            printf("Erro: x deve ser menor que y.\n");
        
        if(x % 2 != 0 || y % 2 != 0)
            printf("Apenas numeros pares sao aceitos.\n");

        printf("\n");

    }

    if(x != 2){
        espaco1 = (y/2) - 2;
        espaco2 = espaco1;  
    }
    
    if(x == 2){
        espaco1 = (y/2);
        espaco2 = espaco1;  
    }

    x1 = x;

    while(x != y+2){
        while(x1 != 0){
            while(espaco1 != 0){
                printf(" ");
                espaco1--;
            }  
            printf("*");
            x1--;
        }
        espaco2--;
        espaco1 = espaco2;

        x = x + 2;
        x1 = x;

        printf("\n");
    }

}
