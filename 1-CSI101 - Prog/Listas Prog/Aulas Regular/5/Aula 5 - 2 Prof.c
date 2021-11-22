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


int main (){
    float media_vei, media_acid;
    int cod, cont, num_vei, num_acid, maior, cid_maior, menor, cid_menor, soma_vei, soma_acid, cont_acid;

    scanf("%i", &soma_vei);
    scanf("%i", &soma_acid);
    scanf("%i", &cont_acid); 

    for(cont = 1; cont <= 5; cont++){
        scanf("%i", &cod);
        scanf("%i", &num_vei);
        scanf("%i", &num_acid);

        if(cont == 1){
            maior = num_acid;
            cid_maior = cod;
            menor = num_acid;
            cid_menor = cod;
        }
        else{
            if(num_acid > maior){
                maior = num_acid;
                cid_maior = cod;
            }
            if(num_acid < menor){
                menor = num_acid;
                cid_menor = cod;
            }
            soma_vei = soma_vei + num_vei;
        }

    }

            if(num_vei < 2000){
            soma_acid = soma_acid + num_acid;
            cont_acid = cont_acid + 1;
        }
        printf("%i, %i", maior, cid_maior);
        printf("%i, %i", menor, cid_menor);
        
        media_vei = soma_vei/5;

        printf("&f", media_vei);

        if(cont_acid == 0){
            printf("Nao foi digitada nenhuma cidade com menos de 2000 veiculos");
        }
        else{
            media_acid = soma_acid / cont_acid;
            printf("&f", media_acid);
        }

    return 0;
}