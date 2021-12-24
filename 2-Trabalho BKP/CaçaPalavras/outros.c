//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/structs.h"
#include "Headers/cores.h"
#include "Headers/outros.h"


void printTabuleiro(int tamLin, int tamCol, Item **tabuleiro, int escolha){

    //Primeira parte da tabela
    printf(BG_BLACK(TAB_TL));
    for (int i = 0; i < tamCol+1; i++){
        if(i != tamCol)
            printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_TJ));
    }
    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_TR) "\n");

    //----------------------------------------------------------------------

    //Parte com os caracteres de referencia da Horizontal
    printf(BG_BLACK(TAB_VER));

    printf(BG_BLACK("   "));
    for (int i = 0; i < tamCol; i++)
        printf(BG_BLACK(TAB_VER BOLD(BLUE(" %c "))), 'A'+ i);

    printf(BG_BLACK(TAB_VER));

    printf("\n");

    //----------------------------------------------------------------------

    //União dos caracteres de referencia com a tabela principal
    printf(BG_BLACK(TAB_ML));

    for (int i = 0; i < tamCol; i++)
        printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MJ));

    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MR) "\n");


    //----------------------------------------------------------------------


    for (int i = 0; i < tamLin; i++){
        //Print dos caracteres de referência na vertical (um a cada inicio da linha)
        printf(BG_BLACK (TAB_VER BOLD(BLUE(" %c "))), 'A'+ i);
        for (int j = 0; j < tamCol; j++){
            //Interpreta se é para printar a resolução ou apenas as palavras ja marcadas
            if(tabuleiro[i][j].fazPartePalavra == 1 && escolha == 1){
                printf(BG_BLACK(TAB_VER BOLD(RED(" %c "))), tabuleiro[i][j].caractere);
            }
            else if(tabuleiro[i][j].marcadoUsuario == 1 && escolha == 0){
                printf(BG_BLACK(TAB_VER BOLD(MAGENTA(" %c "))), tabuleiro[i][j].caractere);
            }
            
            else
                printf(BG_BLACK(TAB_VER BOLD(WHITE(" %c "))), tabuleiro[i][j].caractere);
        }  
        printf(BOLD(BG_BLACK(TAB_VER)));

        //Se for a ultima linha print a união entre o fim da tabela com a parte de baixo da tabela
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

    //Parte de baixo da tabela
    printf(BG_BLACK(TAB_BL));
    for (int i = 0; i < tamCol+1; i++){
        if(i != tamCol)
            printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_BJ));
    }
    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_BR) "\n");


}

void sairJogo(Item **tabuleiro, Palavra *palavras, int tamLin){

    //Libera a matriz e o vetor
    for (int i = 0; i < tamLin; i++)
        free(tabuleiro[i]);
    free(tabuleiro); 

    free(palavras); 
}

void leNomeArquivo(char *nomeArquivo[]){

    char nomeArquivoTmp[100];
    int tmpTamanho = 0, verificadoNomeArquivo = 0;

    FILE *arquivoTmp;

    while (1){
        printf("\nDigite o nome do arquivo: ");
        while (verificadoNomeArquivo == 0){
            fgets((*nomeArquivo), 100, stdin);
            //Remove o '\n' do final do nome
            (*nomeArquivo)[strlen((*nomeArquivo))-1] = '\0';

            //Percorre o nome
            for (int i = 0; i < strlen((*nomeArquivo)); i++){
                //Se o caractere atual for uma letra minúscula copia a sua versão maiúscula para nomeArquivoTmp
                if(((*nomeArquivo)[i] >= 'a' && (*nomeArquivo)[i] <= 'z'))
                    nomeArquivoTmp[i] = (*nomeArquivo)[i]-32;

                //Se o caractere atual não for uma letra minúscula e nem um dos caracteres proibidos copia para nomeArquivoTmp
                else if((*nomeArquivo)[i] != '<' && (*nomeArquivo)[i] != '>' && (*nomeArquivo)[i] != ':' && (*nomeArquivo)[i] != '|' && (*nomeArquivo)[i] != '?' && (*nomeArquivo)[i] != '*' && (*nomeArquivo)[i] != '"')
                    nomeArquivoTmp[i] = (*nomeArquivo)[i];
                
                //Se não o sai do loop
                else{
                    verificadoNomeArquivo = 0;
                    break;
                }

                //Se chegou no ultimo caso então coloca um '\0' no final do arquivoTmp e verificadoNomeArquivo recebe 1 
                if(i == strlen((*nomeArquivo)) - 1){
                    verificadoNomeArquivo = 1;
                    nomeArquivoTmp[strlen((*nomeArquivo))] = '\0';
                }
            }        

            //Se o que for digitado foi sair então sai da função
            if(strcmp(nomeArquivoTmp,"SAIR") == 0){
                strcpy((*nomeArquivo),"SAIR\0");
                return;
            }
            
            if(verificadoNomeArquivo == 0)
                printf("Nome do arquivo invalido. Tente Novamente: ");
        }    

        //Verifica se no fim do nome existe '.txt'
        //Se nao for, então é colocado
        tmpTamanho = strlen(nomeArquivoTmp);
        if(nomeArquivoTmp[tmpTamanho-1] != 'T' && nomeArquivoTmp[tmpTamanho-2] != 'X' && nomeArquivoTmp[tmpTamanho-3] != 'T' && nomeArquivoTmp[tmpTamanho-4] != '.'){
            (*nomeArquivo)[tmpTamanho] = '.';
            (*nomeArquivo)[tmpTamanho+1] = 't';
            (*nomeArquivo)[tmpTamanho+2] = 'x';
            (*nomeArquivo)[tmpTamanho+3] = 't';
            (*nomeArquivo)[tmpTamanho+4] = '\0';
        }

        //Abre o arquivo
        arquivoTmp = fopen((*nomeArquivo), "r");

        //---------------------------------------------------------------------------------------------
        
        printf("Abrindo \"%s\"...\n", (*nomeArquivo));
        // Se nao foi possível abrir o arquivo então tudo começa de novo
        if(arquivoTmp == NULL){
            printf("\nErro ao abrir arquivo..");
            verificadoNomeArquivo = 0;
        }
        //Se abriu então sai do loop e fecha o arquivo
        else{
            break;
            fclose(arquivoTmp);
        }
    }

}