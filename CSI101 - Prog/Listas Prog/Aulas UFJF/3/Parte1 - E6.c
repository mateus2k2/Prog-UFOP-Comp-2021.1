
#include <stdio.h>

int calculoDistancia(int x1, int y1, int x2, int y2, int x3, int y3){

    int distancia1, distancia2, perimetro;

    distancia1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    distancia2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));

    perimetro = distancia1 + distancia2; 

    printf("\n%d", perimetro);

    return 0;
}

int main(){
    
    int x1, y1, x2, y2, x3, y3;

    printf("\nDigite o primeiro vertice do triangulo: ");
    scanf("%d %d", &x1, &y1);

    printf("\nDigite o segundo vertice do triangulo: ");
    scanf("%d %d", &x2, &y2);

    printf("\nDigite o terceiro vertice do triangulo: ");
    scanf("%d %d", &x3, &y3);

    calculoDistancia(x1, y1, x2, y2, x3, y3);

    return 0;
}