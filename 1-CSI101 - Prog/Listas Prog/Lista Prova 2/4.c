// Escreva uma função que leia do teclado um valor n e imprima todos os múltiplos de n no intervalo entre n e seu quadrado, em forma de tabuada, como o exemplo abaixo (n=4):
// 1 x 4 = 4
// 2 x 4 = 8
// 3 x 4 = 12
// 4 x 4 = 16

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void tabuada(int a){
    int mult = 0;
    int i = 1;

    printf("\n");

    while(mult != a * a){
        mult = a * i;
        printf("\n%i X %i = %i", i, a, mult);
        i++;
    }
    

}

int main(){
    int a;

    printf("Digite o numero: ");
    scanf("%i", &a);

    tabuada(a);

    return 0;

}