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


int checar(int n){

    if(n == 2)
        return 2;    

    //primo
    int j = 2;
    while (j < n){
        if(n%2 == 0 && n != 2)  
            break;

        if(n % j == 0)
            break;

        if(j == n - 1)
            return 2;

        j++;
    }

    //par
    if(n % 2 == 0)
        return 1;
    //impar
    else
        return 3;


}

int main(int argc, char *argv[ ]){
    int numero;
    int retorno;

    printf("Digite um numero: "); scanf("%i", &numero);

    retorno = checar(numero);

    switch(retorno){
    case 1: printf("%i eh par", numero);
        break;
    case 2: printf("%i eh primo", numero);
        break;
    case 3: printf("%i eh impar", numero);
        break;
    default:
        break;
    }
    
    printf("\n");
    return 0;
}