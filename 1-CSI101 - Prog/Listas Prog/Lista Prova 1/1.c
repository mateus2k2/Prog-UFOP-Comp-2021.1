//Faça uma função que retorne a soma de dois números reais passados como parâmetro.

#include <stdio.h>

int soma(int a, int b) {
    int soma;
    soma = a + b;

    return soma;
}

int main(){
    int primeiroNum = 1, segundoNum = 1, resultado = 0;
    resultado = soma(primeiroNum, segundoNum);
    printf("soma de %d com %d eh igual a %d", primeiroNum, segundoNum, resultado); 
    return 0;   
}
