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

//52998224725
//(5 X 10) + (2 X 9) + (9 X 8) + (9 X 7) + (8 X 6) + (2 X 5) + (2 X 4) + (4 X 3) + (7 X 2) = 295
//295/10 % 11 = 2

//(5 X 11) + (2 X 10) + (9 X 9) + (9 X 8) + (8 X 7) + (2 X 6) + (2 X 5) + (4 X 4) + (7 X 3) + (2 X 2) = 347
//347 / 10 % 11 = 5 

int verificaCPF(long long int cpf){

    long long int bkpCpf = cpf;
    int mult10 = 2;     
    int mult11 = 2;
    int soma1 = 0, soma2 = 0;
    int i = 0;

    while(i != 11){
        long long int mod = cpf % 10;
    
        if(i > 1){
            soma1 = soma1 + (mod*mult10);
            mult10++;
        }

        i++;
        cpf = cpf / 10;     
    }

    i = 0;
    cpf = bkpCpf;

    while(i != 11){
        long long int mod = cpf % 10;
    
        if(i > 0){
            soma2 = soma2 + (mod*mult11);
            mult11++;
        }

        i++;
        cpf = cpf / 10;     
    }

    i = 0;
    cpf = bkpCpf;

    while(i != 2){
        long long int mod = cpf % 10;

        if(i == 0){
            if((soma2*10) % 11 != mod){
                return 1;
            }
        }

        if(i == 1){
            if((soma1*10) % 11 != mod){
                return 1;
            }
        }
        
        i++;
        cpf = cpf / 10;     
    }
    return 0;
}

int main(){

    long long int cpf;

    printf("Digite seu CPF (Somente Numeros): "); scanf("%lld", &cpf);
    
    if(verificaCPF(cpf) == 0)
        printf("\nCPF Valido\n");
    else
        printf("\nCPF Invalido\n");


    return 0;
}