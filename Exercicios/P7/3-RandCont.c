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

imprime(int cont[], int n){

    for (int i = 0; i < n+1; i++){
        printf("\n%i: %i", i, cont[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[ ]){

    int n = 501;
    int aleatorio;
    
    time_t t;   
    srand((unsigned) time(&t));
    
    printf("Digite um numero n menor ou igual a 500: ");
    while(n > 500 || n < 0){
        scanf("%i", &n);

        if(n > 500 || n < 0){
            printf("\nNumero invalido, tente novamente: ");
        }
    }

    int cont[500];
    for (int i = 0; i < n+1; i++){
        cont[i] = 0;
    }    

    for (int i = 0; i < 100000; i++){
        aleatorio =  rand() % (n+1);

        for (int i = 0; i < n+1; i++){
            if(aleatorio == i)
                cont[i]++;
        }
    }
    
    imprime(cont, n);


    return 0;
}