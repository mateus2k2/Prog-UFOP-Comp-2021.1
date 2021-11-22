// Os vetores U e V têm o mesmo tamanho, você deverá fazer um programa que leia este tamanho e os elementos dos dois vetores. 
// Depois seu programa deverá calcular e mostrar se a propriedade abaixo foi obedecida ou não por estes vetores.

//Matrícula 20.2.8093
//Nome: Mateus Filipe Moreira Silva

/*
Entrdas: valores do vetor 1 e do vetor 2

Saidas: Verificação se a propriedade proposta e verdadeira ou falsa 

Objetivo: Verifica se a propriedade e verdadeira usando o valor 2 como padrão. Fazendo 2(vet1 * vet2) [op1] = ((2*vet1 )* vet2) [op2] = (vet1 * (2*vet2)) [op3]

*/

#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    float vet1[1000], vet2[1000];
    float op1 = 0, op2 = 0, op3 = 0;
    int tamanho;

    printf("Digite o valor do tamanho dos vetores: ");
    scanf("%i", &tamanho);

    printf("\n");

    for (int i = 0; i < tamanho; i++){
        printf("Digite o valor %i do vetor 1: ", i+1);
        scanf("%f", &vet1[i]);
    }
    
    printf("\n");

    for (int i = 0; i < tamanho; i++){
        printf("Digite o valor %i do vetor 2: ", i+1);
        scanf("%f", &vet2[i]);
    }

    for (int i = 0; i < tamanho; i++){
        op1 = op1 + (vet1[i]*vet2[i]);
        if(i == tamanho-1)
            op1 = op1 * 2.0;

        op2 = op2 + ((vet1[i]*2)*vet2[i]);
        op3 = op3 + (vet1[i]*(vet2[i]*2));
        
    }

    printf("\nOperacao 1 %f", op1);
    printf("\nOperacao 2 %f", op2);
    printf("\nOperacao 3 %f", op3);

    if(op1==op2 && op2 == op3 && op3 == op1)
        printf("\nOs vetores obedecem a propriedade");
    else
        printf("\nOs vetores nao obedecem a propriedade");


    return 0;

}