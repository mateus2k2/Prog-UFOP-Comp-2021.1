// Write a program in C to print the array elements using recursion.

// Test Data :
// Input the number of elements to be stored in the array :6
// Input 6 elements in the array :
// element - 0 : 2
// element - 1 : 4
// element - 2 : 6
// element - 3 : 8
// element - 4 : 10
// element - 5 : 12

// Expected Output :
// The elements in the array are : 2  4  6  8  10  12 


#include <stdio.h>
#include <string.h>

void mostra(int vetor[], int comeco, int fim){
    if(comeco == fim)
        return;
         
    printf("%d  ", vetor[comeco]);

    mostra(vetor, comeco+1, fim);
}

int main(){
    int vetor[1000];
    int tamanho;

    printf("Digite o numero de elemento a serem armazenados no vetor: ");
    scanf("%i", &tamanho);

    for (int i = 0; i < tamanho; i++){
        printf("Digite o elemento %i: ", i);
        scanf("%i", &vetor[i]);
    }

    mostra(vetor, 0, tamanho);
    

}