// Escreva uma função que leia um número n que indicará a quantidade de números inteiros positivos que devem ser lidos a seguir. 
// A função deve imprimir uma tabela de n linhas onde cada linha deve conter um dos valores inteiros lidos seguido de seu dobro, seu quadrado e seu fatorial. 
// OBS: inicialmente faça o cálculo do fatorial dentro da própria função. Depois, modifique seu código para obter o fatorial chamando a função do exercício 2. 
// Exemplo: se os valores lidos forem 2 3 5, a saída deverá ter 2 linhas na tabela, com x=3 e x=5:

// x 2x x*x x!
// 3 6 9 6
// 5 10 25 120

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int verificador(int n){
    int fatorial;

    if(n > 0){
        for(fatorial = 1; n > 1; n = n - 1)
            fatorial = fatorial * n;
            return fatorial;
    }
        
    else
        return -1;
}

void calculo(int n){
    int x[1000];  

    printf("\n");

    for (int i = 0; i < n; i++){
        printf("Digite o numero: ");
        scanf("%i", &x[i]);    

    }

    printf("\nx    2x      x*x      x!   ");

    for (int i = 0; i < n; i++){
        
        printf("\n%i   %i       %i      %i   ", x[i], 2*x[i], x[i]*x[i], verificador(x[i]));
    }
    
    system("pause");

}

int main(){
    int n;

    printf("Digite a quantidade de numeros: ");
    scanf("%i", &n);

    calculo(n);

    return 0;

    system("pause");

}