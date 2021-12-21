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
#include <unistd.h>


#include "Headers/cores.h"
#include "Headers/structs.h"

#include "Headers/menus.h"

#include "Headers/criaTabuleiro.h"
#include "Headers/continuarJogo.h"
#include "Headers/jogar.h"

#include "Headers/outros.h"



int main(int argc, char *argv[ ]){
    time_t t;   
    srand((unsigned) time(&t));
    setlocale(LC_ALL,"Portuguese_Brasil");
    

    printf("Bem vindo ao Caça Palavras");
    menu();

    printf("\n");

    return 0;
}

