
#include <stdio.h>

float calculoDiametro(float raio){

    float diametro;
    diametro = 2 * raio;

    return diametro;
}

float calculoCircunferencia(float raio, float diametro){
    
    float circunferencia;
    circunferencia = 3.14159 * diametro;

    return circunferencia;

}

float calculoArea(float raio){
    
    float area;
    area = 3.14159 * raio * raio;

    return area;
}

void printResultado(float raio, float diametro, float circunferencia, float area){

    printf("\no circulo de raio %f tem diametro de %f, circunferencia de %f e area de %f", raio, diametro, circunferencia, area);

}

int main(){

    float raio, diametro, circunferencia, area, raio1, diametro1, circunferencia1, area1;

    printf("Insira o raio do circulo 1: ");
    scanf("%f", &raio);

    printf("Insira o raio do circulo 2: ");
    scanf("%f", &raio1);

    diametro = calculoDiametro(raio);
    circunferencia = calculoCircunferencia(raio, diametro);
    area = calculoArea(raio);
    printResultado(raio, diametro, circunferencia, area);

    diametro1 = calculoDiametro(raio1);
    circunferencia1 = calculoCircunferencia(raio1, diametro1);
    area1 = calculoArea(raio1);
    printResultado(raio1, diametro1, circunferencia1, area1);

    return 0;

}