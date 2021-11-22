//Fazer um programa para criar e imprimir uma string que será a concatenação de duas outras strings lidas.

// strcat(char destino[], char origem[])
// faz concatenação (junção) da string origem
// com a string destino. O resultado é armazenado
// na string destino

#include <stdio.h>
#include <string.h>

int main(){
    char str1[10], str2[10], str3[20];

    printf("Digite a primeira string: ");
    fgets(str1, 10, stdin);

    printf("Digite a primeira string: ");
    fgets(str2, 10, stdin);

    strcat(str1, str2);

    puts(str1);

    return 0;


}