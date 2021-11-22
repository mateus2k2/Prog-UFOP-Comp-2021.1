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


int checar(int contL, int contC, int posiL, int posiC){
    int BcontL = contL, BcontC = contC, BposiL = posiL, BposiC = posiC;

    //checar se a linha e coluna atual esta na diagonal da frente
    while(contL != 9){
        if(contL == posiL && contC == posiC)
            return 1;

        contL++;
        contC++;
    }

    contL = BcontL, contC = BcontC, posiL = BposiL, posiC = BposiC;

    //checar se a linha e coluna atual esta na diagonal de tras
    while(contL != 0){
        if(contL == posiL && contC == posiC)
            return 1;

        contL--;
        contC--;
    }

    contL = BcontL, contC = BcontC, posiL = BposiL, posiC = BposiC;

    //checar se a linha e coluna atual esta na diagonal de tras
    while(contL != 9){
        if(contL == posiL && contC == posiC)
            return 1;

        contL++;
        contC--;
    }

    contL = BcontL, contC = BcontC, posiL = BposiL, posiC = BposiC;

    //checar se a linha e coluna atual esta na diagonal de tras
    while(contL != 0){
        if(contL == posiL && contC == posiC)
            return 1;

        contL--;
        contC++;
    }

    return 0;
    
}

int main(int argc, char *argv[ ]){

    int l, c;
    int posiL = 10, posiC = 10;

    printf("\nMovimentos de um Bispo no xadrez!\n");
    printf("\n");

    while(posiL > 8 || posiC > 8 || posiL <= 0 || posiC <= 0){
        printf("Digite a linha em que o Bispo se encontra: "); scanf("%i", &posiL);
        printf("Digite a coluna em que o Bispo se encontra: "); scanf("%i", &posiC);

        if(posiL > 8 || posiC > 8 || posiL <= 0 || posiC <= 0)
            printf("Os valores devem estar entre 1 e 8\n");                                        

        printf("\n");
    }


    int contC=1, contL=1;
    int contC1=1, contL1=1;
    int test = 0;


    printf("       1  2  3  4  5  6  7  8");
    printf("\n    ---------------------------\n");

    while(contL != 9){
        printf("%i |  ", contL);

        while(contC != 9){
            if((checar(contL, contC, posiL, posiC) == 1) && (contL != posiL && contC != posiC))
                printf("  x");
            
            if(checar(contL, contC, posiL, posiC) == 0)
                printf("  -");

            if(contL == posiL && contC == posiC)
                printf("  *");
            
            contC++;
        }
        contC = 1;

        printf("\n");
        contL++;
    }



    return 0;
}