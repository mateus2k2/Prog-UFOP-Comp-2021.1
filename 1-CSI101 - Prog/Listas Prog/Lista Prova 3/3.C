#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct{
    float x, y, z;
}vetor;

vetor soma(vetor vetores[]){
    vetor soma;

    soma.x = vetores[0].x + vetores[1].x;
    soma.y = vetores[0].y + vetores[1].y;
    soma.z = vetores[0].z + vetores[1].z;

    return soma;
}

vetor multiplica(vetor vetores[]){
    vetor mult;
    float maior = -INFINITY;

    if(vetores[1].x > maior)
        maior = vetores[1].x;
    if(vetores[1].y > maior)
        maior = vetores[1].y;
    if(vetores[1].z > maior)
        maior = vetores[1].z;
    
    mult.x = vetores[0].x * maior;
    mult.y = vetores[0].y * maior; 
    mult.z = vetores[0].z * maior; 
    
    return mult;
}

int main(){
    vetor vetores[2];
    vetor vetorSoma;
    vetor vetorMulti;

    for (int i = 0; i < 2; i++){
        printf("\nVETOR %i\n", i+1);

        printf("x: ");
        scanf("%f", &vetores[i].x);
        printf("y: ");
        scanf("%f", &vetores[i].y);
        printf("z: ");
        scanf("%f", &vetores[i].z);
    }
    
    printf("\n----------------------\n");

    vetorSoma = soma(vetores);

    printf("\nVETOR SOMA");
    printf("\nx: %.f", vetorSoma.x);
    printf("\ny: %.f", vetorSoma.y);
    printf("\nz: %.f", vetorSoma.z);

    vetorMulti = multiplica(vetores);

    printf("\n");
    printf("\nVETOR MULTIPLICA");
    printf("\nx: %.f", vetorMulti.x);
    printf("\ny: %.f", vetorMulti.y);
    printf("\nz: %.f", vetorMulti.z);


}