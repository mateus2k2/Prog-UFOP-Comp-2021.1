/*
Faça uma função que receba um número inteiro e teste se o valor lido termina com 0 (divisível por 10). Em caso positivo,
exiba a metade deste número. Caso contrário, exibir a mensagem "O número digitado não termina com 0".
*/
#include <stdio.h>


void verificador(int N){
    
    if(N%10==0){
        printf("%d", N = N/2);
    }
    else{
        printf("Numero nao e terminado em zero");         
    }

}

int main(){
    
    int N1;

    printf("Digite um numero terminado em zero: ");
    scanf("%d", &N1);

    verificador(N1);

    return 0;
}