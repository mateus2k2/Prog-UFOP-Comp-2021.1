/*
Escrever um programa que leia uma string (com mais de
uma palavra) e faça com que a primeira letra de cada
palavra fique em maiúscula. Para isso, basta modificar
cada letra através da expressão:
chrNome[0] = chrNome[0] – 'a' + 'A';
Exemplo:
Entrada: lab. de linguagem de programacao
Saída: Lab. De Linguagem De Programacao
*/

#include <stdio.h>
#include <string.h>

int main(){
    char entrada[50] = "lab. de linguagem de programacao";

    for (int i = 0; entrada[i] != '\0'; i++){
        if(i == 0)
            entrada[0] = entrada[0] - 'a' + 'A';

        if(entrada[i - 1] == ' ')
            entrada[i] = entrada[i] - 'a' + 'A';
    }

    for (int i = 0; entrada[i] != '\0'; i++){
        printf("%c", entrada[i]);
    }

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