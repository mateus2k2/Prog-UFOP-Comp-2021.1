//Escrevauma função que retorna o número de inteiros ímpares que existem entre n1e n2(inclusive ambos, se for o caso). A função deve funcionar inclusive se o valor de n2 for menor que n1.


#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


int calcula(int n1, int n2){
    int temp, cont = 0;

    if(n1 > n2){
        temp = n1;
        n1 = n2;
        n2 = temp;
    }

    for (int i = 0; n1 <= n2; n1++){
        if(n1 % 2 != 0)
            cont++;
    }
    
    return cont;


}

int main(){
    int n1, n2, impares;

    printf("Digite o primeiro numero do o intervalo: ");
    scanf("%i", &n1);

    printf("Digite o segundo numero do o intervalo: ");
    scanf("%i", &n2);

    impares = calcula(n1, n2);

    printf("O numero de inteiros impares no intervalo e %i ", impares);

    return 0;
    

}