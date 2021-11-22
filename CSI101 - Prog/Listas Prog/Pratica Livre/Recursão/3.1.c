#include<stdio.h>
 
int term;
 
int fibonacci(int antiAnterior, int anterior) {
    static int i = 1;
    int proximo;
 
    if (i == term)
        return (0);
    else{
        proximo = antiAnterior + anterior;
        antiAnterior = anterior;
        anterior = proximo;
        printf("%d  ", proximo);
 
        i++;
        fibonacci(antiAnterior, anterior); 
    }
   return (0);
}

void main() {
    static int antiAnterior = 0, anterior = 1;
    
    printf(" Input number of terms for the Series (< 20) : ");
    scanf("%d", &term);

    printf(" The Series are :\n"); 
    printf(" 1  ");
    fibonacci(antiAnterior, anterior);
}
 
