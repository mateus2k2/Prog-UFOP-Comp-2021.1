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

    int n, vetor[15], temp;

    printf("Digite um numero n: "); scanf("%i", &n);

    printf("DIGITE OS VALORES DO VETOR\n");
    for (int i = 0; i < 15; i++){
        printf("%i: ", i+1);
        scanf("%i", &vetor[i]);
    }
    
    printf("\nVETOR ORIGINAL\n");
    for (int i = 0; i < 15; i++){
        printf("%i ", vetor[i]);
    }

    for(int i = 0; i < n; i++){    
        int j, primeiro;    
        primeiro = vetor[0];    
        
        for(j = 0; j < 15-1; j++){    
            vetor[j] = vetor[j+1];    
        }    
        vetor[j] = primeiro;    
    }  

    printf("\n\nVETOR ROTACIONADO %i POSICOES PARA A ESQUERDA\n", n);
    for (int i = 0; i < 15; i++){
        printf("%i ", vetor[i]);
    }
    
    printf("\n");

    return 0;
}
 