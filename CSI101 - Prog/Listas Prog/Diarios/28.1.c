//Entrada: um numero inteiro qualquer
//Objetivo: calcular incremesto sucecivos dessse numero no modelo  (Ex.: 3 + 3 = ++(+ + (+ + 3))) usando uma função recurciva.
//Saida: o numero inteiro qulquer incrementado nele mesmo 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int incrementa(int numero, int numeroORG){
    int cont = 0;

    if(cont == numero){
        return cont;
        printf("%i", cont);
    }
    else{ 
        cont++;
        return cont + incrementa(numero-1, numeroORG);
    }

}

int main(){
    int numero, numeroORG;
    int soma;

    printf("Digite um numero para ser somado com ele mesmo usando uma recurcao: ");
    scanf("%i", &numero);

    numeroORG = numero;

    soma = incrementa(numero, numeroORG);

    printf("Soma %i", soma);

    return 0;

}