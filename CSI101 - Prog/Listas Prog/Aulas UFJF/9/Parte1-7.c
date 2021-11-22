// Utilizando a estrutura medidas definida no exercício 2, faça um  programa  que  leia  a  altura  
// e  o  peso  de  6  pessoas  e imprima a média da altura e a média do peso do grupo.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

typedef struct{
    float peso;
    float altura;
}medida;

int main(){
    medida grupo[6];
    float acumuladorPeso = 0, acumuladorAltura = 0;

    for (int i = 0; i < 6; i++){
        printf("\n");

        printf("Digite a altura da pessoa %i: ", i+1);
        scanf("%f", &grupo[i].altura);
        
        printf("Digite o peso da pessoa %i: ", i+1);
        scanf("%f", &grupo[i].peso);

        acumuladorAltura = acumuladorAltura + grupo[i].altura;
        acumuladorPeso = acumuladorPeso + grupo[i].peso; 
    }

    printf("\nA media do peso do grupo de 6 pessoa e %f", acumuladorPeso/6);
    printf("\nA media da altura do grupo de 6 pessoa e %f", acumuladorAltura/6); 

    return 0;
}