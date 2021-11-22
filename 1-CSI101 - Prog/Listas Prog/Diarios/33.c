//Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior endereço.

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
    int n1, n2;

    printf("Digite dois numeros (numero1, numero2): ");
    scanf("%i%i", &n1, &n2);

    if(&n1 > &n2)
        printf("O numero 1 tem maior endereco: %i endereco %i", n1, &n1);

    if(&n2 > &n1)
        printf("O numero 1 tem maior endereco: %i endereco %i", n2, &n2);

    return 0;
}