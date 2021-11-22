#include <stdio.h>

int check(int cod){

    if(cod > 0){
    if (cod >= 1 && cod <= 20)
        printf("Europa");
    if (cod >= 21 && cod <= 40)
        printf("Asia");
    if (cod >= 41 && cod <= 60)
        printf("America");
    if (cod >= 61 && cod <= 80)
        printf("Africa");
    if (cod > 80)
        printf("Paraguai");
    }
    else{
        printf("Codigo invalido");
    }
}

int main(){
    
    int cod;

    printf("Digite o cod do produto: ");
    scanf("%d", &cod);

    check(cod);

    return 0;
}