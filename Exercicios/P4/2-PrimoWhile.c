//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <stdlib.h>
#include <stdio.h>

int is_prime(int n);

int main(){
    int numero;

        printf("\nDigite um numero: ");
        scanf("%i", &numero);
        
    if(is_prime(numero) == 0)
        printf("\n%i e um numero primo!", numero);
    else
        printf("\n%i NAO e um numero primo", numero);

}

int is_prime(int n){

    if(n%2 == 0 && n != 2){      
        return 1;
    }

    if(n == 2){
        return 0;    
    }

    int j = 2;
    while (j < n){
        
        if(n % j == 0)
            return 1;

        if(j == n - 1){
            return 0;
        }

    j++;
    }
}