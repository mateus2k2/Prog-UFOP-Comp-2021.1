//fazer usando 3 pares de if-else

#include <stdio.h>

int calculoIdade(int idade){

    if(idade > 0){
    if (idade < 13)
        printf("Voce e uma criança");
    if (idade >= 13 && idade < 20 )
        printf("Voce e um adolecente");
    if (idade >= 20 && idade < 65 )
        printf("Voce e um adulto");
    if (idade >= 65 )
        printf("Voce e um idoso");
    }
    else{
        printf("idade negativa ou zero = invalida");
    }
}

int main(){
    
    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    calculoIdade(idade);

    return 0;
}
