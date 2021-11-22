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
    char plano;
    int quantidade;
    float media, total;

    printf("Digite plano: ");
    scanf("%c", &plano);
    printf("Digite quantidade: ");
    scanf("%i", &quantidade);

    if(plano == 'F'){
        if(quantidade <= 15)
            total = quantidade * 4.15 + 23.90;
        if(quantidade > 15 && quantidade <= 30)
            total = (quantidade - 15) * 3.15 + (15 * 3.5) + 23.90;
        if(quantidade > 30)
            total = quantidade * 1.5 + 23.90;
    }
    
    if(plano == 'V'){
        if(quantidade <= 15)
            total = quantidade * 3 + 31.95;
        if(quantidade > 15 && quantidade <= 30)
            total = (quantidade - 15) * 2.10 + (15 * 2.75) + 31.95;
        if(quantidade > 30)
            total = ((quantidade - 30) * 1) + (30 * 1.5) + 31.95;
    }

    printf("Total: %f \nMedia: %f", total, total/quantidade);
    
    return 0;
}