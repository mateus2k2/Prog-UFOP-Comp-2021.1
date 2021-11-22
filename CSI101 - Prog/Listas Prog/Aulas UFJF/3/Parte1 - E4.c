#include <stdio.h>

void calculo(float NN1, float NN2, float NN3){

float media;

media = (NN1 + NN2 + NN3) / 3;

printf("%f", media);

}


int main (){

float N1, N2, N3;

printf("Digite o primeiro numero: ");
scanf("%f", &N1);

printf("Digite o segundo numero: ");
scanf("%f", &N2);

printf("Digite o terceiro numero: ");
scanf("%f", &N3);

calculo(N1, N2, N3);

return 0;

}