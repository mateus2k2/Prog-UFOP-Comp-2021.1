//Crie um programa que, dada uma letra, escreve na tela se essa letra e ou n~ao uma vogal (considere letras maiusculas e minusculas).

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

    char letra;

    printf("Digite uma letra: ");
    scanf("%c", &letra);
    getchar();

    if(letra == 'a'|| letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') 
        printf("A letra eh uma vogal");
    else
        printf("A leetra nao eh uma vogal");

    return 0;
}