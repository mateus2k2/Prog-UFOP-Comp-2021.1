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

    char conceito;

    printf("Digite o conceito: ");
    scanf("%c", &conceito);
    getchar();

    if(conceito == 'A' || conceito == 'a')
        printf("Exelente");

    else if (conceito == 'B' || conceito == 'b')
            printf("Otimo");
        
    else if (conceito == 'C' || conceito == 'c')
            printf("Bom");

    else if (conceito == 'D' || conceito == 'd')
            printf("Regular");

    else if (conceito == 'E' || conceito == 'e')
            printf("Ruim");

    else if (conceito == 'F' || conceito == 'f')
            printf("Nos vemos de novo ano que vem...");
        
    else
        printf("Conceito nao valido...");
        

    


    return 0;
}