
#include <stdio.h>

int calculoRaio(int raio){

float resultado; 

resultado = 3.14 * raio * raio;

return resultado;
}

int main(){

    float raio, resultado;
    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);

    resultado = calculoRaio(raio);

    printf("O raio do circulo e %f", resultado);

    return 0;
}