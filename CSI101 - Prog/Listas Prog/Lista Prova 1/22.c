/*
Escreva um algoritmo que imprima todos os números de 1000 a 1999 que divididos por 11 dão resto igual a 5.
*/

#include<stdlib.h>
#include<stdio.h>

    int main() {
        
//    int n;  

    for (int n = 1000; n <= 1999; n++) {  
        
    if(n%11==5){  
        printf ("\n --> %d / 11 tem como resto 5",n);
        }  
    }  
} 