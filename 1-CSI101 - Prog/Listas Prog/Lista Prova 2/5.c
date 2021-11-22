// Escreva uma função que leia os valores n1 e n2 e imprima o intervalo fechado entre esses dois valores. Exemplo: se os valores lidos forem 5 e 2, a saída deverá ser 5 4 3 2.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void tabuada(int n1, int n2){
    printf("\n");

    while(n2 >= n1 ){
        printf("%i ", n2);
        n2--;
    }
    

}

int main(){
    int n1, n2;

    printf("Digite o inicio do intervalo: ");
    scanf("%i", &n1);

    printf("Digite o fim do intervalo: ");
    scanf("%i", &n2);

    tabuada(n1, n2);

    return 0;

}