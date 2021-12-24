//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/structs.h"
#include "Headers/continuarJogo.h"
#include "Headers/menus.h"
#include "Headers/cores.h"
#include "Headers/criaTabuleiro.h"


void menu(){

    //Menu principal
    
    char escolhaChar[20];

    printf("\nO que deseja fazer:\n");

    printf("\n1.  Comecar um novo jogo");
    printf("\n2.  Continuar um jogo");
    printf("\n3.  Instruções do jogo\n\n");

    printf("Escolha a opção (digite ”sair” em qualquer lugar para sair do jogo): ");
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
            printf("Vistas as instruções o que deseja fazer? ");
        }
        else if(strcmp(escolhaChar,"SAIR") == 0){
            return;
        }
        else
            printf("Opção Invalida. Tente Novamente: ");
    }
}

int menuDificuldade(){

    //Menu de dificuldades
    
    char escolhaChar[20];

    printf("\nDigite o nível de dificuldade:\n");

    printf("\n1.  Fácil");
    printf("\n2.  Médio");
    printf("\n3.  Difícil\n\n");

    printf("Escolha a opção: ");
    while (strcmp(escolhaChar,"1") != 0 || strcmp(escolhaChar,"2") != 0 && strcmp(escolhaChar,"3") != 0 && strcmp(escolhaChar,"SAIR") != 0){
        fgets(escolhaChar, 20, stdin);
        escolhaChar[strlen(escolhaChar)-1] = '\0';

        for (int i = 0; i < strlen(escolhaChar); i++){
            if(escolhaChar[i] >= 'a' && escolhaChar[i] <= 'z')
                escolhaChar[i] = escolhaChar[i]-32;
        }        

        if(strcmp(escolhaChar,"1") == 0){
            return 1;
        }
        
        else if(strcmp(escolhaChar,"2") == 0){
            return 2;
        }
        else if(strcmp(escolhaChar,"3") == 0){
            return 3;
        }
        else if(strcmp(escolhaChar,"SAIR") == 0){
            return 0;
        }
        else
            printf("Opção Invalida. Tente Novamente: ");
    }
}

void printInstrucoes(){

//Inicializa matriz tabuleiro de demostração

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

    printf(BG_BLACK(WHITE(BOLD("OPÇÕES MENU"))));
    printf("\n1-Começar Novo Jogo: Escolha a dificuldade e Digite o nome do arquivo de dicionário. Comece a jogar");
    printf("\n2-Continuar Jogo Existente: Digite o nome do arquivo para leitura. Comece a jogar");
    printf("\n3-Instruções: O Menu Atual\n\n");

    printf(BG_BLACK(WHITE(BOLD("COMANDOS MARCAR"))));
    printf("\nDigite \"marcar\" seguido na coordenada desejada.");
    printf("\nA coordenada deve estar dentro no tabuleiro.");
    printf("\nNao deixo espaço no final.");
    printf("\nCoordenada deve ser em letras.");
    printf("\nPode ser em caixa alta ou não");
    printf("\nModelo: Marcar AB CD\n\n");

    printf(BG_BLACK(WHITE(BOLD("COMANDOS SALVAR"))));
    printf("\nDigite \"salvar\" seguido do nome do arquivo desejado.");
    printf("\nCaso voce nao coloque \".txt\" no final do nome do arquivo ele sera adicioando automaticamente");
    printf("\nPode estar em caixa alta ou nao");
    printf("\nModelo: Salvar teste.txt\n\n");

    printf(BG_BLACK(WHITE(BOLD("COMANDOS RESOLVER"))));
    printf("\nDigite apenas \"resolver\".");
    printf("\nA resposta sera mostrada");
    printf("\nO programa sera encerrado");
    printf("\nPode estar em caixa alta ou nao");
    printf("\nModelo: Resolver\n\n");

    printf(BG_BLACK(WHITE(BOLD("COMANDOS SAIR"))));
    printf("\nDigite apenas \"sair\".");
    printf("\nPrograma se encerra sem salvar");
    printf("\nPode estar em caixa alta ou nao");
    printf("\nModelo: Sair\n\n");

    printf(BG_BLACK(WHITE(BOLD("TABULEIRO EXEMPLO"))) "\n\n");
    printTabuleiroInstrucao(11, 11, tabuleiro, 2);

    printf("\n" BOLD(BG_BLACK(BOLD(BLUE("AZUL")))) ": Apenas Auxilio. Não faz Parte do Tabuleiro");
    printf("\n" BOLD(BG_BLACK(BOLD(GREEN("VERDE")))) ": dificuldade 1");
    printf("\n" BOLD(BG_BLACK(BOLD(MAGENTA("MAGENTA")))) ": dificuldade 2");
    printf("\n" BOLD(BG_BLACK(BOLD(RED("VERMELHO")))) ": dificuldade 3");
    printf("\nSe a acumulam a cada dificuldade\n\n");

    printf(BG_BLACK(WHITE(BOLD("O JOGO ENCERRA CASO"))));
    printf("\nSeja digitado sair");
    printf("\nTodas as palavras sejam marcadas");
    printf("\nSeja digitado resolver\n\n");


    printf(BG_BLACK(WHITE(BOLD("OUTROS"))));
    printf("\nNo jogo, as palavras marcadas serão na cor magenta e se escolher resolver, elas ficarão vermelhas");
    printf("\nPara nomes de arquivos, os caracteres '<' '>' ':' '\"' '|' '?' '*' Sao proibidos");
    printf("\nCaracteres especiais no immput como 'ç' ou 'á' não são recomendados\n");

    
    printf("\n-------------------------------------------------------------------------\n\n");
    
}

void printTabuleiroInstrucao(int tamLin, int tamCol, Item tabuleiro[11][11], int escolha){

    //Mesma lógica do printTabuleiro
    //Muda apenas o tipo do parametro tabuleiro e a cor do prints 

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
        printf(BG_BLACK(TAB_VER BOLD(BLUE(" %c "))), 'A'+ i);

    printf(BG_BLACK(TAB_VER));

    printf("\n");

    //----------------------------------------------------------------------

    printf(BG_BLACK(TAB_ML));

    for (int i = 0; i < tamCol; i++)
        printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MJ));

    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MR) "\n");


    //----------------------------------------------------------------------


    for (int i = 0; i < tamLin; i++){
        printf(BG_BLACK(TAB_VER BOLD(BLUE(" %c "))), 'A'+ i);
        for (int j = 0; j < tamCol; j++){

            if(escolha == 2 && tabuleiro[i][j].dificuldade == 1){
                    printf(BG_BLACK(TAB_VER BOLD(GREEN(" %c "))), tabuleiro[i][j].caractere);
            }
            else if(escolha == 2 && tabuleiro[i][j].dificuldade == 2){
                printf(BG_BLACK(TAB_VER BOLD(MAGENTA(" %c "))), tabuleiro[i][j].caractere);
            }
            else if(escolha == 2 && tabuleiro[i][j].dificuldade == 3){
                printf(BG_BLACK(TAB_VER BOLD(RED(" %c "))), tabuleiro[i][j].caractere);
            }
    
            else
                printf(BG_BLACK(TAB_VER BOLD(WHITE(" %c "))), tabuleiro[i][j].caractere);
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

