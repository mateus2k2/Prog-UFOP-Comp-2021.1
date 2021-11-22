#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



int main () {
    int num; 
    long long resultado;

    printf("Digite um numero: ");
    scanf("%d", &num);

    resultado = fat(num);

    printf("O fatorial de %d eh igual a: %ld\n", num, resultado);

    return 0;
}

int fat (int num){

    if(num == 0) {
        return 1;
    } else {
        return (num * fat(num - 1));
    }
}