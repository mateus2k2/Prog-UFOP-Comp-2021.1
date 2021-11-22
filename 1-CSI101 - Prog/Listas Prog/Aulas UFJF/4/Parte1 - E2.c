#include <stdio.h>

void divsibi(int N1){
    
    int div;
    
    if (N1%2==0){
        printf("O Numero e par");
    }
    else{
        printf("O Numero e impar");
    }
    
}

int main(){

    int N1;
    printf("Digite o numero: ");
    scanf("%d", &N1);
    
    divsibi(N1); 

    return 0;
}