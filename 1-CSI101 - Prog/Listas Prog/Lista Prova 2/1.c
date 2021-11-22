/*
Escreva uma função que recebe como parâmetro um número inteiro n. A função deve ler n valores do teclado e retornar quantos destes valores são negativos.
*/


#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int verificador(int n){
    int negativos = 0;
    int numero;

    for (int i = 0; i < n; i++){
    
        printf("Digite o numero: ");
        scanf("%i", &numero);

        if(numero < 0)
            negativos++;
    }
    return negativos;    
}

int main(){
    int n, quantidadeNegativos;

    printf("Digite o numero de valores a serem lidos no teclado: ");
    scanf("%i", &n);

    quantidadeNegativos = verificador(n);

    printf("A quantidade de negativos e: %i", quantidadeNegativos);

    return 0;

}