//Escreva uma função que recebe como parâmetro um número inteiro n. A função deve ler n valores do teclado e retornar quantos destes valores são negativos.

#include<stdlib.h>
#include<stdio.h>

int calculo(int numeroInteriro){

int numeroInteriroFixo;

numeroInteriroFixo = numeroInteriro;

    while (numeroInteriro <= (numeroInteriroFixo * numeroInteriroFixo)){
        
        if(numeroInteriro%numeroInteriroFixo==0){
        printf("\n%d e multiplo de %d", numeroInteriro, numeroInteriroFixo);
        }
        
        numeroInteriro++;
    }  

    return 0;
}

int main(){
    int numeroInteriro;

    printf("Digite um valor interio: ");
    scanf("%d", &numeroInteriro);

    calculo(numeroInteriro);

    return 0;

}


