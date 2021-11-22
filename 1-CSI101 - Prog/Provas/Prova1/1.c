//Matrícula 20.2.8093
//Nome: Mateus Filipe Moreira Silva

/*
Na aula de matemática o professor pediu para você fazer um programa para verificar se três medidas podem ser lados de um triângulo. 
Este programa deve receber o valor dos catetos de um triângulo, calcular e mostrar o valor da hipotenusa. O programa deverá conferir 
se os valores dos catetos são consistentes, ou seja, a soma de dois catetos quaisquer não é maior do que o que sobrou. Caso os valores 
sejam inconsistentes deverá mostrar uma mensagem para o usuário informando que os valores são inconsistentes.
*/

//


#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
   
    float lado1, lado2, lado3;

    //Entrada do lado1 e lado2 (Catetos)
    printf("Digite o valor do primeiro lado: ");
    scanf("%f", &lado1);

    printf("Digite o valor do segundo lado: ");
    scanf("%f", &lado2);

    //Calculo do lado3(Hipotenusa) com Bhaskara
    lado3 = sqrt(lado1*lado1 + lado2*lado2);

    //Verifica a consistencia dos lados desse triangulo
    //Redundante, ja que entrando com dois lados e calculando o tenceiro com Bhaskara jamais o triangulo entrará na consição de nao existencia. Independente dos valores do lado1 e lado2
    if(lado1<lado2+lado3 && lado2<lado1+lado3 && lado3<lado1+lado2 ){
        printf("\nO triangulo e valido");
        printf("\nO valor da hipotenusa e %0.1f", lado3);
    }
    else{
        printf("O triangulo e invalido");
    }

    return 0;
}