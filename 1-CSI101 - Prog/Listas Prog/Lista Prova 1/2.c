/*
Crie uma função que calcule o aumento que será dado a um funcionário. Esta função receberá como parâmetro o salário atual do funcionário e a porcentagem de aumento. 
A função deverá, ao final, imprimir o novo valor do salário e o valor do aumento.
*/

//Arrumar nome das variáveis

#include <stdio.h>

//calcular o aumento
float aumento(float x, float y) {
    float aumento = (x * (y/100)) + x;

    return aumento; 
}

float aumentovalor(float x, float y) {
    float aumentovalor = (x * (y/100));

    return aumentovalor;
}

int main() {
    
    /* 
    salario = salario atual
    aumentop = porcentegem de aumento
    aumentov = valor do aumento
    salarion = salario novo  
    */
    float salario, aumentop, aumentov, salarion;

    printf("Entre com o salário atual: ");
    scanf("%f", &salario);

    //porcentagem de aumento. Ex: 50, 60 
    printf("Entre com a porcentagem de aumento: ");
    scanf("%f", &aumentop);

    salarion = aumento(salario, aumentop);
    aumentov = aumentovalor (salario, aumentop);

    printf ("Seu novo salario e: %f. Ele teve um aumento de %f.", salarion, aumentov);    

    return 0;
}
