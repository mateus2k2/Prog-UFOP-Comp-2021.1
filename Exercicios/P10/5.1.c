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


    FILE *ft,*fb;
    int a;

    ft = fopen("file.txt","rt");
    fb = fopen("file.dat","wb");

    while (fscanf(ft,"%d\n",&a) != EOF){
        fprintf(fb,"%d\n",a);
        fseek(ft, 1, SEEK_CUR);

    }

    return 0;
}