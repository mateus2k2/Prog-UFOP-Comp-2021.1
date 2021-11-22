//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  1

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


int main(int argc, char *argv[]){

    int x, soma = 0;
    int cont = 0;

    while(x =! 0){
        printf("Digite um valor x: "); scanf("%i", &x);
        if(x == 0)
            break;

        while (cont < 5){
            if(x % 2 == 0){
                soma = soma + x;
                x = x + 2;
                cont++;
            }
            else{
                soma = soma + x+1;
                x = (x+1) + 2;
                cont++;
            }
        }
        printf("\nSoma: %i\n", soma);
        soma = 0;
        cont = 0;
    }
    


    return 0;
}