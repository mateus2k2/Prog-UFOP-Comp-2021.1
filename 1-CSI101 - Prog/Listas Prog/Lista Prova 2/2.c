/*
Faça uma função que recebe um valor N inteiro e que, se N for positivo, retorna o fatorial de N (N!). Se não for possível calcular o fatorial, a função deve imprimir uma mensagem e retornar o valor -1.
*/


#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int verificador(int n){
    int fatorial;

    if(n > 0){
        for(fatorial = 1; n > 1; n = n - 1)
            fatorial = fatorial * n;
        return fatorial;
    }
        
    else{   
        printf("Nao e posivel calcular o fatorial de %i", n);
        return -1;
    }
}

int main(){
    int n, retorno;

    printf("Digite o numero a ser fatorado: ");
    scanf("%i", &n);

    retorno = verificador(n);

    printf("\nO retorno e %i", retorno);

    return 0;

}