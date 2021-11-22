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

    int idade;
    
    printf("Digite a sua idade: ");
    scanf("%i", &idade);

    if(idade <= 10)
        printf("R$90,00");
    else if (idade > 10 && idade <= 29)
        printf("R$170,00");
    else if (idade > 29 && idade <= 45)
        printf("R$290,00");
    else if (idade > 45 && idade <= 59)
        printf("R$400,00");
    else if (idade > 59 && idade <= 65)
        printf("R$515,00");
    else if (idade > 65)
        printf("R$695,00");



    return 0;
}