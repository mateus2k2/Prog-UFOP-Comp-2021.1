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


float calculo(int t, float d);

int main(int argc, char *argv[ ]){
    int t;
    float d;
    float v;
    
    printf("Digite distancia: "); scanf("%f", &d);
    printf("Digite tempo: "); scanf("%i", &t);

    printf("Velociade media %f", calculo(t, d));

    return 0;
}

float calculo(int t, float d){
    float v;
    v = d/(float)t;
    return v;
}