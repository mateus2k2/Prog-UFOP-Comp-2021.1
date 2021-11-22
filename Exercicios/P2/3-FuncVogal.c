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

char caractere;

void verifica();

int main(int argc, char *argv[ ]){

    printf("Digite o caractere: "); scanf("%c", &caractere);

    verifica();

    return 0;
}

void verifica(){
    
    if(caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u' || caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U')
        printf("\nCaractere eh uma vogal\n");
    
    else
        printf("\nCaractere eh uma consoante\n");



}