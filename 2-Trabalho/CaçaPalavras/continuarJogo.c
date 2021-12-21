// void salvaJogo(int quantidade, int tamLin, int tamCol, Item **tabuleiro, Palavra *palavras, char nomeArquivoSave[]);
// void printResolvido(int tamLin, int tamCol, Item **tabuleiro);
// void continuaJogo();
// void resolveTabuleiro(int quantidade, int tamLin, int tamCol, Item **tabuleiro, Palavra *palavras);
// void sairJogo();
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
#include "Headers/continuarJogo.h"
#include "Headers/jogar.h"
#include "Headers/outros.h"


void salvaJogo(int quantidade, int tamLin, int tamCol, Item **tabuleiro, Palavra *palavras, char nomeArquivoSave[]){
    FILE *save = fopen(nomeArquivoSave, "w");

    printf("\nAbrindo \"%s\"...\n", nomeArquivoSave);
    if(save == NULL){
        printf("Erro ao abrir Aquivo.");
        return;
    }

    fprintf(save, "%i %i\n", tamLin, tamCol);

    for (int i = 0; i < tamLin; i++){
        for (int j = 0; j < tamCol; j++){
            fprintf(save, "%c ", tabuleiro[i][j].caractere);
        }
        fprintf(save, "\n");        
    }    

    fprintf(save, "%i\n", quantidade);

    for (int i = 0; i < quantidade; i++){
        if(palavras[i].marcado == 1)
            fprintf(save, "%s %c%c %c%c\n", palavras[i].palavra, palavras[i].limC + 'A', palavras[i].colC + 'A', palavras[i].limF + 'A', palavras[i].colF + 'A');

        else
            fprintf(save, "%s -- --\n", palavras[i].palavra);
    }


    fclose(save);
}

void continuaJogo(){

    Item **tabuleiro;
    Palavra *palavras;

    char tmp;
    int tamLin, tamCol, quantidade;

    //------------------------------------------------------------------------

    // char *nomeArquivo;
    // nomeArquivo = malloc(100 * sizeof(char));

    // if(nomeArquivo == NULL){
    //     printf("Erro");
    //     return;
    // }

    // FILE *save;  
   
    // leNomeArquivo(&nomeArquivo);
    // if(strcmp(nomeArquivo, "SAIR") == 0)
    //     return;
    // save = fopen(nomeArquivo, "r");
    // free(nomeArquivo);

    FILE *save = fopen("Files/save.txt", "r");

    //------------------------------------------------------------------------

    fscanf(save, "%i %i", &tamLin, &tamCol);
    tabuleiro = (Item**)malloc(tamLin*sizeof(Item*));
    for(int i = 0; i < tamLin; i++)
        (tabuleiro)[i] = (Item*)malloc(tamCol*sizeof(Item));

    if(tabuleiro == NULL){
        printf("\nErro.");
        return;
    }
    
    for (int i = 0; i < tamLin; i++){
        for (int j = 0; j < tamCol; j++){
            fscanf(save, "%c", &tmp);
            if(tmp >= 'A' && tmp <= 'Z')
                tabuleiro[i][j].caractere = tmp;
            else
                j--;
        }
    }  


    //---------------------------------------------------------------------------------------------

    fscanf(save, "%i", &quantidade);
    palavras = malloc(quantidade * sizeof(Palavra));

    if(palavras == NULL){
        printf("\nErro.");
        return;
    }

    //---------------------------------------------------------------------------------------------

    fscanf(save, "%c", &tmp);
    for (int i = 0; i < quantidade; i++){
        for (int j = 0; j < 100; j++){
            fscanf(save, "%c", &tmp);   

            if(tmp >= 'A' && tmp <= 'Z')
                palavras[i].palavra[j] = tmp;

            if(tmp == ' ')
                break;
        }
        
        fscanf(save, "%c", &tmp);
        if(tmp >= 'A' && tmp <= 'Z'){
            palavras[i].limC = tmp - 'A';
            fscanf(save, "%c", &tmp);
            palavras[i].colC = tmp - 'A';
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            palavras[i].limF = tmp - 'A';
            fscanf(save, "%c", &tmp);
            palavras[i].colF = tmp - 'A';
            fscanf(save, "%c", &tmp);
            palavras[i].marcado = 1;
        }
        else{
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            palavras[i].marcado = 0;
        }    

        palavras[i].tamanho = strlen(palavras[i].palavra);    

    }  

    fclose(save);
    
    
    resolveTabuleiroSaveGame(quantidade, tamLin, tamCol, tabuleiro, palavras);
    jogar(palavras, tabuleiro, tamLin, tamCol, quantidade);
}

void resolveTabuleiroSaveGame(int quantidade, int tamLin, int tamCol, Item **tabuleiro, Palavra *palavras){
    
    int aprovado = 1, teste = 0;

    for (int i = 0; i < tamLin; i++)
        for (int j = 0; j < tamCol; j++)
            tabuleiro[i][j].fazPartePalavra == 0;

    for (int contColocadas = 0; contColocadas < quantidade; contColocadas++){
        
        for (int lim = 0; lim < tamLin; lim++){
            for (int col = 0; col < tamCol; col++){

                //######################################################################################################################## 0

                if(col + palavras[contColocadas].tamanho <= tamCol){

                    for (int i = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++){
                        if(tabuleiro[lim][i].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){
                        for (int i = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++){
                            tabuleiro[lim][i].fazPartePalavra = 1;
                            tabuleiro[lim][i].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        for (int i = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++){
                            tabuleiro[lim][i].fazPartePalavra = 1;
                            tabuleiro[lim][i].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;

                }

                //######################################################################################################################## 1

                if(lim + palavras[contColocadas].tamanho <= tamLin){

                    for (int i = lim, j = 0; j < palavras[contColocadas].tamanho; i++, j++){
                        if(tabuleiro[i][col].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){                        
                        for (int i = lim, j = 0; j < palavras[contColocadas].tamanho; i++, j++){
                            tabuleiro[i][col].fazPartePalavra = 1;
                            tabuleiro[i][col].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        
                        for (int i = lim, j = 0; j < palavras[contColocadas].tamanho; i++, j++){
                            tabuleiro[i][col].fazPartePalavra = 1;
                            tabuleiro[i][col].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }

                //######################################################################################################################## 2

                if(lim + palavras[contColocadas].tamanho <= tamLin && col + palavras[contColocadas].tamanho <= tamCol){
                    for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++, k++){
                        if(tabuleiro[i][k].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++, k++){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++, k++){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }

                //######################################################################################################################## 3

                if(col + palavras[contColocadas].tamanho <= tamCol && lim - palavras[contColocadas].tamanho >= 0){
                
                    for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++, k++){
                        if(tabuleiro[i][k].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++, k++){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++, k++){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }
    
                //######################################################################################################################## 4

                if(lim - palavras[contColocadas].tamanho >= 0){
                    for (int i = lim, j = 0; j < palavras[contColocadas].tamanho; i--, j++){
                        if(tabuleiro[i][col].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){
                        
                        for (int i = lim, j = 0; j < palavras[contColocadas].tamanho; i--, j++){
                            tabuleiro[i][col].fazPartePalavra = 1;
                            tabuleiro[i][col].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        
                        for (int i = lim, j = 0; j < palavras[contColocadas].tamanho; i--, j++){
                            tabuleiro[i][col].fazPartePalavra = 1;
                            tabuleiro[i][col].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }

                //######################################################################################################################## 5

                if(col - palavras[contColocadas].tamanho >= 0){
                    for (int i = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++){
                        if(tabuleiro[lim][i].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){
                        
                        for (int i = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++){
                            tabuleiro[lim][i].fazPartePalavra = 1;
                            tabuleiro[lim][i].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        
                        for (int i = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++){
                            tabuleiro[lim][i].fazPartePalavra = 1;
                            tabuleiro[lim][i].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }

                //######################################################################################################################## 6

                if(lim - palavras[contColocadas].tamanho >= 0 && col - palavras[contColocadas].tamanho >= 0){
                    for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++, k--){
                        if(tabuleiro[i][k].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++, k--){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++, k--){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }
                
                //######################################################################################################################## 7

                if(lim + palavras[contColocadas].tamanho <= tamLin && col - palavras[contColocadas].tamanho >= 0){
                    for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++, k--){
                        if(tabuleiro[i][k].fazPartePalavra != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++, k--){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++, k--){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }

            }
            if(teste == 1){
                teste = 0;
                break;
            }
        }
        
    }
    
}
