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

unsigned long long fat(int n);

int main(){
    int n;
    
    printf("Digite o valor de n: "); scanf("%i", &n);
    printf("%i!: %llu", n, fat(n));

    return 0;
}

unsigned long long fat(int n){
    unsigned long long i, f;
    f = i = 1;
    
    while(i <= n){
        f = f * i;
        i++;
    }

    return f;

}