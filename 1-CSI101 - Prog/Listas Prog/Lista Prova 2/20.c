//Implementeuma função que receba um vetor de inteiros e seu tamanho e ordene-o.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


void ordena(int n1[], int tamN1){
    int i, j;
    float aux;
    
    for(i = 0; i <= (tamN1-2); i++){
        
        for(j = tamN1-1; j > i; j--){
        
            if(n1[j] < n1[j-1] ){
                
                aux = n1[j];
                n1[j] = n1[j-1];
                n1[j-1] = aux;

                }
            }
        }
}

int main(){
    int n1[5], maior;

    for (int i = 0; i < 5; i++){
        printf("Digite um valor: ");
        scanf("%i", &n1[i]);
    }
    
    ordena(n1, 5);

    for (int i = 0; i < 5; i++)
        printf("%i\n",n1[i]);

    return 0;
    
}