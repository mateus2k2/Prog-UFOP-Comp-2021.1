//Escrevauma função que receba um vetor de valores reais e seu tamanho e retorne quantos destes valores são negativos.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


int calcula(int n1[], int tamN1){
    int cont = 0;

    for (int i = 0; i < tamN1; i++){
        if(n1[i] < 0)
            cont++;
    }
    
    return cont;


}

int main(){
    int n1[5], negativos;

    for (int i = 0; i < 5; i++){
        printf("Digite um valor: ");
        scanf("%i", &n1[i]);
    }
    

    negativos = calcula(n1, 5);

    printf("O numero de negativos no vetor e %i", negativos);

    return 0;
    
}