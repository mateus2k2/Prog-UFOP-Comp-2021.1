// Você deverá fazer um programa que leia a medida do ângulo formado por uma escada apoiada no chão e a distância em que a escada está da parede. 
// O programa deverá calcular e mostrar a medida da escada para que se possa alcançar sua ponta. O seu programa deverá verificar a consistência dos dados, 
// lembrando que a soma de dois lados de um triângulo deve ser maior do que o terceiro.


//Matrícula 20.2.8093
//Nome: Mateus Filipe Moreira Silva

/*
Entrdas: ângulo da escada com o chão e distancia da escada da parede 

Saidas: Tamanho da escada e tamanho da parece 

Objetivo: Calcular o tamanho de uma escada apoiada em uma parece fazendo uso do ângulo fornecido e da distância da escada para a parede
          Também e verificado as condições de existência do triângulo formado   

*/


#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
   
    float escadaParede, escada, parede;
    float angulo;

    //Entrada do angulo e da distencia da escada (Cateto adjacente ao ângulo) para a parede
    printf("Digite o angulo formada pela escada apoiada no chao: ");
    scanf("%f", &angulo);

    printf("Digite o valor do da distância da escada ate a parede: ");
    scanf("%f", &escadaParede);

    angulo = (angulo * M_PI) / 180.00;
    escada = escadaParede/cos(angulo);
    parede = sqrt((escada*escada) - (escadaParede*escadaParede));

    //Verifica a consistencia dos lados desse triângulo
    //Redundante, ja que entrando com dois lados e calculando o terceiro com Bhaskara jamais o triângulo entrará na consição de nao existência
    if(parede<escada+escadaParede && escada<parede+escadaParede && escadaParede<parede+escada ){
        printf("\nO triangulo e valido");
        printf("\nO valor da escada e %0.3f", escada);
        printf("\nO valor da parede e %0.3f", parede);
    }
    else{
        printf("O triangulo e invalido");
    }    

    return 0;
}