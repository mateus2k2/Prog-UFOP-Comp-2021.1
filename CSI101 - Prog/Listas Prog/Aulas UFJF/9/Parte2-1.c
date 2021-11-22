// Escreva um programa para fazer a criação dos novos tipos de dados conforme solicitado abaixo:
// a)Horário: composto de hora, minutos e segundos. 
// b)Data: composto de dia, mês e ano. 
// c)Compromisso: composto de uma data, horário e texto que descreve o compromisso.
// d)Faça um programa que leia 10 compromissos e imprima no formato 

// No dia dd/mm/aaaa as hh:mm:ss voce tem o compromisso XXXXXXXXX

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 2

typedef struct{
    int hora;
    int minutos;
    int segundos;

}horario;

typedef struct{
    int dia;
    int mes;
    int ano;

}data;


typedef struct{
    horario horarioCompromiso;
    data dataCompromiso;
    char descrisaoCompromiso[1000];

}compromiso;


int main(){
    compromiso calendario[MAX];
    int c;

    for (int i = 0; i < MAX; i++){
        printf("\nCOMPROMISO NUMERO %i\n", i+1);
        
        printf("Digite o horaio (hh mm ss): ");
        scanf("%i %i %i", &calendario[i].horarioCompromiso.hora, &calendario[i].horarioCompromiso.minutos, &calendario[i].horarioCompromiso.segundos);

        printf("Digite a data (dd mm aa): ");
        scanf("%i %i %i", &calendario[i].dataCompromiso.dia, &calendario[i].dataCompromiso.mes, &calendario[i].dataCompromiso.ano);

        //Remove the \n from input stream
        while ( (c = getchar()) != '\n' && c != EOF );

        printf("Digite uma descricao para o comprimiso: ");
        gets(calendario[i].descrisaoCompromiso);
    }
    
    for (int i = 0; i < MAX; i++){
        printf("\nNo dia %i/%i/%i as %i:%i:%i voce tem o compromisso %s", 
        calendario[i].dataCompromiso.dia, calendario[i].dataCompromiso.mes, calendario[i].dataCompromiso.ano, calendario[i].horarioCompromiso.hora, calendario[i].horarioCompromiso.minutos, calendario[i].horarioCompromiso.segundos, calendario[i].descrisaoCompromiso);
    }
    
    return 0;

}


