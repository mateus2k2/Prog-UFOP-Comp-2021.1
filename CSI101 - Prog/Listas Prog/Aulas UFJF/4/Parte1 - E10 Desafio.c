
#include <stdio.h>

float calculoCusto(int cod){

    float custo;

 switch (cod) {
    case 54: custo = 1.90;
    break;
    case 598: custo = 1.90;
    break;
    case 595: custo = 1.90;
    break;
    case 56: custo = 1.90;
    break;
    case 49: custo = 2.00;
    break;
    case 33: custo = 2.00;
    break;
    case 44: custo = 2.00;
    break;
    case 1: custo = 2.30;
    break;
    default: custo = 2.30;
}

return custo;

}


void calculoAumento(float custo, int min){

    float resultado;

    if(min > 5){
//      resultado = (5 * custo) + ((min - 5)*custo)*0.95;
        resultado = (5 * custo) + (custo*0.95)*min;
    }
    else{
        resultado = (min * custo);
    }

    printf("%f", resultado);
}

int main(){
     
    float custo;
    int cod, min;

    printf("Digite o prexido da ligacao: ");
    scanf("%i", &cod);

    printf("Digite a duracao da ligacao: ");
    scanf("%i", &min);


    custo = calculoCusto(cod);
    calculoAumento(custo, min);

    return 0;

    

}