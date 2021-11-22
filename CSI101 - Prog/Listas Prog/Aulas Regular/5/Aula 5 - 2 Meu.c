/*
Foi feita uma estatistica em cinco cidades brasileiras para coletar dados sobre acidentes de transito 

Foram obtidos os segintes dados
A-Codigo da cidade
B-Numero de veiculos de passageiros
C-Numero de Acidentes de transito com vitimas

Deseja-se saber
1-Qual é o maior e qual é o menor indice de acidentes de transito e a que cidade pertencem
2-Qual é a media de veiculos nas cinco cidade juntas
3-Qual é a media de acidentes de transito nas cidades com menos de 2000 veiculos de passageiros
*/

#include <stdio.h>

int main(){

    int cont, cod, veiculos, acidentes, indiceMenor, indiceMaior, codMenor, codMaior, somaVeiculos = 0, somaAcidentes2000 = 0, contAcidentes2000 = 0;
    float mediaVeiculos, mediaAcidentes2000;

    for(cont = 1; cont <= 5; cont++){
        
        printf("Digite o codigo da cidade: ");
        scanf("%i", &cod);

        printf("Digite o numero de veiculos da cidade: ");
        scanf("%i", &veiculos);

        printf("numero de acidentes da cidade : ");
        scanf("%i", &acidentes);

        if(cont == 1){
            codMaior = cod;
            indiceMaior = acidentes;
            codMenor = cod;
            indiceMenor = acidentes;
        }
        else{
            if(acidentes > indiceMaior){
                codMaior = cod;
                indiceMaior = acidentes;
                }

            if(acidentes < indiceMenor){
                codMenor = cod;
                indiceMenor = acidentes;
                }
        }

        if(veiculos < 2000){
            somaAcidentes2000 = somaAcidentes2000 + acidentes;
            contAcidentes2000 = contAcidentes2000 + 1;          
        }

        somaVeiculos = somaVeiculos + veiculos;

    }

    mediaVeiculos = somaVeiculos/5;
    mediaAcidentes2000 = somaAcidentes2000/contAcidentes2000;

    if(somaAcidentes2000 == 0){
        printf("Nao foi digitada nenhuma cidade com menos de 2000 veiculos");
    }
    else{
        printf("\nA media de acidentes nas cidade com menos de 2000 carros e %f", mediaAcidentes2000);
    }


    printf("\nA media de veiculos nas cinco cidade e %f", mediaVeiculos);

    printf("\nA cidade com o maior indice de acidentes tem codigo %i com %f acidentes", codMaior, indiceMaior);
    printf("\nA cidade com o menor indice de acidentes tem codigo %i com %f acidentes", codMenor, indiceMenor);
    

    return 0;
    
}


