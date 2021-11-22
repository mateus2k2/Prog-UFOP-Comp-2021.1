// Você trabalha em uma empresa de ônibus. Esta empresa precisa fazer um programa para controlar o número de pessoas
// no ônibus e o acento que eles estão ocupando. Você sabe que todos os ônibus da empresa têm 48 lugares (24 janelas e 24 corredores).
// Baseado nisto você deverá criar um programa que dois vetores de 24 posições cada que representam os acentos. 
// Quando o lugar estiver ocupado a posição do vetor deverá ser preenchida com 1 e 0 quando estiver desocupado. 
// Quando o seu programa iniciar todas as poltronas estão livres. Após iniciar o programa deverá apresenta um menu com as opções:

// 1 - Vender passagem;
// 2 - mostrar mapa de ocupação do ônibus
// 3 - Encerrar

// Quando a opção escolhida for vender passagem, deverá se perguntado também se o usuário deseja janela ou corredor e o número da poltrona. 
// o programa deverá, então, mostrar uma das seguintes opções:

// a) Venda efetivada - se a poltrona solicitada estiver livre. E marcar a poltrona como vendida.
// b) Poltrona ocupada - se a poltrona solicitada não estiver disponível para venda.
// c) Ônibus lotado - se não tiverem mais lugares disponíveis.

// Para a opção mostrar mapa de ocupação, você deverá mostrar uma lista indicando qual lugar está livre e qual está ocupado. Para a opção 3 - o programa deverá ser encerrado.

#include <assert.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int vender(int acentoCorredor[], int acentoJanela[], int ocupados[]){
    char possicao; 
    int numero;
    
    printf("\n------------------------------------------------------------------------------------\n");

    while(1){

        while ((getchar()) != '\n');

        printf("Janela (Digite j) ou corredor (Digite c): ");
        scanf("%c", &possicao);

        if(possicao == 'j' || possicao == 'c')
            break;
        else{
            printf("\nEscolha invalida, tente novamente");
        }
        printf("\n");
    }
    

    while(1){
        printf("Digite o numero da proutrona: 1 a 24: ");
        scanf("%i", &numero);


        if(numero >= 1 && numero <= 24)
            break;
        else{
            printf("\nEscolha invalida, tente novamente");
        }
        printf("\n");
    }

    if(ocupados[1] < 24){
        if(possicao == 'j'){
            if(acentoJanela[numero] == 0){
                acentoJanela[numero] = 1;
                printf("Venda efetivada");
                ocupados++;
                //printf("\n------------------------------------------------------------------------------------\n");
                menu(acentoCorredor, acentoJanela, ocupados);
            }
            else{
                printf("Poltrona ocupada");
                //printf("\n------------------------------------------------------------------------------------\n");
                menu(acentoCorredor, acentoJanela, ocupados);
            }
        }

        if(possicao == 'c'){
            if(acentoCorredor[numero] == 0){
                acentoCorredor[numero] = 1;
                printf("Venda efetivada");
                ocupados++;
                //printf("\n------------------------------------------------------------------------------------\n");
                menu(acentoCorredor, acentoJanela, ocupados);
                
            }
            else{
                printf("Poltrona ocupada");
                //printf("\n------------------------------------------------------------------------------------\n");
                menu(acentoCorredor, acentoJanela, ocupados);
            }
        }
    }
    else{
        printf("Onibus lotado");
        //printf("\n------------------------------------------------------------------------------------\n");
        menu(acentoCorredor, acentoJanela, ocupados);
    }
}

int mapa(int acentoCorredor[], int acentoJanela[], int ocupados[]){

    printf("\n------------------------------------------------------------------------------------\n");


    for (int i = 0; i < 48; i = i + 4){
        
        if(i<10){
            if(acentoJanela[i] == 1)
                printf("0%iO ", i);
            else
                printf("0%iL ", i);

            if(acentoCorredor[i+1] == 1)
                printf("0%iO ", i+1);
            else
                printf("0%iL ", i+1);

            printf("    ||  ");

            if(acentoJanela[i+2] == 1)
                printf("   0%iO ", i+2);
            else
                printf("   0%iL ", i+2);

            if(acentoCorredor[i+3] == 1)
                printf("0%iO", i+3);
            else
                printf("0%iL", i+3);
        }
        
        if(i>10){
            if(acentoJanela[i] == 1)
                printf("%iO ", i);
            else
                printf("%iL ", i);

            if(acentoCorredor[i+1] == 1)
                printf("%iO ", i+1);
            else
                printf("%iL ", i+1);

            printf("    ||  ");

            if(acentoJanela[i+2] == 1)
                printf("   %iO ", i+2);
            else
                printf("   %iL ", i+2);

            if(acentoCorredor[i+3] == 1)
                printf("%iO", i+3);
            else
                printf("%iL", i+3);
        }

        printf("\n");

    }
    


    printf("\nLEGENDA:");

    printf("\nNumero Antes = Numero poltrona");
    printf("\nSeguencia da Esquerda para a direita = Janela, Corredor, Corredor, Janela");

    printf("\nO = Ocupada");
    printf("\nL = Livre");

    printf("\nJ = Poltronas da janela");
    printf("\nC = Poltronas do corredor");
    
    menu(acentoCorredor, acentoJanela, ocupados);

}

int menu(int acentoCorredor[], int acentoJanela[], int ocupados[]){
    int escolha;

    printf("\n------------------------------------------------------------------------------------\n");

    printf("\n1 - Vender passagem");
    printf("\n2 - Mostrar mapa de ocupacao do onibus");
    printf("\n3 - Ebcerrar");
    printf("\nEscolha: ");
    scanf("%i", &escolha);

    while(1){

    switch (escolha){
    case 1: vender(acentoCorredor, acentoJanela, ocupados); 
        break;
    case 2: mapa(acentoCorredor, acentoJanela, ocupados); 
        break;
    case 3: return 0; 
        break;    
    default: printf("Escolha invalida. Tente novamente: ");
             scanf("%i", &escolha);
        break;
    }
    
    }
    
}


int main(int argc, char *argv[ ]){

    int acentoJanela[24] = {0}, acentoCorredor[24] = {0};
    int ocupados[1] = {0};

    menu(acentoCorredor, acentoJanela, ocupados);

    return 0;
}