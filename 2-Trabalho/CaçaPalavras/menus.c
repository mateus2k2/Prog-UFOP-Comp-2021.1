// void menu();
// void menuDificuldade();
// void printInstrucoes();
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
#include <unistd.h>

#include "Headers/menus.h"
#include "Headers/cores.h"
#include "Headers/structs.h"



void menu(){

    int escolha;
    char escolhaChar[20];

    printf("\nO que deseja fazer:\n");

    printf("\n1.  Comecar um novo jogo");
    printf("\n2.  Continuar um novo jogo");
    printf("\n3.  Instrucoes do jogo\n\n");

    printf("Escolha a opcao (digite ”sair” em qualquer lugar para sair do jogo): ");
    while (strcmp(escolhaChar,"1") != 0 || strcmp(escolhaChar,"2") != 0 && strcmp(escolhaChar,"3") != 0 && strcmp(escolhaChar,"SAIR") != 0){
        fgets(escolhaChar, 20, stdin);
        escolhaChar[strlen(escolhaChar)-1] = '\0';

        for (int i = 0; i < strlen(escolhaChar); i++){
            if(escolhaChar[i] >= 'a' && escolhaChar[i] <= 'z')
                escolhaChar[i] = escolhaChar[i]-32;
        }        

        if(strcmp(escolhaChar,"1") == 0){
            criarJogo();
            break;
        }
        
        else if(strcmp(escolhaChar,"2") == 0){
            continuaJogo();
            break;
        }
        else if(strcmp(escolhaChar,"3") == 0){
            printInstrucoes();
            printf("Vistas as instruções oque deseja fazer? ");
        }
        else if(strcmp(escolhaChar,"SAIR") == 0){
            return;
        }
        else
            printf("Opcao Invalida. Tente Novamente: ");
    }
}

void menuDificuldade(){
    //menu
}

void printInstrucoes(){

    Item tabuleiro[11][11] = 
{
//            |  COL 0  |  |  COL 1  |  |  COL 2  |  |  COL 3  |  |  COL 4  |  |  COL 5  |  |  COL 6  |  |  COL 7  |  |  COL 8  |  |  COL 9  |  |  COL 10  |
/* LIN 0 */ { {'E',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'E',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'E',3,0,0} },
/* LIN 1 */ { {'A',0,0,0}, {'T',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'T',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'T',3,0,0}, {'A',0,0,0} },
/* LIN 2 */ { {'A',0,0,0}, {'A',0,0,0}, {'S',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'S',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'S',3,0,0}, {'A',0,0,0}, {'A',0,0,0} },
/* LIN 3 */ { {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'E',3,0,0}, {'A',0,0,0}, {'E',3,0,0}, {'A',0,0,0}, {'E',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0} },
/* LIN 4 */ { {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'T',3,0,0}, {'T',3,0,0}, {'T',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0} },
/* LIN 5 */ { {'E',3,0,0}, {'T',3,0,0}, {'S',3,0,0}, {'E',3,0,0}, {'T',3,0,0}, {'A',0,0,0}, {'T',1,0,0}, {'E',1,0,0}, {'S',1,0,0}, {'T',1,0,0}, {'E',1,0,0} },
/* LIN 6 */ { {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'T',3,0,0}, {'T',1,0,0}, {'T',2,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0} },
/* LIN 7 */ { {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'E',3,0,0}, {'A',0,0,0}, {'E',1,0,0}, {'A',0,0,0}, {'E',2,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0} },
/* LIN 8 */ { {'A',0,0,0}, {'A',0,0,0}, {'S',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'S',1,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'S',2,0,0}, {'A',0,0,0}, {'A',0,0,0} },
/* LIN 9 */ { {'A',0,0,0}, {'T',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'T',1,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'T',2,0,0}, {'A',0,0,0} },
/* LIN 10*/ { {'E',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'E',1,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'E',2,0,0} }

};  


    printf("\n-------------------------------------------------------------------------\n");

    printf("\nOPCOES MENU");
    printf("\n1-Começar Novo Jogo: Escolha a dificuldade e Digite o nome do arquivo de dicionario. Comece a jogar");
    printf("\n2-Continuar Jogo Existente: Digite o nome do arquivo para leitura. Comece a jogar");
    printf("\n3-Instrucoes: O Menu Atual\n");

    printf("\nCOMANDOS MARCAR");
    printf("\nDigite \"marcar\" seguido na coordenada desejada.");
    printf("\nA coordenada deve estar dentro no tabuleiro.");
    printf("\nNao deixo espaço no final.");
    printf("\nCoordenada deve ser em letras.");
    printf("\nPode ser em caixa alta ou não");
    printf("\nModelo: Marcar AB CD\n");

    printf("\nCOMANDOS SALVAR");
    printf("\nDigite \"salvar\" seguido do nome do arquivo desejado.");
    printf("\nCaso voce nao coloque \".txt\" no final do nome do arquivo ele sera adicioando automaticamente");
    printf("\nPode estar em caixa alta ou nao");
    printf("\nModelo: Salvar teste.txt\n");

    printf("\nCOMANDOS RESOLVER");
    printf("\nDigite apenas \"resolver\".");
    printf("\nA resposta sera mostrada");
    printf("\nO programa sera encerrado");
    printf("\nPode estar em caixa alta ou nao");
    printf("\nModelo: Resolver\n");

    printf("\nCOMANDOS SAIR");
    printf("\nDigite apenas \"sair\".");
    printf("\nPrograma se encerra sem salvar");
    printf("\nPode estar em caixa alta ou nao");
    printf("\nModelo: Sair\n");

    printf("\nTABULEIRO EXEMPLO\n");
    printTabuleiroInstrucao(11, 11, tabuleiro, 2);

    printf("\nAZUL: Apenas Auxilio. Não faz Parte do Tabuleiro (Se a acumulam a cada dificuldade)");
    printf("\nCOR VERDE: dificuldade 1");
    printf("\nCOR AMARELO: dificuldade 2");
    printf("\nCOR VERMELHO: dificuldade 3\n");

    printf("\nO JOGO ENCERRA CASO: ");
    printf("\nSeja digitado sair");
    printf("\nTodas as palavras sejam marcadas");
    printf("\nSeja digitado resolver\n");


    printf("\nOUTROS");
    printf("\nO caractere \"/\" eh proibido para nome de arquivo.");
    printf("\nExistem mais cacteres proibidos no windows e eles nao sao verificados.");
    printf("\nPodem ocorrer erros no windows.");
    printf("\nNo jogo, as palavras marcadas serão amarelas e se escolher resolver, elas ficarão vermelhas\n");
    
    printf("\n-------------------------------------------------------------------------\n\n");
    
}

void printTabuleiroInstrucao(int tamLin, int tamCol, Item tabuleiro[11][11], int escolha){

    printf(BG_BLACK(TAB_TL));
    for (int i = 0; i < tamCol+1; i++){
        if(i != tamCol)
            printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_TJ));
    }
    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_TR) "\n");

    //----------------------------------------------------------------------

    printf(BG_BLACK(TAB_VER));

    printf(BG_BLACK("   "));
    for (int i = 0; i < tamCol; i++)
        printf(BG_BLACK(TAB_VER BLUE(" %c ")), 'A'+ i);

    printf(BG_BLACK(TAB_VER));

    printf("\n");

    //----------------------------------------------------------------------

    printf(BG_BLACK(TAB_ML));

    for (int i = 0; i < tamCol; i++)
        printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MJ));

    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MR) "\n");


    //----------------------------------------------------------------------


    for (int i = 0; i < tamLin; i++){
        printf(BG_BLACK(TAB_VER BLUE(" %c ")), 'A'+ i);
        for (int j = 0; j < tamCol; j++){

            if(escolha == 2 && tabuleiro[i][j].dificuldade == 1){
                    printf(BG_BLACK(TAB_VER BOLD(GREEN(" %c "))), tabuleiro[i][j].caractere);
            }
            else if(escolha == 2 && tabuleiro[i][j].dificuldade == 2){
                printf(BG_BLACK(TAB_VER BOLD(YELLOW(" %c "))), tabuleiro[i][j].caractere);
            }
            else if(escolha == 2 && tabuleiro[i][j].dificuldade == 3){
                printf(BG_BLACK(TAB_VER BOLD(RED(" %c "))), tabuleiro[i][j].caractere);
            }
    
            else
                printf(BG_BLACK(TAB_VER " %c "), tabuleiro[i][j].caractere);
        }  
        printf(BG_BLACK(TAB_VER));

        if(i != tamLin - 1){     

            printf("\n");

            printf(BG_BLACK(TAB_ML));

            for (int i = 0; i < tamCol; i++)
                printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MJ));

            printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MR));    
        }

        printf("\n");
        
    } 


    //----------------------------------------------------------------------

    printf(BG_BLACK(TAB_BL));
    for (int i = 0; i < tamCol+1; i++){
        if(i != tamCol)
            printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_BJ));
    }
    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_BR) "\n");


}

