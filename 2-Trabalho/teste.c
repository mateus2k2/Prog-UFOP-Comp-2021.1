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

    int randdd;
    time_t t;   
    srand((unsigned) time(&t));


    while (1){
        randdd = rand() % 4;
        printf("\n%i", randdd);
    }
    


    return 0;
}