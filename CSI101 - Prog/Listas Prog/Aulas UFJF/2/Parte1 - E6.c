
#include <stdio.h>

int main(){
    float salarioMinimo, salarioFuncionario, numeroSalarioMinimo, restoSalario;

    printf("Digite o seu salario: ");
    scanf("%f", &salarioFuncionario);

    printf("Digite o seu salario minimo: ");
    scanf("%f", &salarioMinimo);

    numeroSalarioMinimo = salarioFuncionario / salarioMinimo;
    printf("Voce ganha %f salario minnimos", numeroSalarioMinimo);

    return 0;


}