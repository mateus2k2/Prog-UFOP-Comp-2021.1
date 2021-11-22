#include <stdio.h>

int leNumeroPositivo(int N1){

    int N2;

    if (N1 < 0){
        printf("Segunda chance de duas para digitar o numero positivo: ");
        scanf("%d", &N2);    
    }
    else{
        printf("O primeiro numero digitado e postivo");
        return N1;
    }

    if (N2 < 0){
        printf("O segundo numero digitado e negativo: ");   
    }
    else{
        printf("O segundo numero digitado e postivo");
    }

    // return N1;

}

int main(){

    int N1;

    printf("Primeira chance de duas para digitar o numero positivo: ");
    scanf("%d", &N1);

    leNumeroPositivo(N1);

    return 0;

}