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

    float peso, altura, IMC;

    printf("Digite o seu peso: ");
    scanf("%f", &peso);

    printf("Digite a sua altura: ");
    scanf("%f", &altura);

    IMC = peso/(altura*altura);

    printf("\nIMC = %.2f\n", IMC);

    if(IMC < 18.5)
        printf("Abaixo do peso");
    else if (IMC >= 18.5 && IMC < 25)
        printf("Peso normal");
    else if (IMC >= 25 && IMC < 30)
        printf("Acima do peso");
    else if(IMC >= 30)
        printf("Obeso");


    return 0;
}