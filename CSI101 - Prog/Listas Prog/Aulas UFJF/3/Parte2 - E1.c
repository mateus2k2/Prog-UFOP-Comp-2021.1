
#include <stdio.h>

float calculoParcelas(float valorCompra, float numeroParcelas){

    float valorParcela;

    valorParcela = valorCompra / numeroParcelas;

    printf("\nCOMPRAR A PRAZO");
    printf("\nO valor da comprar: %f", valorCompra);
    printf("\nNumero de parcelas: %f", numeroParcelas);     
    printf("\nO valor de cada parcela: %f", valorParcela); 
}

int main(){
    
    float valorCompra, numeroParcelas;

    printf("Digite o valor da comprar: ");
    scanf("%f", &valorCompra);

    printf("Digite o numero de parcelas: ");
    scanf("%f", &numeroParcelas);

    calculoParcelas(valorCompra, numeroParcelas);

    return 0;

}