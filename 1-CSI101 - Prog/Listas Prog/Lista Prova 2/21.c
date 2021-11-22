//Elaboreuma função que recebe por parâmetro um vetor de inteiros e o seu tamanho e retorna a soma de seus elementos. 

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int calcula(int n1[], int tamN1){
    int soma = 0;

    for (int i = 0; i < tamN1; i++){
        soma = soma + n1[i];
    }
    
    return soma;

}

int main(){
    int n1[5], soma;

    for (int i = 0; i < 5; i++){
        printf("Digite um valor: ");
        scanf("%i", &n1[i]);
    }
    
    soma = calcula(n1, 5);

    printf("O maior elemento do vetor e %i", soma);

    return 0;
    
}