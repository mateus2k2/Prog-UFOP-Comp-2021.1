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
    char nomeCompleto[70], nomesSeparados[10][70];
    int contEspacos = 0;

    printf("Digite o nome completo: ");
    fgets(nomeCompleto, 70, stdin);

    int tam = strlen(nomeCompleto);
    nomeCompleto[tam-1] = '\0';

    int i, j;
    for (i = 0, j = 0; i < strlen(nomeCompleto); i++, j++){            
        if(nomeCompleto[i] == ' '){
            nomesSeparados[contEspacos][j] = '\0';
            contEspacos++;
            j = 0;
            i++;
        }

        nomesSeparados[contEspacos][j] = nomeCompleto[i];    
    }

    nomesSeparados[contEspacos][j] = '\0';

    printf("%s, ", nomesSeparados[contEspacos]);
    for (int i = 0; i < contEspacos; i++){
        printf("%s", nomesSeparados[i]);
        printf(" ");
    }

    printf("\nTotal de letras (Sem Espacos): %li", strlen(nomeCompleto) - contEspacos);
    printf("\nTotal de letras do ultimo sobrenome: %li", strlen(nomesSeparados[contEspacos]));
    
    printf("\n");
    
    return 0;
}