/*
Faça uma função que receba o ano atual e o ano de nascimento de uma pessoa e imprima sua idade. 
A seguir, imprima se a pessoa é bebê (0 a 3 anos), criança (4 a 10 anos), adolescente (11 a 18 anos), adulta (19 a 50 anos) ou idosa (51 anos em diante).
*/

#include <stdio.h>

int calculoIdade(int Nacim, int Atual){
    
    int calculoIdade;
    
    calculoIdade = Atual - Nacim;
    printf("Sua idade atual e %d", calculoIdade);

    if(calculoIdade > 0){
    if (calculoIdade > 0 && calculoIdade <= 3 )
        printf("\nVoce e um bebe");
    if (calculoIdade >= 4 && calculoIdade <= 10 )
        printf("\nVoce e uma crianca");
    if (calculoIdade >= 11 && calculoIdade <= 18 )
        printf("\nVoce e um adolecente");
    if (calculoIdade >= 19 && calculoIdade <= 50 )
        printf("\nVoce e um aldulto");
    if (calculoIdade >= 51)
        printf("\nVoce e um idoso");
    }
    else{
        printf("\nidade negativa ou zero = invalida");
    }
    return calculoIdade;
}

int main(){
    
    int anoNacimento, anoAtual;

    printf("Digite seu ano de nacimento: ");
    scanf("%d", &anoNacimento);

    anoAtual = 2021;

    calculoIdade(anoNacimento, anoAtual);

    return 0;
}
