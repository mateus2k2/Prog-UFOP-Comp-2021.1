
#include <stdio.h>
#include <string.h>

int soma(int n){

    if(n == 0)
        return n;
    else{
        return n + soma(n-1);
    } 

}

int main(){
    int n = 5;

    scanf("%i", &n);

    printf("%i", soma(n));

}