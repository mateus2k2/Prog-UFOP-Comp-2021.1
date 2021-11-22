// Entrdas: 
// Saidas: 
// Objetivo:  


#include <stdio.h>

int main()
{
    float valorDivida, valorJuros;
    int parcela;

    printf("Digite o valor da sua divida: ");
    scanf("%f", &valorDivida);
    printf("Quantidade de parcelas");
    scanf("%i", &parcela);

    //Determinar o valor dos juros dependendo do numero de parcelas
    if(parcela > 0 && parcela <= 2)
        valorJuros = 0.05;
    else if(parcela > 2 && parcela <= 4)
        valorJuros = 0.15;
    else if(parcela > 4 && parcela <= 7)
        valorJuros = 0.20;
    else if(parcela > 7 && parcela <= 10)
        valorJuros = 0.25;
    else if(parcela > 10 && parcela <= 13)
        valorJuros = 0.30;
    else
        printf("\nValor nao valido");

    //printf do valor da divida valor dos juros numero de parcelas e valor das parcelas. So usar um printf

    return 0;
}