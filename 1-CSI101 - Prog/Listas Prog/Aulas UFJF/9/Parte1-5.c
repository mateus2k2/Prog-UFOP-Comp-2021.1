// a) Crie uma estrutura chamadapontocontendo apenas as coordenadas x e y(inteiros) do ponto. 
// b) Faça uma função que receba dois pontos por parâmetro e retorne a distância entre eles.
// c) Faça um programa que declare 2 pontos, leia as coordenadasxe yde cada um e chame a função criada 
//    para calcular a distância entre eles. Apresente no final a distância entre os dois pontos.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}coordenadas;

    int calculaDistancia(coordenadas cord1, coordenadas cord2){
        float distancia;

        distancia = sqrt((cord1.x-cord2.x)*(cord1.x-cord2.x)+(cord1.y-cord2.y)*(cord1.y-cord2.y));

        return distancia;
    }

int main(){
    coordenadas cord1, cord2;
    float distanica;

    printf("Digite a coordenada de x: ");
    scanf("%i", &cord1.x);

    printf("Digite a coordenada de y: ");
    scanf("%i", &cord1.y);

    printf("Digite a coordenada de x: ");
    scanf("%i", &cord2.x);

    printf("Digite a coordenada de y: ");
    scanf("%i", &cord2.y);

    distanica = calculaDistancia(cord1, cord2);

    printf("A distancia entre os pontos e %f", distanica);

    return 0;
}
