// Elabore uma função que receba como parâmetros dois valores reais a e b.
// A função deve ler uma sequência de valores reais e imprimir a média aritmética dos valores que pertencerem ao intervalo fechado entre a e b.
// A sequência de valores deverá ser encerrada quando for lido um valor negativo. Exemplo: Com entradas a=7, b=3 e sequência= 5 2 9 8 3 1 -2, a função deve imprimir o valor 4.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int verificador(int a, int b){
    int media = 0, valor = 1, cont = 0;

    printf("\n");

    while (valor > 0){
        printf("Digite um valor: ");
        scanf("%i", &valor);

        if(valor >= a && valor <= b){
            media = media + valor;
            cont++;
        }

    }

    media = media / cont;
    

    return media;
}

int main(){
    int a, b, media;

    printf("Digite o inicio do intervalo: ");
    scanf("%i", &a);

    printf("Digite o final do intervalo: ");
    scanf("%i", &b);

    media = verificador(a, b);

    printf("\nO retorno e %i", media);

    return 0;

}