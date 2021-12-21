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
#include "Headers/jogar.h"
#include "Headers/continuarJogo.h"
#include "Headers/outros.h"

void jogar(Palavra *palavras ,Item **tabuleiro, int tamLin, int tamCol, int quantidade){
    
    char comandoCompleto[100];
    int encontradas=0, retornoVerificacao;
    Comando comando;

    //---------------------------------------------------------------------------------------------

    printf("\n");

    printResolvido(tamLin, tamCol, tabuleiro, 0);

    //----------------------------------------------------------------------    

    while (encontradas != quantidade){

        comando.numeroComando = 0;
        comando.limC = tamLin+1; 
        comando.colC = tamCol+1;
        comando.limF = tamLin+1;
        comando.colF = tamCol+1;
        
        //---------------------------------------------------------------------------------------------
        
        while (comando.numeroComando == 0 || (comando.numeroComando == 1 && (comando.limC > tamLin-1 || comando.limF > tamLin-1 || comando.colC > tamCol-1 || comando.colF > tamCol-1))){
            printf("\nDigite o Comando: ");
            fgets(comandoCompleto, 100, stdin);
            comandoCompleto[strlen(comandoCompleto)-1] = '\0';

            comando = interpretaComando(comandoCompleto);    

            if(comando.numeroComando == 0)
                printf("Comando Invalido!\n");

            if(comando.numeroComando == 1 && (comando.limC > tamLin-1 || comando.limF > tamLin-1 || comando.colC > tamCol-1 || comando.colF > tamCol-1))
                printf("Indice Invalido!\n");        
        }

        //---------------------------------------------------------------------------------------------

        if(comando.numeroComando == 1){
            retornoVerificacao = verificaEscolha(comando, palavras, tabuleiro, &encontradas, quantidade, tamCol, tamLin);

            if(retornoVerificacao == 0)
                printf("Palavra invalida\n");
            if(retornoVerificacao == 1)
                printf("Palavra marcada\n");
            if(retornoVerificacao == 2)
                printf("Palavra repetida ou ja marcada\n");
        }

        else if(comando.numeroComando == 2){
            salvaJogo(quantidade, tamLin, tamCol, tabuleiro, palavras, comando.nomeArquivoSave);
        }

        else if(comando.numeroComando == 3){
            printResolvido(tamLin, tamCol, tabuleiro, 1);
            sairJogo(tabuleiro, palavras, tamLin);
            printf("\nPena que nao conseguiu resolver, tchau!");
            return;
        } 
        
        else{
            sairJogo(tabuleiro, palavras, tamLin);
            return;
        }

        //---------------------------------------------------------------------------------------------

        printf("\n");    

        printResolvido(tamLin, tamCol, tabuleiro, 0);

        if(encontradas == quantidade){
            sairJogo(tabuleiro, palavras, tamLin);
            printf("\nTodas as palavra encontradas!");

        }
    }

    return;
}

int verificaEscolha(Comando comando, Palavra *palavras, Item **tabuleiro, int *encontradas, int quantidade, int tamCol, int tamLin){
    int direcao;

    //Verificar direcao 
    if(comando.colC != comando.colF && comando.limC == comando.limF && comando.colC < comando.colF)
        direcao = 0;
    else if(comando.colC == comando.colF && comando.limC != comando.limF && comando.limC < comando.limF)
        direcao = 1;
    else if(comando.colC < comando.colF && comando.limC < comando.limF)
        direcao = 2;
    else if(comando.colC < comando.colF && comando.limC < comando.limF)
        direcao = 3;
    else if(comando.colC == comando.colF && comando.limC != comando.limF && comando.limC > comando.limF)
        direcao = 4;
    else if(comando.colC != comando.colF && comando.limC == comando.limF && comando.colC > comando.colF)
        direcao = 5;
    else if(comando.colC > comando.colF && comando.limC > comando.limF)
        direcao = 6;
    else if(comando.colC > comando.colF && comando.limC < comando.limF)
        direcao = 7;
    else if(comando.colC == comando.colF && comando.limC == comando.limF)
        direcao = 0;
    

    if(direcao == 0){
            for (int t = 0; t < quantidade; t++){
                for (int i = comando.colC, j = 0; j < palavras[(t)].tamanho; i++, j++){
                    if(tabuleiro[comando.limC][i].caractere != palavras[(t)].palavra[j]){
                        break;
                    }                     
        
                    if(i == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 0){
                        palavras[t].marcado = 1;
                        (*encontradas)++;

                        palavras[t].limC = comando.limC;
                        palavras[t].colC = comando.colC;
                        palavras[t].limF = comando.limF;
                        palavras[t].colF = comando.colF;

                        for (int u = comando.colC, p = 0; p < palavras[(t)].tamanho; u++, p++)   {                         
                            tabuleiro[comando.limC][u].marcadoUsuario = 1;
                        }

                        return 1;
                    }
                    
                    if(i == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 1){
                        return 2;
                    }
                }
            }
            return 0;
        }

    //-----------------------------------------------------------------------------------------------------1

    else if(direcao == 1){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, j = 0; j < palavras[t].tamanho; i++, j++){
                if(tabuleiro[i][comando.colC].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 0){
                        palavras[t].marcado = 1;
                        (*encontradas)++;

                        palavras[t].limC = comando.limC;
                        palavras[t].colC = comando.colC;
                        palavras[t].limF = comando.limF;
                        palavras[t].colF = comando.colF;

                        for (int u = comando.limC, p = 0; p < palavras[(t)].tamanho; u++, p++){                            
                            tabuleiro[u][comando.colC].marcadoUsuario = 1;
                        }

                        return 1;
                }
                
                if(i == comando.limF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    //-----------------------------------------------------------------------------------------------------2

   else if(direcao == 2){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.colC, j = 0; j < palavras[t].tamanho; i++, j++, k++){
                if(tabuleiro[i][k].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 0){
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    for (int u = comando.limC, q = comando.colC, p = 0; p < palavras[t].tamanho; u++, p++, q++){                            
                        tabuleiro[u][q].marcadoUsuario = 1;
                    }

                    return 1;
                }
                
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    //-----------------------------------------------------------------------------------------------------3

    else if(direcao == 3){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.colC, j = 0; j < palavras[t].tamanho; i--, j++, k++){
                if(tabuleiro[i][k].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 0){
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    for (int u = comando.limC, q = comando.colC, p = 0; p < palavras[t].tamanho; u--, p++, q++){                            
                        tabuleiro[u][q].marcadoUsuario = 1;
                    }

                    return 1;
                }
                
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    // //-----------------------------------------------------------------------------------------------------4

    else if(direcao == 4){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, j = 0; j < palavras[t].tamanho; i--, j++){
                if(tabuleiro[i][comando.colC].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 0){
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    for (int u = comando.limC, p = 0; p < palavras[t].tamanho; u--, p++){                            
                        tabuleiro[u][comando.colC].marcadoUsuario = 1;
                    }

                    return 1;
                }
                
                if(i == comando.limF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    // //-----------------------------------------------------------------------------------------------------5

    else if(direcao == 5){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.colC, j = 0; j < palavras[t].tamanho; i--, j++){
                if(tabuleiro[comando.limC][i].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 0){
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    for (int u = comando.colC, p = 0; p < palavras[t].tamanho; u--, p++){                            
                        tabuleiro[u][comando.limC].marcadoUsuario = 1;
                    }

                    return 1;
                }
                
                if(i == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    // //-----------------------------------------------------------------------------------------------------6

    else if(direcao == 6){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.colC, j = 0; j < palavras[t].tamanho; i--, j++, k--){
                if(tabuleiro[i][k].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 0){
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    for (int u = comando.limC, q = comando.colC, p = 0; p < palavras[t].tamanho; u--, p++, q--){                            
                        tabuleiro[u][q].marcadoUsuario = 1;
                    }

                    return 1;
                }
                
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    // //-----------------------------------------------------------------------------------------------------7

    else if(direcao == 7){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.colC, j = 0; j < palavras[t].tamanho; i++, j++, k--){
                if(tabuleiro[i][k].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 0){
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    for (int u = comando.limC, q = comando.colC, p = 0; p < palavras[t].tamanho; u++, p++, q--){                            
                        tabuleiro[u][q].marcadoUsuario = 1;
                    }

                    return 1;
                }
                
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }   

}

Comando interpretaComando(char comandoCompleto[]){
    Comando comando;

    char marcar[] = "MARCAR\0";

    char salvar[] = "SALVAR\0";
    char nomeArquivoTmp[100];
    int indiceFim = 0;
    int tamanhoTmp;

    for (int i = 0; i < strlen(comandoCompleto); i++){
        nomeArquivoTmp[i] = comandoCompleto[i];

        if(comandoCompleto[i] >= 'a' && comandoCompleto[i] <= 'z')
                comandoCompleto[i] = comandoCompleto[i] - 32;        
    }
    nomeArquivoTmp[strlen(comandoCompleto)] = '\0';

    if(strstr(comandoCompleto, "MARCAR") != NULL && comandoCompleto[6] == ' ') {
        for (int i = 0; i < 6; i++){
            if(comandoCompleto[i] != marcar[i]){
                comando.numeroComando = 0;
                return comando;
            }
        }

        if( (comandoCompleto[6] == ' ') && 
            (comandoCompleto[7] >= 'A' && comandoCompleto[7] <= 'Z') &&
            (comandoCompleto[8] >= 'A' && comandoCompleto[8] <= 'Z') &&
            (comandoCompleto[9] == ' ') &&
            (comandoCompleto[10] >= 'A' && comandoCompleto[10] <= 'Z') &&
            (comandoCompleto[11] >= 'A' && comandoCompleto[11] <= 'Z')){    
              
            comando.limC =  comandoCompleto[7] - 'A';
            comando.colC =  comandoCompleto[8] - 'A';
            comando.limF =  comandoCompleto[10] - 'A';
            comando.colF =  comandoCompleto[11] - 'A';
        }

        else{
            comando.numeroComando = 0;
            return comando;
        } 
        
        comando.numeroComando = 1;
        return comando;        
    }
    else if(strstr(comandoCompleto, "SALVAR") != NULL){
        for (int i = 0; i < 6; i++){
            if(comandoCompleto[i] != salvar[i]){
                comando.numeroComando = 0;
                return comando;
            }
        }
        if(comandoCompleto[6] == ' '){
            for (int i = 0; i < strlen(comandoCompleto); i++){   
                if(comandoCompleto[i] == '.' && comandoCompleto[i+1] == 'T' && comandoCompleto[i+2] == 'X' && comandoCompleto[i+3] == 'T'){
                    indiceFim = i;
                    break;
                }

                if((comandoCompleto[i] == '<') || (comandoCompleto[i] == '>') || (comandoCompleto[i] == ':') || (comandoCompleto[i] == '"') || (comandoCompleto[i] == '|') || (comandoCompleto[i] == '?') || (comandoCompleto[i] == '*')){
                    comando.numeroComando = 0;
                    return comando;
                }
                
            }

            if(indiceFim != 0)
                for (int i = 7, j = 0; j < indiceFim - 7; i++, j++){
                    comando.nomeArquivoSave[j] = nomeArquivoTmp[i];
                    if(j == (indiceFim - 7)-1)
                        comando.nomeArquivoSave[j+1] = '\0';
                }
            else{
                for (int i = 7, j = 0; j < strlen(comandoCompleto) - 7; i++, j++){
                    comando.nomeArquivoSave[j] = nomeArquivoTmp[i];
                    if(j == (strlen(comandoCompleto) - 7)-1)
                        comando.nomeArquivoSave[j+1] = '\0';

                }                
            }
            tamanhoTmp = strlen(comando.nomeArquivoSave);
            comando.nomeArquivoSave[tamanhoTmp+0] = '.';
            comando.nomeArquivoSave[tamanhoTmp+1] = 't';
            comando.nomeArquivoSave[tamanhoTmp+2] = 'x';
            comando.nomeArquivoSave[tamanhoTmp+3] = 't';
            comando.nomeArquivoSave[tamanhoTmp+4] = '\0';

            comando.numeroComando = 2;
            return comando;           
        }

        else{
            comando.numeroComando = 0;
            return comando;
        }

    }
    else if(strstr(comandoCompleto, "RESOLVER") != NULL && strlen(comandoCompleto) == 8){
        comando.numeroComando = 3;
        return comando;
    }
    else if(strstr(comandoCompleto, "SAIR") != NULL && strlen(comandoCompleto) == 4) {
        comando.numeroComando = 4;
        return comando;
    }
    else{
        comando.numeroComando = 0;
        return comando;
    }

}   
