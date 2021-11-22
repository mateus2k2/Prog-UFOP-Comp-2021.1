//Faça uma função que imprima se um número real recebido como parâmetro é positivo, negativo ou neutro (zero).

#include <stdio.h>

void verificador(int N){
    
    if(N > 0){
        printf("o numero e positivo ");
    }
    else{
    if(N < 0){
        printf("o numero e negativo ");
    }
    else{
        printf("Numero e zero");         
    }
    }

}

int main(){
    
    int N1;

    printf("Digite um numero real: ");
    scanf("%d", &N1);

    verificador(N1);

    return 0;
}