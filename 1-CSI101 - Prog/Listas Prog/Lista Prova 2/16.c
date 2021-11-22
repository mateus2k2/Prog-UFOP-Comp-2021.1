//Escrevauma funçãoque imprime todos os divisores de umnúmero inteiro passado por parâmetro. 

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


void calcula(int n1){
    for (int i = 1; i <= n1 ; i++){
        if(n1 % i == 0)
            printf("\n%i e divisor de %i", i, n1);
    }
}

int main(){
    int n1;

    printf("Digite o numero: ");
    scanf("%i", &n1);

    calcula(n1);

    return 0;
    

}