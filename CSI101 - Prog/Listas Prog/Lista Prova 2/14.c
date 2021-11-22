// Escreva uma função para calcular o valor de E: 
// E = 1 + 1 / 1! + 1 / 2! + 1 / 3! + ... + 1 / (k-1)! + 1 / k! 

// A função deve ler um valor real x representando o valor máximo (tolerância) para a diferença entre dois termos consecutivos. 
// Isto é, o cálculo do valor de E deve ser computado até que | 1/k! – 1/(k+1)! | < x . Imprima cada termo gerado e o resultado de E ao final. 
// OBS: inicialmente faça o cálculo do fatorial dentro da própria função. Depois, modifique seu código para obter o fatorial chamando a função do exercício 2.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

//--------------------------------

int fatorial(int n){
    int fatorial;

    if(n > 0){
        for(fatorial = 1; n > 1; n = n - 1)
            fatorial = fatorial * n;
        return fatorial;
    }
        
    else{   
        printf("\n");
        printf("\nNao e posivel calcular o fatorial de %i", n);
        return -1;
    }
}

//--------------------------------

void calculo(float x){
    float e = 1.0;

    //abs( 1.0/fatorial(i) - 1.0/fatorial(i+1) )

    for (int i = 1; i < x; i++){
        e = e + 1.0/fatorial(i); 
        printf("\n i --- %i E ---- %f", i, e);
    }

    printf("\nO valor de e E %f", e);


}

//--------------------------------

int main(){
    float x;

    printf("Digite um valor: ");
    scanf("%f", &x);

    calculo(x);

    return 0;
}
