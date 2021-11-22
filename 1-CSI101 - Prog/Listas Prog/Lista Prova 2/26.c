//Elaboreuma função que recebaduas strings, strA e strB,  e o tamanho alocado para ambas,t. 
// A função deve completar a string strAcom os caracteres da string strB sem que o tamanho máximo da string seja ultrapassado.
// Exemplo:  se strA="ABC",strB="XYWZ"e t=6, ao final da função, deve-se ter strA="ABCXY".

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void junta(char strA[], char strB[], int tam){
    int j = 0;
    int i = tam;

    for (i = tam - 1; i < 5; i++){ 
        strA[i] = strB[j];
        j++;
    }
    strA[i] = '\0';    

    printf("A nova string e: ");
    puts(strA);
}

int main(){
    char strA[6];
    char strB[6];
    int tam;

    printf("Digite a string A: ");
    fgets(strA, 6, stdin);

    printf("Digite a string B: ");
    fgets(strB, 6, stdin);

    tam = strlen(strA);

    junta(strA, strB, tam);

    return 0;
    
}