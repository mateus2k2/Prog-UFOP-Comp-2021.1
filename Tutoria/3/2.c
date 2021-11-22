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

void eleva(int x, int *x2, int *x3){
    *x2 = x*x;
    *x3 = x*x*x;
}

int main(int argc, char *argv[ ]){
    int x, x2, x3;

    printf("Digite o numero: "); scanf("%i", &x);

    eleva(x, &x2, &x3);

    printf("\n%i ao quadrado e igual a %i", x, x2);
    printf("\n%i ao cubo e igual a %i", x, x3);

    printf("\n");
    return 0;
}