
#include <stdio.h>

int calculo(float N1, float N2, int cod){

    float conta;

    switch (cod) {
    case 1: conta = N1 + N2;
    break;
    case 2: conta = N1 * N2;
    break;
    case 3: conta = N1 / N2;
    break;
    default: printf("Codigo invalido");
}

if (cod == 1 || cod == 2 || cod == 3){
    printf("%f", conta);
}
    return 0;
}

int main(){

    float N1, N2; 
    int cod;

    printf("Digite o primeiro numero: ");
    scanf("%f", &N1);

    printf("Digite o segundo numero: ");
    scanf("%f", &N2);

    printf("Digite o codigo: ");
    scanf("%d", &cod);

    calculo(N1, N2, cod);

    return 0;

}