#define TAMANHO 5

#include <stdio.h>
 
void reverse(int vet[], int tamVet){
    int temp;
    int high;

    high = tamVet - 1;
    
    for (int low = 0; low < high; low++, high--){
        temp = vet[low];

        vet[low] = vet[high];
        vet[high] = temp;
    }

    for (int i = 0; i < tamVet; i++){
        printf("%d ", vet[i]);
    }
}
 
int main(void)
{
    int vet[5] = { 1, 2, 3, 4, 5 };
 
    reverse(vet, 5);
 
    return 0;
}