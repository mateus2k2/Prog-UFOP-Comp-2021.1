
#include <stdio.h>

float calculo(float p1, float p2){

    float p3;

    p3 = (- p1 - p2 + 20) / 2;
    
    printf("\nCALCULO DE NOTA PARA APROVACAO");
    printf("\nNota na 1a prova: %f", p1);
    printf("\nNota na 2a prova: %f", p2);
    printf("\nNota necessaria: %f", p3);

    return p3;     
}

int main(){
    
    float p1, p2;

    printf("Digite a nota da primeira prova: ");
    scanf("%f", &p1);

    printf("Digite a nota da segunda prova: ");
    scanf("%f", &p2);

    calculo(p1, p2);

    return 0;

}