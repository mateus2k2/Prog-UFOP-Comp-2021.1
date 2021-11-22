//Você precisa fazer um programa para determinar se a soma de dois números é par ou é ímpar.
//Você deve fazer um programa que leia um par de números inteiros e apresente uma mensagem dizendo se o número é par ou ímpar. O programa deverá repetir até que a soma seja ímpar.


#include <stdlib.h>
#include <stdio.h>


int main(){
    int n1, n2, soma, cont = 0;

    while(cont==0){

        printf("Digite o primeiro numero: ");
        scanf("%i", &n1);

        printf("Digite o segundo numero: ");
        scanf("%i", &n2);

        soma = n1 + n2;

        if(n1%2==0)
            printf("\nO primeiro numero e par");
        else
            printf("\nO primeiro numero e impar");

        if(n2%2==0)
            printf("\nO segundo numero e par");
        else
            printf("\nO segundo numero e impar");

        if(soma%2 == 0)
            printf("\nA soma do primeiro numero com o segundo e par\n");
        else{
            printf("\nA soma do primeiro numero com o segundo e impar\n");
            cont=1;
        }
    }

    return 0;

}