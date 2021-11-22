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

    int a, b, c;
    int temp;

    printf("Digite os valores a, b, c: \n");
    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);

    printf("\n");

 if(a > c){
    temp = a;
    a = c;
    c = temp;
}

if(a > b){
    temp = a;
    a = b;
    b = temp;
}

if (b > c){
    temp = b;
    b = c;
    c = temp;
}

    printf("Menor: %i\n", a);
    printf("Intermediario: %i\n", b);
    printf("Maior: %i\n", c);

    return 0;
}