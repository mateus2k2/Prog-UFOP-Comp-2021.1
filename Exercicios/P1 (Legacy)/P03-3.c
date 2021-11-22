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

    int cod;
    float salarioAntigo, salarioNovo;

    printf("Digite o codigo do cargo: ");
    scanf("%i", &cod);

    printf("Digite o seu salario atual: ");
    scanf("%f", &salarioAntigo);

    switch(cod){
    case 100: salarioNovo = salarioAntigo * 1.03;
        break;
    case 101: salarioNovo = salarioAntigo * 1.05;
        break;
    case 102: salarioNovo = salarioAntigo * 1.075;
        break;
    case 201: salarioNovo = salarioAntigo * 1.1;
        break;

    default: salarioNovo = salarioAntigo * 1.15;
        break;
    }

    printf("\n");
    printf("Salario Antigo: %.2f\n", salarioAntigo);
    printf("Salario Novo: %.2f\n", salarioNovo);
    printf("Diferenca: %.2f\n", salarioNovo - salarioAntigo);
    


    return 0;
}