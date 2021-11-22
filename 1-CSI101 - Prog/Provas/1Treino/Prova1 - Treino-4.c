/*
 Faça um programa que receba a idade de oito pessoas calcule e mostre:

a) a quantidade de pessoas em cada faixa etária;

b) a porcentagem de pessoas na primeira faixa etária com relação ao total de pessoas.

c) a porcentagem de pessoas na última faixa etária com relação ao total de pessoas

A tabela para classificação da idade em cada faixa etária é:

Faixa etária    Idade
1ª	          Até 15 anos
2ª	          De 16 a 30 anos
3ª	          De 31 a 45 anos
4ª	          De 46 a 60 anos
5ª		      Acima de 60 anos
*/

//Matrícula 20.2.8093
//Nome: Mateus Filipe Moreira Silva

#include <stdio.h>

int main(){

    int idade, cont = 0, F1 = 0, F2 = 0, F3 = 0, F4 = 0, F5 = 0;
    float n1, n2;

    for(cont = 1; cont <= 8; cont++){
        printf("Digite a idade: ");
        scanf("%i", &idade);

        if(idade <= 15)
            F1 = F1 + 1;
        else if(idade <= 30 && idade >= 16)
            F2 = F2 + 1;
        else if(idade <= 45 && idade >= 31)
            F3 = F3 + 1;
        else if(idade <= 60 && idade >= 46)
            F4 = F4 + 1;
        else if(idade >= 60)
            F5 = F5 + 1;
        else
            printf("Idade zero ou negativa nao permitida");

    }

    printf("\n%i Numero de pessoas na primeira faixa etaria de ate 15 anos", F1);
    printf("\n%i Numero de pessoas na segunda faixa etaria de 16 a 30 anos", F2);
    printf("\n%i Numero de pessoas na terceira faixa etaria de 31 a 45 anos", F3);
    printf("\n%i Numero de pessoas na quarta faixa etaria de 46 a 60 anos", F4);
    printf("\n%i Numero de pessoas na primeira faixa etaria de mais de 60 anos", F5);

    n1 = (F1/8)*100;
    n2 = (F5/8)*100;

    printf("\nA porcentagem de pessoas na primeira faixa etaria com relacao ao total de pessoas e %0.2f", n1 );
    printf("\nA porcentagem de pessoas na ultima faixa etaria com relacao ao total de pessoas e %0.2f", n2  );

    return 0;
    
}