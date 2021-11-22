/*
Faça a leitura do salário atual e do tempo de serviço de um funcionário. A seguir, em uma função, calcule o seu salário reajustado. Funcionários com até 1 ano de empresa, 
receberão aumento de 10%. Funcionários com mais de um ano de tempo de serviço, receberão aumento de 20%. A função deverá retornar o salário reajustado.
*/

#include <stdio.h>

float reajuste(float sal, float temp){

    float reajuste;

    if(temp > 1){
        reajuste = sal * 1.2;
    }
    else{
        reajuste = sal * 1.1;
    }

    return reajuste;

}

int main(){

    float salario, tempo, salarioReajustado; 

    printf("Digite o seu salario atual: " );
    scanf("%f", &salario);

    printf("Digite o tempo de servico: " );
    scanf("%f", &tempo);

    salarioReajustado = reajuste(salario, tempo);

    printf("Seu salario reajustado e: %f", salarioReajustado);

    return 0;

}