// Você certamente já utilizou algum programa de compressão de arquivos (zip, rar, entre outros). 
// Estes programas normalmente precisam analisar os dados armazenados nos arquivos para saber a melhor forma de comprimí-los. 
// No caso de arquivos de texto, por exemplo, uma possível análise é verificar que letras ou símbolosaparecem com maior frequência no texto.

// a) Faça uma função que receba uma string e um vetor de inteiros de tamanho 128. 
// Em cada posição i do vetor de inteiros do parâmetro, a função deverá contabilizar 
// o número de vezes que o caractere de código i aparecerá no texto. Por exemplo, se a string for "AAAB", 
// o vetor deve ter o valor 3 na posição 65, 1 na posição 66 e 0 em todas as outras posições. Caracteres fora do intervalo entre 0 e 127 não precisam ser contabilizados.

// b) Faça uma função que receba um vetor de inteiros de tamanho 128 e um vetor de inteiros de tamanho 5.
// A função deve armazenar no segundo vetor o índice das posições que contém os 5 maiores valores do primeiro vetor(em qualquer ordem).

// c) Escreva um programa que leia um texto com até 1000 caracteres e imprima quais são os 5 símbolos mais frequentes.

#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main(){

    if (strstr("sent word", "word") != NULL)
        printf("found substring at address \n");
    else
        printf("no substring found!\n");

    exit(EXIT_SUCCESS);
}