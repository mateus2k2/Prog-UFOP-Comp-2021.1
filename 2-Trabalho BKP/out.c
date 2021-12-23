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

void leNomeArquivo(char *nomeArquivo[]){

    char nomeArquivoTmp[100];
    int tmpTamanho = 0, verificadoNomeArquivo = 0;

    FILE *dicionario;

    while (1){
        printf("\nDigite o nome do arquivo: ");
        while (verificadoNomeArquivo == 0){
            fgets(*nomeArquivo, 100, stdin);
            *nomeArquivo[strlen(*nomeArquivo)-1] = '\0';

            for (int i = 0; i < strlen(*nomeArquivo); i++){
                if((*nomeArquivo[i] >= 'a' && *nomeArquivo[i] <= 'z'))
                    nomeArquivoTmp[i] = *nomeArquivo[i]-32;

                else if(*nomeArquivo[i] != '/')
                    nomeArquivoTmp[i] = *nomeArquivo[i];
                
                else{
                    verificadoNomeArquivo = 0;
                    break;
                }

                if(i == strlen(*nomeArquivo) - 1){
                    verificadoNomeArquivo = 1;
                    nomeArquivoTmp[strlen(*nomeArquivo)] = '\0';
                }
            }        

            if(strcmp(nomeArquivoTmp,"SAIR") == 0)
                return;
            
            if(verificadoNomeArquivo == 0)
                printf("Nome do arquivo invalido. Tente Novamente: ");
        }    


        tmpTamanho = strlen(nomeArquivoTmp);
        if(nomeArquivoTmp[tmpTamanho-1] != 'T' && nomeArquivoTmp[tmpTamanho-2] != 'X' && nomeArquivoTmp[tmpTamanho-3] != 'T' && nomeArquivoTmp[tmpTamanho-4] != '.'){
            *nomeArquivo[tmpTamanho] = '.';
            *nomeArquivo[tmpTamanho+1] = 't';
            *nomeArquivo[tmpTamanho+2] = 'x';
            *nomeArquivo[tmpTamanho+3] = 't';
            *nomeArquivo[tmpTamanho+4] = '\0';
        }

        dicionario = fopen(*nomeArquivo, "r");

        //---------------------------------------------------------------------------------------------
        
        printf("Abrindo \"%s\"...\n", *nomeArquivo);
        if(dicionario == NULL){
            printf("\nErro ao abrir arquivo..");
            verificadoNomeArquivo = 0;
        }
        else
            break;
    }

}