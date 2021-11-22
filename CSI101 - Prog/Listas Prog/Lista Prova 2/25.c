//Faça uma função que receba uma string e um caractere e retorna o número de vezes que o caractere aparece na string.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int verifica(char n1[], char caractere){
   int cont = 0;

    for (int i = 0; n1[i] != '\0'; i++){ 
        if(n1[i] == caractere){
            cont++;
        }
    }

    return cont; 
    
}

int main(){
    char n1[10];
    char caractere;
    int numero;

    printf("Digite a string: ");
    fgets(n1, 10, stdin);

    printf("Digite o caractere a se procurar: ");
    scanf("%c", &caractere);

    numero = verifica(n1, caractere);

    printf("O numero de ocorrencia do caractere '%c' na string e %i", caractere, numero);

    return 0;
    
}

// strcpy(char destino[], char origem[])
// copia a string origem na string destino

// strlen(char str[])
// retorna o tamanho da string “str”

// strcat(char destino[], char origem[])
// faz concatenação (junção) da string origem
// com a string destino. O resultado é armazenado
// na string destino

// fgets(str,30,stdin);
// puts(str)