//Escreva uma função que recebe como parâmetro um número inteiro n. A função deve ler n valores do teclado e retornar quantos destes valores são negativos.

#include<stdlib.h>
#include<stdio.h>

int calculo(int numeroValores){

    int valorInt, quantidadeNegativos;

    quantidadeNegativos = 0; 

    while (numeroValores > 0){
        printf("Digite um valor interio: ");
        scanf("%d", &valorInt);

        if(valorInt < 0){
            quantidadeNegativos = quantidadeNegativos + 1;  
        }
        numeroValores--;
    }  

    printf("Dos valores que voce digitol %d sao negativos", quantidadeNegativos);
    return 0;
}

int main(){
    int numeroValores;

    numeroValores = 5;

    calculo(numeroValores);

    return 0;

}


