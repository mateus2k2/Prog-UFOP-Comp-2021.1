#include<stdio.h>
#include <stdlib.h>

unsigned long long fact(int n){
  
    if (n == 1)
        return 1;
    else
        return(n * fact(n-1));
}

int main(){
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);
  
    printf("Fatorial de %d = %llu\n", n, fact(n));
  
    return 0;
}

