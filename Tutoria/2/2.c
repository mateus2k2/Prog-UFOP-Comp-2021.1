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


int is_prime(int n){

    if(n%2 == 0 && n != 2){      
        return 1;
    }

    if(n == 2){
        return 0;    
    }

    int j = 2;
    while (j < n){
        
        if(n % j == 0)
            return 1;

        if(j == n - 1){
            return 0;
        }

    j++;
    }
}

void calculaIntervalo(int *soma, int x, int y){
    int i = x+1;

    while(i <= y){
        if(is_prime(i) == 0){
            *soma = *soma + i;
        }
        
        i++;
    }
}

int main(int argc, char *argv[ ]){

    int x,y;
    int soma = 0;

    printf("Digite o intervalo: "); scanf("%i %i", &x, &y);

    calculaIntervalo(&soma, x, y);

    printf("\nSoma primos: %i", soma);    

    return 0;
}


