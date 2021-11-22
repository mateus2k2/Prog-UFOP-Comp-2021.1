#include <stdio.h>


int calculo(int T){

if (T > 0 ){
    if (T > 5)
        printf("\nA taxa de juros e de: 0,95");
    if (T < 5 && T >= 4)
        printf("\nA taxa de juros e de: 0,9");
    if (T < 4 && T >= 3)
        printf("\nA taxa de juros e de: 0,85");
    if (T < 3 && T >= 2)
        printf("\nA taxa de juros e de: 0,75");
    if (T < 2 && T >= 1)
        printf("\nA taxa de juros e de: 0,65");
    if (T < 1)
        printf("\nA taxa de juros e de: 0,55");
}
else{
    printf("Insira um valor maior que zero");
}


}

int main(){

    int tempo; 

    printf("Digite o tempo que os fundo foram mantidos em deposito: ");
    scanf("%d", &tempo);

    calculo(tempo);

    return 0;    
}