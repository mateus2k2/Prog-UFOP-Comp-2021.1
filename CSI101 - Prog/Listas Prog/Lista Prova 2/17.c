// Escrevauma função que, dados dois números inteiros n1 e n2,retorna a soma dos números inteiros que existem no intervalo fechado entre n1e n2. 
// A função deve funcionar inclusive se o valor de n2 for menor que n1.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


int calcula(int n1, int n2){
    int soma = 0, temp;

    if(n1 > n2){
        temp = n1;
        n1 = n2;
        n2 = temp;
    }

    for (int i = 0; n1 <= n2; n1++){
        soma = soma + n1;
    }
    
    return soma;


}

int main(){
    int n1, n2, soma;

    printf("Digite o primeiro numero do o intervalo: ");
    scanf("%i", &n1);

    printf("Digite o segundo numero do o intervalo: ");
    scanf("%i", &n2);

    soma = calcula(n1, n2);

    printf("A soma dos inteiros no intervalo e %i ", soma);

    return 0;
    
}