/*
Escreva uma função que leia os valores n1, n2 e x, e imprima os múltiplos de x que pertencem ao 
intervalo fechado entre n1 e n2, em ordem crescente. Exemplo: se os valores lidos forem n1=1, n2=7 e x=3, a saída deverá ser 3 6 .
*/

#include <stdio.h>

int calculo(int n1, int n2, int x){

    while (n1 < n2){
        
    if(n1%x==0){
        printf("%d ", n1);
    }
        
    n1++;
}

    if(n2%x==0)
    printf("%d ", n2);

return 0;

}


int main(){

    float n1, n2, x;

    printf("Digite o numero 1 menor: ");
    scanf("%f", &n1 );

    printf("Digite o numero 2 maior: ");
    scanf("%f", &n2 );

    printf("Digite o numero a ser visto: ");
    scanf("%f", &x );

    calculo(n1, n2, x);

    return 0;
}

