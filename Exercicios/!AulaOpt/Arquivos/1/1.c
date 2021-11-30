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

int main(int argc, char *argv[]){

    FILE *arquivoIn = fopen("1In.txt", "r");

    char tmp[100][100], c;
    int i = 0, j = 0;
    
    while (fscanf(arquivoIn, "%c", &c) != EOF){
        tmp[i][j] = c;
        if(c == '\n')
            j++;
        i++;
    }
    FILE *arquivoOut = fopen("1Out.txt", "w");

    while (fscanf(arquivoOut, "%c", &c) != EOF){
        tmp[i][j] = c;
        if(c == '\n')
            j++;
        i++;
    }

    return 0;
}