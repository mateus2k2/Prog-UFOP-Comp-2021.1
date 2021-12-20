// void criarJogo();
// void colocaPalavra(int escolhaDirecao, int *contColocadas, int lim, int col, int tamLin, int tamCol, Palavra *palavras ,Item **tabuleiro, int *contDirecao);
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
#include "Headers/outros.h"
#include "Headers/jogar.h"
#include "Headers/criaTabuleiro.h"


void criarJogo(){
    Item **tabuleiro;
    Palavra *palavras;

    char tmp[100];
    int tmpTamanho;

    int contDirecao[8] = {0};
    int tabuleiroPronto = 0, verificadoNomeArquivo = 0;

    int tamLin, tamCol, quantidade, dificuldade;
    int escolhaDirecao = 0, escolhaColocar, escolhaLetra, contColocadas = 0;

    int totalLetrasPalavras = 0, TotalTamanhoTabuleiro = 0;
    double razao;

    char nomeArquivo[100], nomeArquivoTmp[100];
    FILE *dicionario;

    // while (1){
    //     printf("\nDigite o nome do arquivo: ");
    //     while (verificadoNomeArquivo == 0){
    //         fgets(nomeArquivo, 100, stdin);
    //         nomeArquivo[strlen(nomeArquivo)-1] = '\0';

    //         for (int i = 0; i < strlen(nomeArquivo); i++){
    //             if((nomeArquivo[i] >= 'a' && nomeArquivo[i] <= 'z'))
    //                 nomeArquivoTmp[i] = nomeArquivo[i]-32;

    //             else if(nomeArquivo[i] != '/')
    //                 nomeArquivoTmp[i] = nomeArquivo[i];
                
    //             else{
    //                 verificadoNomeArquivo = 0;
    //                 break;
    //             }

    //             if(i == strlen(nomeArquivo) - 1){
    //                 verificadoNomeArquivo = 1;
    //                 nomeArquivoTmp[strlen(nomeArquivo)] = '\0';
    //             }
    //         }        

    //         if(strcmp(nomeArquivoTmp,"SAIR") == 0)
    //             return;
            
    //         if(verificadoNomeArquivo == 0)
    //             printf("Nome do arquivo invalido. Tente Novamente: ");
    //     }    


    //     tmpTamanho = strlen(nomeArquivoTmp);
    //     if(nomeArquivoTmp[tmpTamanho-1] != 'T' && nomeArquivoTmp[tmpTamanho-2] != 'X' && nomeArquivoTmp[tmpTamanho-3] != 'T' && nomeArquivoTmp[tmpTamanho-4] != '.'){
    //         nomeArquivo[tmpTamanho] = '.';
    //         nomeArquivo[tmpTamanho+1] = 't';
    //         nomeArquivo[tmpTamanho+2] = 'x';
    //         nomeArquivo[tmpTamanho+3] = 't';
    //         nomeArquivo[tmpTamanho+4] = '\0';
    //     }

    //     dicionario = fopen(nomeArquivo, "r");

    //     //---------------------------------------------------------------------------------------------
        
    //     printf("Abrindo \"%s\"...\n", nomeArquivo);
    //     if(dicionario == NULL){
    //         printf("\nErro ao abrir arquivo..");
    //         verificadoNomeArquivo = 0;
    //     }
    //     else
    //         break;

    // }   
   
    dicionario = fopen("Files/dicionario.txt", "r");
    fscanf(dicionario, "%i %i", &tamLin, &tamCol);
    TotalTamanhoTabuleiro = tamLin * tamCol;

    if(tamLin > 26 || tamCol > 26){
        printf("\nTabuleiro nao pode ser maior que 26 X 26...");
        return;
    }

    tabuleiro = (Item**)malloc(tamLin*sizeof(Item*));
    for(int i = 0; i < tamLin; i++)
        (tabuleiro)[i] = (Item*)malloc(tamCol*sizeof(Item));

    fscanf(dicionario, "%i", &quantidade);
    palavras = malloc(quantidade * sizeof(Palavra));

    if(tabuleiro == NULL || palavras == NULL){
        printf("\nErro.");
        return;
    }


    //---------------------------------------------------------------------------------------------

    printf("\nDigite o nivel de dificuldade:\n");

    printf("\n1.  Facil");
    printf("\n2.  Medio");
    printf("\n3.  Dificil\n\n");

    printf("Escolha a opcao: ");
    while (dificuldade != 1 && dificuldade != 2 && dificuldade != 3){
        scanf("%i", &dificuldade);
        while ((getchar()) != '\n');

        switch (dificuldade){
            case 1: dificuldade = 1; break;
            case 2: dificuldade = 2; break;
            case 3: dificuldade = 3; break;
            default: printf("Opcao Invalida. Tente Novamente: ");
                break;
        }
    }

    //---------------------------------------------------------------------------------------------

    fgets(tmp, 100, dicionario);

    if(quantidade == 0){
        printf("\n0 Palavras no imput"); 
        sairJogo(tabuleiro, palavras, tamLin);
        return;
    }

    for (int i = 0; i < quantidade; i++){
        fgets(palavras[i].palavra, 100, dicionario);

        if(i != quantidade-1){
            palavras[i].palavra[strlen(palavras[i].palavra)-1] = '\0';
        }
        
        palavras[i].tamanho = strlen(palavras[i].palavra);

        if(palavras[i].tamanho > tamCol && palavras[i].tamanho > tamLin){
            printf("\nPalavra \"%s\" Rejeitada. Muita grande para o tabuleiro.\n", palavras[i].palavra);
            i--;
            quantidade--;
        }
        else
            totalLetrasPalavras = totalLetrasPalavras + palavras[i].tamanho;
    } 

    //Verifica se tem repetidas
    for(int i = 0; i < quantidade; i++){
        for(int j = i+1; j < quantidade; j++){
            if(strcmp(palavras[i].palavra, palavras[j].palavra) == 0){
                for (int k = j; k < quantidade - 1; k++){
                    strcpy(palavras[k].palavra, palavras[k+1].palavra);
                    palavras[k].tamanho = palavras[k+1].tamanho;  
                }
                quantidade--;
                j--;
            }
        }   
    }

    //sort palavras
    for(int i = 0; i < quantidade-1; i++){
        for(int j = i+1; j < quantidade; j++){
            if(palavras[i].tamanho < palavras[j].tamanho){
                strcpy(tmp, palavras[i].palavra);
                strcpy(palavras[i].palavra, palavras[j].palavra);
                strcpy(palavras[j].palavra, tmp);

                tmpTamanho = palavras[i].tamanho;
                palavras[i].tamanho = palavras[j].tamanho;
                palavras[j].tamanho = tmpTamanho;            
            }
        }    
    }

    for (int i = 0; i < quantidade; i++){
        for (int j = 0; j < palavras[i].tamanho; j++){
            if(palavras[i].palavra[j] >= 'a' && palavras[i].palavra[j] <= 'z')
                palavras[i].palavra[j] = palavras[i].palavra[j] - 32;
        }        
    } 

    razao = (double)totalLetrasPalavras / (double)TotalTamanhoTabuleiro;

    if(razao > 1){
        printf("Muitas palavras para o tabuleiro. ");
        sairJogo(tabuleiro, palavras, tamLin);
        return;
    }

    //---------------------------------------------------------------------------------------------
    
    for (int i = 0; i < 8; i++)
        contDirecao[i] = 0;

    for (int l = 0; l < tamLin; l++){
        for (int k = 0; k < tamCol; k++){
            escolhaLetra = rand() % (26);
            tabuleiro[l][k].caractere = escolhaLetra + 'A';
            tabuleiro[l][k].fazPartePalavra = 0;
            tabuleiro[l][k].marcadoUsuario = 0;
        }       
    }

    double contTentativas = 0;

    while (1){
        contTentativas = contTentativas + 1;

        for (int i = 0; i < tamLin; i++){
            for (int j = 0; j < tamCol; j++){
                
                //Dificuldade 1
                if(dificuldade == 1){
                    escolhaDirecao = rand() % (2);
                    escolhaColocar = rand() % (1000) + (razao * 200);

                    if(escolhaColocar >= 995){
                        colocaPalavra(escolhaDirecao, &contColocadas, i, j, tamLin, tamCol, palavras, tabuleiro, contDirecao);
                    }

                    if(quantidade == contColocadas && contDirecao[0] != 0 && contDirecao [1] != 0){
                        tabuleiroPronto = 1;
                        break;
                    }
                }

                //Dificuldade 2
                else if(dificuldade == 2){
                    escolhaDirecao = rand() % (3);
                    escolhaColocar = rand() % (1000) + (razao * 200);

                    if(escolhaColocar >= 995){
                        colocaPalavra(escolhaDirecao, &contColocadas, i, j, tamLin, tamCol, palavras, tabuleiro, contDirecao);
                    }

                    if(quantidade == contColocadas && contDirecao[0] != 0 && contDirecao [1] != 0 && contDirecao[2] != 0){
                        tabuleiroPronto = 1;
                        break;
                    }
                }

                //Dificuldade 3
                else{
                    escolhaDirecao = rand() % (8);
                    escolhaColocar = rand() % (1000) + (razao * 200);

                    if(escolhaColocar >= 995){
                        colocaPalavra(escolhaDirecao, &contColocadas, i, j, tamLin, tamCol, palavras, tabuleiro, contDirecao);
                    }

                    if(quantidade == contColocadas && contDirecao[0] != 0 && contDirecao [1] != 0 && contDirecao[2] != 0 && contDirecao[7] != 0){
                        tabuleiroPronto = 1;
                        break;
                    }
                }
            }

            if(tabuleiroPronto == 1)
                break;       
        }

        if(tabuleiroPronto == 1)
            break; 

        else{
            contColocadas = 0;
            tabuleiroPronto = 0;
            for (int l = 0; l < tamLin; l++){
                for (int k = 0; k < tamCol; k++){
                    escolhaLetra = rand() % (26);
                    tabuleiro[l][k].caractere = escolhaLetra + 'A';
                    tabuleiro[l][k].fazPartePalavra = 0;
                    tabuleiro[l][k].marcadoUsuario = 0;
                }       
            }
            for (int i = 0; i < 8; i++)
                contDirecao[i] = 0;  
        }        
    }

    fclose(dicionario);
    
    //---------------------------------------------------------------------------------------------

    jogar(palavras ,tabuleiro, tamLin, tamCol, quantidade);

}

void colocaPalavra(int escolhaDirecao, int *contColocadas, int lim, int col, int tamLin, int tamCol, Palavra *palavras, Item **tabuleiro, int *contDirecao){
    
    int aprovado = 1;

    //-----------------------------------------------------------------------------------------------------0 
    if(escolhaDirecao == 0 && col + palavras[(*contColocadas)].tamanho <= tamCol){

        for (int i = col, j = 0; j < palavras[(*contColocadas)].tamanho; i++, j++){
            if(tabuleiro[lim][i].fazPartePalavra == 1 && tabuleiro[lim][i].caractere != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            for (int i = col, j = 0; j < palavras[(*contColocadas)].tamanho; i++, j++){
                tabuleiro[lim][i].caractere = palavras[(*contColocadas)].palavra[j];     
                tabuleiro[lim][i].fazPartePalavra = 1;
                tabuleiro[lim][i].marcadoUsuario = 0;
            }
            (*contColocadas)++;
            contDirecao[0] = contDirecao[0] + 1;
        }
        aprovado = 1;
    }

    //-----------------------------------------------------------------------------------------------------1

    else if(escolhaDirecao == 1 && lim + palavras[(*contColocadas)].tamanho <= tamLin){

        for (int i = lim, j = 0; j < palavras[(*contColocadas)].tamanho; i++, j++){
            if(tabuleiro[i][col].fazPartePalavra == 1 && tabuleiro[i][col].caractere != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, j = 0; j < palavras[(*contColocadas)].tamanho; i++, j++){
                tabuleiro[i][col].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][col].fazPartePalavra = 1;
                tabuleiro[i][col].marcadoUsuario = 0;
            }
            (*contColocadas)++;
            contDirecao[1] = contDirecao[1] + 1;
        }
        aprovado = 1;
    }

    //-----------------------------------------------------------------------------------------------------2

   else if(escolhaDirecao == 2 && lim + palavras[(*contColocadas)].tamanho <= tamLin && col + palavras[(*contColocadas)].tamanho <= tamCol){
        for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamanho; i++, j++, k++){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].caractere != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamanho; i++, j++, k++){
                tabuleiro[i][k].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][k].fazPartePalavra = 1;
                tabuleiro[i][k].marcadoUsuario = 0;
            }
            (*contColocadas)++;
            contDirecao[2] = contDirecao[2] + 1;
        }
        aprovado = 1;
    }

    //-----------------------------------------------------------------------------------------------------3

    else if(escolhaDirecao == 3 && col + palavras[(*contColocadas)].tamanho <= tamCol && lim - palavras[(*contColocadas)].tamanho >= 0){
       
        for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamanho; i--, j++, k++){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].caractere != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamanho; i--, j++, k++){
                tabuleiro[i][k].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][k].fazPartePalavra = 1;
                tabuleiro[i][k].marcadoUsuario = 0;
            }
            (*contColocadas)++;
            contDirecao[3]++;
        }
        aprovado = 1;
    }

    // //-----------------------------------------------------------------------------------------------------4

    else if(escolhaDirecao == 4 && lim - palavras[(*contColocadas)].tamanho >= 0){
        for (int i = lim, j = 0; j < palavras[(*contColocadas)].tamanho; i--, j++){
            if(tabuleiro[i][col].fazPartePalavra == 1 && tabuleiro[i][col].caractere != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, j = 0; j < palavras[(*contColocadas)].tamanho; i--, j++){
                tabuleiro[i][col].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][col].fazPartePalavra = 1;
                tabuleiro[i][col].marcadoUsuario = 0;
            }
            (*contColocadas)++;
            contDirecao[4] = contDirecao[4] + 1;
        }
        aprovado = 1;
    }

    // //-----------------------------------------------------------------------------------------------------5

    else if(escolhaDirecao == 5 && col - palavras[(*contColocadas)].tamanho >= 0){
        for (int i = col, j = 0; j < palavras[(*contColocadas)].tamanho; i--, j++){
            if(tabuleiro[lim][i].fazPartePalavra == 1 && tabuleiro[lim][i].caractere != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = col, j = 0; j < palavras[(*contColocadas)].tamanho; i--, j++){
                tabuleiro[lim][i].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[lim][i].fazPartePalavra = 1;
                tabuleiro[lim][i].marcadoUsuario = 0;
            }
            (*contColocadas)++;
            contDirecao[5] = contDirecao[5] + 1;
        }
        aprovado = 1;
    }

    // //-----------------------------------------------------------------------------------------------------6

    else if(escolhaDirecao == 6 && lim - palavras[(*contColocadas)].tamanho >= 0 && col - palavras[(*contColocadas)].tamanho >= 0){
        for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamanho; i--, j++, k--){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].caractere != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamanho; i--, j++, k--){
                tabuleiro[i][k].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][k].fazPartePalavra = 1;
                tabuleiro[i][k].marcadoUsuario = 0;
            }
            (*contColocadas)++;
            contDirecao[6] = contDirecao[6] + 1;
        }
        aprovado = 1;
    }

    // //-----------------------------------------------------------------------------------------------------7

    else if(escolhaDirecao == 7 && lim + palavras[(*contColocadas)].tamanho <= tamLin && col - palavras[(*contColocadas)].tamanho >= 0){
        for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamanho; i++, j++, k--){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].caractere != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamanho; i++, j++, k--){
                tabuleiro[i][k].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][k].fazPartePalavra = 1;
                tabuleiro[i][k].marcadoUsuario = 0;
            }
            (*contColocadas)++;
            contDirecao[7] = contDirecao[7] + 1;
        }
        aprovado = 1;
    }

}

