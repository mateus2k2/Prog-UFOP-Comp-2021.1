/*
Faça um algoritmo que receba o valor do salário de uma pessoa e o valor de um financiamento pretendido. Caso o financiamento seja menor ou igual a 5 vezes o salário da pessoa, 
o algoritmo deverá escrever "Financiamento Concedido"; senão, ele deverá escrever "Financiamento Negado".
*/

#include <stdio.h>

int calculo(float valorsalario, float valorfinanciamento){

if(valorfinanciamento <= 5 * valorsalario){
    printf("Financiamento Concedido");
}
else{
    printf("Financiamento Negado");
}
}

int main(){

    float salario, financiamento;

    printf("Digite o seu salario: ");
    scanf("%f", &salario);

    printf("Digite o valor do financiamento desejado: ");
    scanf("%f", &financiamento);

    calculo(salario, financiamento);
} 