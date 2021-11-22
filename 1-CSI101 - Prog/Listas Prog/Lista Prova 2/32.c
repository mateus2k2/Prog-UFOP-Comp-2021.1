/*
A  prefeitura  de  uma  cidade  fez  uma  pesquisa  entre  seus  habitantes, armazenandoosalário  eonúmero de filhosde cada entrevistado. 
A prefeitura deseja saber:

a.média do salário da população;
b.média do número de filhos;
c.percentual de pessoas com salário até R$1000,00;

Faça um programa que leia os dados e, ao final, exiba os resultados solicitados. A leitura de dados será encerrada com a entrada de um salário negativo.
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int main(){
    float salario = 0;
    float mediaSalario = 0, salario1000 = 0, mediaFilhos = 0;
    float filhos = 0, contFilhos = 0, contSalario = 0, cont = 0; 

    while (salario >= 0){
        printf("\n");

        printf("Digite o seu salario: ");
        scanf("%f", &salario);

        if(salario < 0)
            break;

        printf("Digite quantidade de filhos: ");
        scanf("%f", &filhos);

        if(salario != 0){
            mediaSalario = mediaSalario + salario;
            contSalario++;
        }

        if(salario >= 1000)
            salario1000++;
        
        if(filhos != 0){
            mediaFilhos = mediaFilhos + filhos;
            contFilhos++;
        }

        cont++;   
        
    }
    mediaFilhos = mediaFilhos / contFilhos;
    mediaSalario = mediaSalario / contSalario;

    printf("\nA media dos filhos e: %.2f", mediaFilhos);
    printf("\nA media dos salario e: %.2f", mediaSalario);

    printf("\n");

    printf("\nA porcentagem de pessoas com salario acima de 1000 e %.2f", (salario1000/cont)*100 );

    return 0;
    
}