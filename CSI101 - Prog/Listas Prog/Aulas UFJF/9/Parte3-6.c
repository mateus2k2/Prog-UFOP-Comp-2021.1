// Elabore um programa que auxilie no controle de uma fazenda de gado que possua um total de 100 cabeças de gado. 
// O programa deverá conter uma estrutura que comporte:

// • código: código da cabeça de gado;
// • leite: número de litros de leite produzido por semana;
// • alimento: quantidade de alimento ingerida por semana (kg);
// • mês de nascimento;
// • ano de nascimento;
// • abate: ‘N”(não) ou ‘S’ (sim).

// O seu programa deverá conter um menu com as seguintes funcionalidades:
// (a) Ler a base de dados (código, leite, alimento, nascimento) informados pelo usuário e armazenar em um vetor de estruturas.

// (b) Preencher o campo abate, considerando que a cabeça de gado irá para o abate caso:• tenha mais de 5 anos, ou;• produza menos 
//     de 40 litros de leite por semana, ou;• produza entre 50 e 70 litros de leite por semana e ingira mais de 50 quilos de alimento por semana.

// (c) Imprimir a quantidade total de leite produzida por semana na fazenda.

// (d) Imprimir a quantidade total de alimento consumido por semana na fazenda.

// (e) Imprimir a quantidade total de leite que vai ser produzido por semana na fazenda, após o abate

// (f) Imprimir a quantidade total de alimento que vai ser consumido por semana na fazenda, após o abate

// (g) Imprimir número de cabeças de gado que irão para o abate.

// (h) Inclua uma opção para sair do menu.


#define MAX 2

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


typedef struct{
    int ano;
    int mes;
}data;



typedef struct{
    int cod;
    float litrosLeite;
    float kgAlimentos;
    data dataNacimento;
    char abate;
}gado;


void lerInfo(gado rebanho[]){

    for (int i = 0; i < MAX; i++){
        printf("\nINFORMACAO GADO NUMERO %i\n", i+1);

        printf("Codigo: ");
        scanf("%i", &rebanho[i].cod);

        printf("Litro de leite: ");
        scanf("%f", &rebanho[i].litrosLeite);

        printf("Kg alimento consumidos: ");
        scanf("%f", &rebanho[i].kgAlimentos);

        printf("Data de nacimento (ano mes): ");
        scanf("%i %i", &rebanho[i].dataNacimento.mes, &rebanho[i].dataNacimento.ano);
    }
    menu(rebanho);
}

//• tenha mais de 5 anos, ou;• produza menos de 40 litros de leite por semana, ou;• produza entre 50 e 70 litros de leite por semana e ingira mais de 50 quilos de alimento por semana.

void abate(gado rebanho[]){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int idade;

    for (int i = 0; i < MAX; i++){
        if(((tm.tm_year + 1900)-rebanho[i].dataNacimento.ano - 1) > 5){
            rebanho[i].abate = 'S';
        }
        else if(rebanho[i].litrosLeite < 40){
            rebanho[i].abate = 'S';
        }
        else if(rebanho[i].litrosLeite > 50 && rebanho[i].litrosLeite < 70 && rebanho[i].kgAlimentos > 50){
            rebanho[i].abate = 'S';
        }
        else{
            rebanho[i].abate = 'N';
        }   
    }
    menu(rebanho);
}

void totalLeite(gado rebanho[]){
    float totalLeite = 0;

    for (int i = 0; i < MAX; i++){
        totalLeite = totalLeite + rebanho[i].litrosLeite;
    }

    printf("\nTOTAL DE LEITE PRODUZIDOS: %.2f\n", totalLeite);
    menu(rebanho);
}

void totalAlimentos(gado rebanho[]){
    float totalAlimento = 0;

    for (int i = 0; i < MAX; i++){
        totalAlimento = totalAlimento + rebanho[i].kgAlimentos;
    }

    printf("\nTOTAL DE ALIMENTOS CONSUMIDOS: %.2f\n", totalAlimento);
    menu(rebanho);
}

void leiteAbate(gado rebanho[]){
    float totalLeiteAbate = 0;

    for (int i = 0; i < MAX; i++){
        if(rebanho[i].abate == 'N')
            totalLeiteAbate = totalLeiteAbate + rebanho[i].litrosLeite;
    }

    printf("\nTOTAL DE LEITE PRODUZIDO APOS ABATE: %.2f\n", totalLeiteAbate);
    menu(rebanho);
}

void alimentoAbate(gado rebanho[]){
    float totalAlimentoAbate = 0;

    for (int i = 0; i < MAX; i++){
        if(rebanho[i].abate == 'N')
            totalAlimentoAbate = totalAlimentoAbate + rebanho[i].kgAlimentos;
    }

    printf("\nTOTAL DE ALIMENTO CONSUMIDO APOS ABATE: %.2f\n", totalAlimentoAbate);
    menu(rebanho);
}

void cabecasAbate(gado rebanho[]){
    float totalCabecasAbate = 0;

    for (int i = 0; i < MAX; i++){
        if(rebanho[i].abate == 'N')
            totalCabecasAbate++;
    }

    printf("\nTOTAL DE CABECAS DE GADO RESTANTES APOS ABATE: %.2f\n", totalCabecasAbate);
    menu(rebanho);
}

void menu(gado rebanho[]){
    int escolha;
    
    printf("\nMENU\n");

    printf("\n1: Ler informacoes");
    printf("\n2: Verificar abatidos");
    printf("\n3: Imprimir total de leite antes do abate");
    printf("\n4: Imprimir total de alimentos antes do abate");
    printf("\n5: Imprimir total de leite depois do abate");
    printf("\n6: Imprimir total de alimento depois do abate");
    printf("\n7: Imprimir total de cabecas depois do abate\n");
    printf("ESCOLHA: ");
    scanf("%i", &escolha);
    

    while(1){
        switch(escolha){
        case 1: lerInfo(rebanho);
            break;
        case 2: abate(rebanho);
            break;
        case 3: totalLeite(rebanho);
            break;
        case 4: totalAlimentos(rebanho);
            break;
        case 5: leiteAbate(rebanho);
            break;
        case 6: alimentoAbate(rebanho);
            break;
        case 7: cabecasAbate(rebanho);
            break;
        
        default: printf("Opcao invalida tente novamente: ");
                 scanf("%i", &escolha);
            break;
        }
    }
}

int main(){
    gado rebanho[MAX];

    lerInfo(rebanho);
    abate(rebanho);

    menu(rebanho);
}