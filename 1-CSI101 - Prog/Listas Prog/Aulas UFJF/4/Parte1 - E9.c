#include <stdio.h>

float calculo(float precoCusto){

    float precoReajustado;

    if(precoCusto > 0){
    if (precoCusto <= 2)
        precoReajustado = precoCusto + 0,15;
    if (precoCusto > 2 && precoCusto <= 5)
        precoReajustado = precoCusto * 1.02;
    if (precoCusto > 5 && precoCusto <= 20)
        precoReajustado = precoCusto * 1.1;
    if (precoCusto > 20)
        precoReajustado = precoCusto * 1.08;
    }
    else{
        printf("Prco negativo invalido");
    }

    printf("%f", precoReajustado);
}

int main(){
    
    float precoCusto;

    printf("Digite o preço custo: ");
    scanf("%f", &precoCusto);

    calculo(precoCusto);

    return 0;
}