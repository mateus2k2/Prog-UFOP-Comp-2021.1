//Implemente uma função quereceba um vetor de inteiros e seu tamanho e retorne o maior elemento do vetor.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


int calcula(int n1[], int tamN1){
    int maior;

    for (int i = 0; i < tamN1; i++){
        if(i == 0)
            maior = n1[i];
        
        if(n1[i] > maior)
            maior = n1[i];
    }
    
    return maior;


}

int main(){
    int n1[5], maior;

    for (int i = 0; i < 5; i++){
        printf("Digite um valor: ");
        scanf("%i", &n1[i]);
    }
    
    maior = calcula(n1, 5);

    printf("O maior elemento do vetor e %i", maior);

    return 0;
    
}
