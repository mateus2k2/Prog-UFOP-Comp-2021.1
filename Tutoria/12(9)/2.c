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
    FILE *arquivoDat = fopen("matrizes.dat", "r");
    int lin, col, tmp;

       while (!feof(arquivoDat)){
        fread(&lin, sizeof(int), 1, arquivoDat);
        fread(&col, sizeof(int), 1, arquivoDat);

        for (int i = 0; i < lin; i++){
            for (int j = 0; j < col; j++){
                fread(&tmp, sizeof(int), 1, arquivoDat);
                printf("%i ", tmp);
            }
            printf("\n");            
        }
        
        printf("\n------------------------------------------------------------\n");         

        
    }
    

    fclose(arquivoDat);
    printf("\n");


    return 0;
}