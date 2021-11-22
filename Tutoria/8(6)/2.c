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

    printf("Digite a frase: ");
    fgets(frase, 100, stdin);

while (1){

    printf("Digite o numero de deslocamentos. Menor que 50 e -1 Para sair: ");
        
        while(numeroDeslocamentos > 50){
            scanf("%i", &numeroDeslocamentos);
            if(numeroDeslocamentos > 50)
                printf("Numero inválido. Tente novamente: ");
        }

        if(numeroDeslocamentos == -1)
            break;

        for (int i = 0; i < strlen(frase); i++){
            
            if(frase[i] >=  'a' && frase[i] <= 'z'){
                if(frase[i]-numeroDeslocamentos < 'a')
                    frase[i] = ('z'+ 1) - ((numeroDeslocamentos)%26);  
                else
                    frase[i] = frase[i] - numeroDeslocamentos;
            }

            if(frase[i] >=  'A' && frase[i] <= 'Z'){
                if(frase[i]-numeroDeslocamentos < 'A')
                    frase[i] = ('Z' + 1) - ((numeroDeslocamentos)%26);  
                else
                    frase[i] = frase[i] - numeroDeslocamentos;
            }
        }   

        printf("\nFrase decodificada: ");
        puts(frase);
        numeroDeslocamentos = 51;
        
}

    
    


    return 0;
}