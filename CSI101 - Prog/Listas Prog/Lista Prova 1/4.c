/*
Calcule o salário líquido do funcionário sabendo que este é constituído pelo salário bruto mais o valor das horas extras subtraindo 8% de INSS do total. 
Serão lidos nesse problema o salário bruto, o valor das horas extras e o número de horas extras. Apresentar ao final o salário líquido.
*/

#include <stdio.h>

float calculoSalarioLiquido (float salario, float horas, float valor){

    float calculoSalarioLiquido = (salario + (horas * valor)) * 0.92;  

    return calculoSalarioLiquido;
}

float main(){
    
    float salarioBruto, salarioLiquido, valorExtra, numeroExtra;
    printf("Digite o seu salario bruto: ");
    scanf("%f", &salarioBruto);

    printf("Digite valor das horas extras: ");
    scanf("%f", &valorExtra);

    printf("Digite o numero de horas extras realizadas: ");
    scanf("%f", &numeroExtra);

    salarioLiquido = calculoSalarioLiquido(salarioBruto, valorExtra, numeroExtra);
    
    printf("O seu salario liquido e de %f , considereando o salario bruto de %f , com %f horas extras no valor de %f cada, menos 8% do INSS", salarioLiquido, salarioBruto, numeroExtra, valorExtra); 

    return 0;

}