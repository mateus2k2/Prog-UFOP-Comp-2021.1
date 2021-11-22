// Escreva um algoritmo que imprima todos os números de 1000 a 1999 que divididos por 11 dão resto igual a 5.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int main(){

    for (int i = 1000; i >= 1000 && i <= 1999; i++){
        if(i % 11 == 5)
            printf("\n%i dividido por 11 da resto igual a 5.", i);
    }
    
    return 0;
}