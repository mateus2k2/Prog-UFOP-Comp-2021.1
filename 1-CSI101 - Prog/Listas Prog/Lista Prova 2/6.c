// Escreva uma função que leia os valores n1, n2 e x, e imprima os múltiplos de x que pertencem ao intervalo fechado entre n1 e n2, 
// em ordem crescente. Exemplo: se os valores lidos forem n1=1, n2=7 e x=3, a saída deverá ser 3 6 .

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void tabuada(int n1, int n2, int x){
    int i = 1;
    
    printf("\n");

    while(n1 * x <= n2){

        printf("%i ", x * n1);
        n1++;
    }
    

}

int main(){
    int n1, n2, x;

    printf("Digite o inicio do intervalo: ");
    scanf("%i", &n1);

    printf("Digite o fim do intervalo: ");
    scanf("%i", &n2);

    printf("Digite o numero a se rverificado: ");
    scanf("%i", &x);

    tabuada(n1, n2, x);

    return 0;

}