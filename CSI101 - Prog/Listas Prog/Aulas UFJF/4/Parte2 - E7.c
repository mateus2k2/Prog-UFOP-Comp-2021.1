

#include <stdio.h>

int classificaNadador(int idade){

    if(idade > 0){
        if(idade >= 5 && idade <= 7)
            printf("Infantil A");
        if(idade >= 8 && idade <= 10)
            printf("Infantil B");
        if(idade >= 11 && idade <= 13)
            printf("Juvenil A");
        if(idade >= 14 && idade <= 17)
            printf("Juvenil B");
        if(idade >= 18 && idade <= 30)
            printf("Adulto");
        if(idade > 30)
            printf("Senior");
    }
    else{
        printf("Idade negativa invalida");
    }

}

int main(){

    int idade;

    printf("Digite a idade do nadador: ");
    scanf("%d", &idade);

    classificaNadador(idade);

}
