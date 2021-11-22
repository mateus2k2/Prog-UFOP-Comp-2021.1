/*
Faça uma função que receba a quantidade de quilowatts consumido em uma casa e calcule o valor a ser pago de energia elétrica, 
sabendo-se que o valor a pagar por quilowatt é de R$ 0,46. Apresentar o valor total a ser pago pelo usuário acrescido de 18% de ICMS.
*/

#include <stdio.h>

float calculoKw(float kw){

    float calculoKw = (kw * 0.46) * 1.18;

    return calculoKw;

} 

float main(){

    float quantidaeKw, kwPagar;

    printf("Digite a quantidade de quilowatt consumidos na residencia: ");
    scanf("%f", &quantidaeKw);

    kwPagar = calculoKw(quantidaeKw);

    printf ("O valor a se pago de energia e %f, considerando 0.46 reais por KW menos 18% do ICMS", kwPagar);

    return 0;
}


