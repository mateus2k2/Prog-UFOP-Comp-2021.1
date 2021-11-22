//Escrevauma função quereceba uma string e um caractere e retorne qual a última posição na string em que o caractere aparece. Se o caracter não estiver na string,a função deveretornar -1. 


#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int verifica(char n1[], char caractere){
   int iMaior = 0, j = 0;

    for (int i = 0; n1[i] != '\0'; i++){ 
        if(n1[i] == caractere){
            iMaior = i;
            j = 1;
            if(i > iMaior)
                iMaior = i;
        }


    }
    if(j == 0)
        return -1;

    return iMaior; 
    
}

int main(){
    char n1[10];
    char caractere;
    int indice;

    printf("Digite a string: ");
    fgets(n1, 10, stdin);

    printf("Digite o caractere a se procurar: ");
    scanf("%c", &caractere);

    indice = verifica(n1, caractere);

    printf("O maior indice que ocorre o caractere '%c' na string e %i", caractere, indice);

    return 0;
    
}