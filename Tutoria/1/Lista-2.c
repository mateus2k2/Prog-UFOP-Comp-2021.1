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


int main()
{
    int n,i,f;
    f = i = 1;

    printf("Digite o numero a ser calculado: "); scanf("%i", &n);
    
    while(i <= n){
        f = f * i;
        i++;
    }

    printf("O fatorial de %i eh : %i",n,f);
    return 0;
}