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

    char frase[1000];

    printf("Digite o texto para censurar: ");
    fgets(frase, 70, stdin);

    int tam = strlen(frase);
    frase[tam-1] = '\0';

    for (int i = 0; i < strlen(frase); i++){
        if(frase[i] == 'a' || frase[i] == 'A')
            frase[i] = '@';
        if(frase[i] == 'e' || frase[i] == 'E')
            frase[i] = '-';
        if(frase[i] == 'i' || frase[i] == 'I')
            frase[i] = '|';
        if(frase[i] == 'o' || frase[i] == 'O')
            frase[i] = '0';
        if(frase[i] == 'u' || frase[i] == 'U')
            frase[i] = '#';
        if(frase[i] == 's' || frase[i] == 'S')
            frase[i] = '$';
    }

    puts(frase);




    return 0;
}
 
