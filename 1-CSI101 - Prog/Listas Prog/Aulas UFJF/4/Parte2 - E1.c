#include <stdio.h>


void imprimeDivisaoReal(float N1, float N2){
    
    float div;
    
    if (N2 =! 0)
    {
        div = N1 / N2;
        printf("\nDivisao real %f", div);
    }
    else{
        printf("O segundo numero nao pode ser 0");
    }
}

void imprimeDivisaoInteira(int N1, int N2){
    
    int div;
    
    if (N2 =! 0)
    {
        div = N1 / N2;
        printf("\nDivisao Inteira %d", div);
    }
    
}

int main(){

    float N1, N2;
    printf("Digite o primerio numero: ");
    scanf("%f", &N1);
    
    printf("Digite o segundo numero: ");
    scanf("%f", &N2);
    
    imprimeDivisaoReal(N1, N2);  
    imprimeDivisaoInteira(N1, N2);

    return 0;
}