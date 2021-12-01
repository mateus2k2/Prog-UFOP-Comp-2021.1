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

typedef struct{
    int a;
    int b;
}Complexo;

Complexo somaComplexo(Complexo c1, Complexo c2){
    Complexo soma;

    soma.a = c1.a + c2.a;
    soma.b = c1.b + c2.b;

    return soma;
}

Complexo subComplexo(Complexo c1, Complexo c2){
    Complexo sub;

    sub.a = c1.a - c2.a;
    sub.b = c1.b - c2.b;

    return sub;
}

Complexo multComplexo(Complexo c1, Complexo c2){
    Complexo mult;

    mult.a = (c1.a*c2.a) - (c1.b*c2.b);
    mult.b = (c1.a*c2.b) + (c1.b*c2.a);

    return mult;
}

void printComplexo(Complexo resultado){
    if(resultado.a > 0 && resultado.b > 0)
            printf("Resultado: %i + (%ii)\n", resultado.a, resultado.b);
    else if(resultado.a > 0 && resultado.b < 0)
            printf("Resultado: %i - (%ii)\n", resultado.a, -resultado.b);
    else if(resultado.a < 0 && resultado.b < 0)
            printf("Resultado: %i - (%ii)\n", resultado.a, -resultado.b);
    else if(resultado.a < 0 && resultado.b > 0)
            printf("Resultado: %i + (%ii)\n", resultado.a, resultado.b);
    else if(resultado.a == 0 && resultado.b > 0)
            printf("Resultado: (%ii)\n", resultado.b);
    else if(resultado.a == 0 && resultado.b < 0)
            printf("Resultado: (%ii)\n", resultado.b);
    else if(resultado.a > 0 && resultado.b == 0)
            printf("Resultado: %i\n", resultado.a);
    else if(resultado.a < 0 && resultado.b == 0)
            printf("Resultado: %i\n", resultado.a);
    else if(resultado.a == 0 && resultado.b == 0)
            printf("Resultado: 0\n");
        

}

int main(int argc, char *argv[ ]){

    Complexo c1, c2, resultado;
    char op;

    printf("Digite os valores de a e b (x = a + bi): "); scanf("%i %i", &c1.a, &c1.b);
    printf("Digite os valores de c e d (x = c + di): "); scanf("%i %i", &c2.a, &c2.b);
    while ((getchar()) != '\n');


    printf("Digite a operacao (+, - ou *): "); scanf("%c", &op);

    if(op == '+'){
        resultado = somaComplexo(c1, c2);
        printComplexo(resultado);
    }    
    else if(op == '-'){
        resultado = subComplexo(c1, c2);
        printComplexo(resultado);
    }
    else if(op == '*'){
        resultado = multComplexo(c1, c2);
        printComplexo(resultado);

    }
    else
        printf("Operados Invalido\n");

    return 0;
}

