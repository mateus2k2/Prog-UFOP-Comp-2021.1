//Você deverá fazer um programa que receba um vetor A de no máximo 100 posições de valores inteiros. 
//O seu programa deverá ter uma função que receba este vetor e mostre, quais elementos de A estão repetidos.
//A sua função deverá retornar quantos números repetidos tem no vetor.



#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


int contaRepetidos(int vet[], int tamVet, int tamanho){
    int cont=0;
    int i, j;

    for (i = 0; i < tamanho; i++){

        for (j = 0; j < 5; j++){
            if(i==j)
                j++;

            if(vet[i]==vet[j]){
                printf("\nElemento %i e %i repetidos", i, j);
                cont++;
            }
        }
    }
    
    return cont;
}

int main(){
    int vet[100], repetidos, tamanho;
    
    printf("Digite o tamanho do vetor (Ate 100): ");
    scanf("%i", &tamanho);

    printf("\n");

    for (int i = 0; i < tamanho; i++){
        printf("Digite o valor do vetor posicao %i: ", i);
        scanf("%i", &vet[i]);
    }

    repetidos = contaRepetidos(vet, 100, tamanho);
    
    printf("\n");
    printf("\nO numero de elemtnos repetidos e %i", repetidos);
    

return 0;

}