
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

#include "Headers/structs.h"
#include "Headers/cores.h"
#include "Headers/outros.h"


void printResolvido(int tamLin, int tamCol, Item **tabuleiro, int escolha){

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
        printf(BOLD(BG_BLACK(TAB_VER BLUE(" %c "))), 'A'+ i);

    printf(BG_BLACK(TAB_VER));

    printf("\n");

    //----------------------------------------------------------------------

    printf(BG_BLACK(TAB_ML));

    for (int i = 0; i < tamCol; i++)
        printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MJ));

    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MR) "\n");


    //----------------------------------------------------------------------


    for (int i = 0; i < tamLin; i++){
        printf(BOLD(BG_BLACK(TAB_VER BLUE(" %c "))), 'A'+ i);
        for (int j = 0; j < tamCol; j++){
            if(tabuleiro[i][j].fazPartePalavra == 1 && escolha == 1){
                printf(BOLD(BG_BLACK(TAB_VER BOLD(RED(" %c ")))), tabuleiro[i][j].caractere);
            }
            else if(tabuleiro[i][j].marcadoUsuario == 1 && escolha == 0){
                printf(BOLD(BG_BLACK(TAB_VER BOLD(YELLOW(" %c ")))), tabuleiro[i][j].caractere);
            }
            
            else
                printf(BOLD(BG_BLACK(TAB_VER " %c ")), tabuleiro[i][j].caractere);
        }  
        printf(BOLD(BG_BLACK(TAB_VER)));

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

void sairJogo(Item **tabuleiro, Palavra *palavras, int tamLin){

    for (int i = 0; i < tamLin; i++)
        free(tabuleiro[i]);
    free(tabuleiro); 

    free(palavras); 
}

void leNomeArquivo(char *nomeArquivo[]){

    char nomeArquivoTmp[100];
    int tmpTamanho = 0, verificadoNomeArquivo = 0;

    FILE *dicionario;

    while (1){
        printf("\nDigite o nome do arquivo: ");
        while (verificadoNomeArquivo == 0){
            fgets((*nomeArquivo), 100, stdin);
            (*nomeArquivo)[strlen((*nomeArquivo))-1] = '\0';

            for (int i = 0; i < strlen((*nomeArquivo)); i++){
                if(((*nomeArquivo)[i] >= 'a' && (*nomeArquivo)[i] <= 'z'))
                    nomeArquivoTmp[i] = (*nomeArquivo)[i]-32;

                else if((*nomeArquivo)[i] != '/')
                    nomeArquivoTmp[i] = (*nomeArquivo)[i];
                
                else{
                    verificadoNomeArquivo = 0;
                    break;
                }

                if(i == strlen((*nomeArquivo)) - 1){
                    verificadoNomeArquivo = 1;
                    nomeArquivoTmp[strlen((*nomeArquivo))] = '\0';
                }
            }        

            if(strcmp(nomeArquivoTmp,"SAIR") == 0){
                strcpy((*nomeArquivo),"SAIR\0");
                return;
            }
            
            if(verificadoNomeArquivo == 0)
                printf("Nome do arquivo invalido. Tente Novamente: ");
        }    


        tmpTamanho = strlen(nomeArquivoTmp);
        if(nomeArquivoTmp[tmpTamanho-1] != 'T' && nomeArquivoTmp[tmpTamanho-2] != 'X' && nomeArquivoTmp[tmpTamanho-3] != 'T' && nomeArquivoTmp[tmpTamanho-4] != '.'){
            (*nomeArquivo)[tmpTamanho] = '.';
            (*nomeArquivo)[tmpTamanho+1] = 't';
            (*nomeArquivo)[tmpTamanho+2] = 'x';
            (*nomeArquivo)[tmpTamanho+3] = 't';
            (*nomeArquivo)[tmpTamanho+4] = '\0';
        }

        dicionario = fopen((*nomeArquivo), "r");

        //---------------------------------------------------------------------------------------------
        
        printf("Abrindo \"%s\"...\n", (*nomeArquivo));
        if(dicionario == NULL){
            printf("\nErro ao abrir arquivo..");
            verificadoNomeArquivo = 0;
        }
        else
            break;
    }

}