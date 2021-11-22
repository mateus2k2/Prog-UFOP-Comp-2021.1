//implemente uma função que, dados um vetor de valores reais e seu tamanho, retorne a média dos valores armazenados

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

float calcula(int n1[], int tamN1){
    float media = 0;

    for (int i = 0; i < tamN1; i++){
        media = media + n1[i];
    }
    
    media = media / tamN1;
    
    return media;

}

int main(){
    int n1[5];
    float media;

    for (int i = 0; i < 5; i++){
        printf("Digite um valor: ");
        scanf("%i", &n1[i]);
    }
    
    media = calcula(n1, 5);

    printf("O media dos valores e %.2f", media);

    return 0;
    
}