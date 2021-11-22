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
    char frase[100];
    int numeroDeslocamentos = 51;

    printf("Digite o numero de deslocamentos. Menor que 50: ");
    
    while(numeroDeslocamentos > 50 || numeroDeslocamentos < 0){
        scanf("%i", &numeroDeslocamentos);
        if(numeroDeslocamentos > 50 || numeroDeslocamentos < 0)
            printf("Numero inválido. Tente novamente: ");
    }

    while ((getchar()) != '\n');

    printf("Digite a frase: ");
    fgets(frase, 100, stdin);
    
    for (int i = 0; i < strlen(frase); i++){
        
        if(frase[i] >=  'a' && frase[i] <= 'z'){
            if(frase[i]+numeroDeslocamentos > 'z')
                frase[i] = ('a'- 1) + ((numeroDeslocamentos)%26);  
            else
                frase[i] = frase[i] + numeroDeslocamentos;
        }

        if(frase[i] >=  'A' && frase[i] <= 'Z'){
            if(frase[i]+numeroDeslocamentos > 'z')
                frase[i] = ('A' - 1) + ((numeroDeslocamentos)%26);  
            else
                frase[i] = frase[i] + numeroDeslocamentos;
        }
    }

    printf("Frase modificada: ");
    puts(frase);
    


    return 0;
}