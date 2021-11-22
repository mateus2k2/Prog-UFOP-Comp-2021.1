//Escreva uma função que recebe como parâmetro um número inteiro n. A função deve ler n valores do teclado e retornar quantos destes valores são negativos.

#include<stdlib.h>
#include<stdio.h>

int calculo(int n1, int n2){

    printf("%d ", n2);

    while (n1 < n2){
        
    printf("%d ", n2 - 1);
        
    n2--;
    }

  

    return 0;
}

int main(){
    int n1, n2;

    printf("Digite o primeiro valor (menor): ");
    scanf("%d", &n1);

    printf("Digite o segundo valor (maior): ");
    scanf("%d", &n2);

    calculo(n1, n2);

    return 0;

}


