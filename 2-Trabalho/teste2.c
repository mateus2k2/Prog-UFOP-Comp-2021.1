typedef struct{
    char palavra[100];
    int marcado;
    int tamnho;
    int limC, colC;
    int limF, colF;
}Palavra;

typedef struct{
    char caractere;
    int fazPartePalavra;
    int marcadoUsuario;
}Item;

typedef struct{
    int numeroComando;
    char nomeArquivoSave[100];
    int limC, colC;
    int limF, colF;
}Comando;

void colocaPalavra(int escolhaDirecao, int contColocadas, int lim, int col, int tamLin, int tamCol, Palavra *palavras, Item **tabuleiro, int *contDirecao){
    
    int aprovado = 1;

    //-----------------------------------------------------------------------------------------------------0 
    if(col + palavras[contColocadas].tamnho <= tamCol){

        for (int i = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++){
            if(tabuleiro[lim][i].fazPartePalavra == 1 && tabuleiro[lim][i].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            for (int i = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++){
                tabuleiro[lim][i].fazPartePalavra = 1;
            }
            contColocadas++;
        }
        aprovado = 1;
        //break;
    }

    //-----------------------------------------------------------------------------------------------------1

    else if(escolhaDirecao == 1 && lim + palavras[contColocadas].tamnho <= tamLin){

        for (int i = lim, j = 0; j < palavras[contColocadas].tamnho; i++, j++){
            if(tabuleiro[i][col].fazPartePalavra == 1 && tabuleiro[i][col].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, j = 0; j < palavras[contColocadas].tamnho; i++, j++){
                tabuleiro[i][col].caractere = palavras[contColocadas].palavra[j];
                tabuleiro[i][col].fazPartePalavra = 1;
            }
            contColocadas++;
            contDirecao[1] = contDirecao[1] + 1;
        }
        aprovado = 1;
    }

    //-----------------------------------------------------------------------------------------------------2

   else if(escolhaDirecao == 2 && lim + palavras[contColocadas].tamnho <= tamLin && col + palavras[contColocadas].tamnho <= tamCol){
        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++, k++){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++, k++){
                tabuleiro[i][k].caractere = palavras[contColocadas].palavra[j];
                tabuleiro[i][k].fazPartePalavra = 1;
            }
            contColocadas++;
            contDirecao[2] = contDirecao[2] + 1;
        }
        aprovado = 1;
    }

    //-----------------------------------------------------------------------------------------------------3

    else if(escolhaDirecao == 3 && col + palavras[contColocadas].tamnho <= tamCol && lim - palavras[contColocadas].tamnho >= 0){
       
        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++, k++){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++, k++){
                tabuleiro[i][k].caractere = palavras[contColocadas].palavra[j];
                tabuleiro[i][k].fazPartePalavra = 1;
            }
            contColocadas++;
            contDirecao[3]++;
        }
        aprovado = 1;
    }

    // //-----------------------------------------------------------------------------------------------------4

    else if(escolhaDirecao == 4 && lim - palavras[contColocadas].tamnho >= 0){
        for (int i = lim, j = 0; j < palavras[contColocadas].tamnho; i--, j++){
            if(tabuleiro[i][col].fazPartePalavra == 1 && tabuleiro[i][col].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, j = 0; j < palavras[contColocadas].tamnho; i--, j++){
                tabuleiro[i][col].caractere = palavras[contColocadas].palavra[j];
                tabuleiro[i][col].fazPartePalavra = 1;
            }
            contColocadas++;
            contDirecao[4] = contDirecao[4] + 1;
        }
        aprovado = 1;
    }

    // //-----------------------------------------------------------------------------------------------------5

    else if(escolhaDirecao == 5 && col - palavras[contColocadas].tamnho >= 0){
        for (int i = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++){
            if(tabuleiro[i][lim].fazPartePalavra == 1 && tabuleiro[i][lim].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++){
                tabuleiro[i][lim].caractere = palavras[contColocadas].palavra[j];
                tabuleiro[i][lim].fazPartePalavra = 1;
            }
            contColocadas++;
            contDirecao[5] = contDirecao[5] + 1;
        }
        aprovado = 1;
    }

    // //-----------------------------------------------------------------------------------------------------6

    else if(escolhaDirecao == 6 && lim - palavras[contColocadas].tamnho >= 0 && col - palavras[contColocadas].tamnho >= 0){
        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++, k--){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++, k--){
                tabuleiro[i][k].caractere = palavras[contColocadas].palavra[j];
                tabuleiro[i][k].fazPartePalavra = 1;
            }
            contColocadas++;
            contDirecao[6] = contDirecao[6] + 1;
        }
        aprovado = 1;
    }

    // //-----------------------------------------------------------------------------------------------------7

    else if(escolhaDirecao == 7 && lim + palavras[contColocadas].tamnho <= tamLin && col - palavras[contColocadas].tamnho >= 0){
        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++, k--){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++, k--){
                tabuleiro[i][k].caractere = palavras[contColocadas].palavra[j];
                tabuleiro[i][k].fazPartePalavra = 1;
            }
            contColocadas++;
            contDirecao[7] = contDirecao[7] + 1;
        }
        aprovado = 1;
    }

}