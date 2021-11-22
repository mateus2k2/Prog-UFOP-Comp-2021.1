// Utilizando a estrutura ponto definida no exercício 5, faça uma função que receba 2 pontos e retorne o ponto mais próximo da origem. 
// Em seguida, modifique o programa principal para ler 4 pontos e imprimir apenas as coordenadas do ponto mais próximo da origem.Exercícios

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}coordenadas;

coordenadas calculaDistancia(coordenadas cord1, coordenadas cord2){
    coordenadas distanciaMenor;
    float distancia;

    distancia = sqrt((cord1.x-cord2.x)*(cord1.x-cord2.x)+(cord1.y-cord2.y)*(cord1.y-cord2.y));

    if(sqrt((cord1.x)*(cord1.x)+(cord1.y)*(cord1.y)) > sqrt((cord2.x)*(cord2.x)+(cord2.y)*(cord2.y)))
        return cord2;
    else
        return cord1;
    }

int main(){
    coordenadas cord1, cord2, cord3, cord4;
    coordenadas distanciaMenor;

    printf("Digite a coordenada de x: ");
    scanf("%i", &cord1.x);

    printf("Digite a coordenada de y: ");
    scanf("%i", &cord1.y);

    printf("Digite a coordenada de x: ");
    scanf("%i", &cord2.x);

    printf("Digite a coordenada de y: ");
    scanf("%i", &cord2.y);

    printf("Digite a coordenada de x: ");
    scanf("%i", &cord3.x);

    printf("Digite a coordenada de y: ");
    scanf("%i", &cord3.y);

    printf("Digite a coordenada de x: ");
    scanf("%i", &cord4.x);

    printf("Digite a coordenada de y: ");
    scanf("%i", &cord4.y);

    distanciaMenor = calculaDistancia(calculaDistancia(cord1, cord2), calculaDistancia(cord3, cord4));

    printf("O ponto (%i, %i)", distanciaMenor.x, distanciaMenor.y);

    return 0;
}