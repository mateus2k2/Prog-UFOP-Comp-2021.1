// Você deverá fazer um programa que receberá o salário de um funcionário. O programa deve calcular e mostrar  quantidade de salários mínimos que esse funcionário ganha. 
// O usuário deverá também digitar o valor do salário mínimo. O seu programa deverá verificar se o usuário não digitou nenhum dos dois dados iguais a zero.

/*
NOME: Mateus Filipe Moreira Silva
Matricula: 20.2.8093
*/

#include <stdio.h>
#include <string.h>

int main(){
    int salarioMinimo, salario;

    printf("Digite o valor do salario minimo: ");
    scanf("%i", &salarioMinimo);

    printf("Digite o valor do salario: ");
    scanf("%i", &salario);

    if(salarioMinimo <= 0 || salario <= 0){
        printf("Valor imputado invalido, saindo...");
        return 0;
    }

    if(salario == salarioMinimo)
        printf("Voce ganha 1 salario minimos");
    if(salario > salarioMinimo)
        printf("Voce ganha %i salarios minimos e %i", salario/salarioMinimo, salario % salarioMinimo);
    if(salarioMinimo > salario)
        printf("Faltam %i para voce ganhar um salario minimo", salarioMinimo-salario);

    return 0;
}