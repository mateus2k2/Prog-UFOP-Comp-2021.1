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
    char resultado;
    int vitorias = 0;

    printf("\nDigite o o resultado dos jogos (V ou P): \n");
    for (int i = 0; i < 6; i++){
        scanf(" %c", &resultado);
    
        if(resultado == 'v' || resultado == 'V'){
            vitorias = vitorias + 1;
        }


        if(resultado != 'p' && resultado != 'P' && resultado != 'v' && resultado != 'V'){
            printf("Caracter invalido, tente novamente: ");
            i--;
        }
    }


    if(vitorias == 5 || vitorias == 4 || vitorias == 6)
        printf("\n1");
    else if(vitorias == 4 || vitorias == 3)
        printf("\n2");
    else if(vitorias == 1 || vitorias == 2)
        printf("\n3");
    else
        printf("\n-1");

    printf("\n");

    return 0;
}