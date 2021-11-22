#include <stdio.h>

int main(){
    float x, y, totalSoma, totalDiferenca;

    printf("SISTEMA DE EQUACOES\n");

    printf("x + y = ");
    scanf("%f", &totalSoma);
    printf("x - y = ");
    scanf("%f", &totalDiferenca);

    y = (totalSoma - totalDiferenca)/2 ;
    x = totalDiferenca + y;

    printf("Solucao:\n");
    printf("x = %f\n", x);
    printf("y = %f\n", y);

    return 0;

}