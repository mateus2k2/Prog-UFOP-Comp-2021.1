//Matrícula 20.2.8093
//Nome: Mateus Filipe Moreira Silva

/*
Um aluno quer fazer um programa para determinar se um triângulo é isóceles, escaleno ou equilátero baseado apenas nos três lados. 
Faça um programa que receba os três lados de um triângulo verifique se os três lados realmente são de um triângulo, 
lembrando que a soma de quaisquer dois lados de um triângulo tem que ser maior do que o terceiro lado. Deve ser mostrada uma mensagem para o usuário informando qual o tipo do triângulo.


*/

//


#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int lado1, lado2, lado3;


    //Entradas dos lados
    printf("Digite o valor do primeiro lado: ");
    scanf("%i", &lado1);

    printf("Digite o valor do segundo lado: ");
    scanf("%i", &lado2);

    printf("Digite o valor do terceiro lado: ");
    scanf("%i", &lado3);

    //Verifica a consição de exiatencia do triangulo
    //Verifica o tipo do triangulo
    if(lado1<lado2+lado3 && lado2<lado1+lado3 && lado3<lado1+lado2 ){
        printf("\n\nO triangulo e valido");
        
        if(lado1!=lado2 && lado1!=lado3 && lado2!=lado3)
            printf("\nO triangulo e escaleno");
        if((lado1==lado2 || lado1==lado3 || lado2==lado3) && (lado1!=lado2 || lado1!=lado3 || lado2!=lado3))
            printf("\nO triangulo e isosceles");
        if(lado1==lado2 && lado1==lado3 && lado2==lado3)
            printf("\nO triangulo e equilatero");
    }
    else{
        printf("\nO triangulo e invalido");
    }

    return 0;
}