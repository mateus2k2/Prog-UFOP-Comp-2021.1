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

    double sala[4][3], mairoMedia = -INFINITY, mediaGeral = 0;
    int codigoMaiorMedia; 

    for (int i = 0; i < 4; i++){
        printf("ALUNO %i\n", i+1);
        printf("Codigo: "); scanf("%lf", &sala[i][0]);
        printf("P1: "); scanf("%lf", &sala[i][1]); 
        printf("P2: "); scanf("%lf", &sala[i][2]); 
        printf("P3: "); scanf("%lf", &sala[i][3]);
        sala[i][4] = (sala[i][1] + sala[i][2] + sala[i][3]) / 3;
        
        if(sala[i][4] > mairoMedia){
            mairoMedia = sala[i][4];
            codigoMaiorMedia = sala[i][0];
        }

        mediaGeral = mediaGeral + sala[i][4];
        printf("\n");
    }
    mediaGeral = mediaGeral/4;

    printf("\nMaior Media: %i", codigoMaiorMedia);
    printf("\nMeida Geral: %lf", mediaGeral);



    return 0;
}