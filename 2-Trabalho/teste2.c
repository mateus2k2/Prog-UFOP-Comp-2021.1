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

    if(col + palavras[contColocadas].tamnho <= tamCol){

        for (int i = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++){
            if(tabuleiro[lim][i].fazPartePalavra == 1 && tabuleiro[lim][i].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1 && palavras[contColocadas].marcado == 0){
            for (int i = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++){
                tabuleiro[lim][i].fazPartePalavra = 1;
                tabuleiro[lim][i].marcadoUsuario = 0;
            }
            contColocadas++;
        }
        if(aprovado == 1 && palavras[contColocadas].marcado == 1){
            for (int i = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++){
                tabuleiro[lim][i].fazPartePalavra = 1;
                tabuleiro[lim][i].marcadoUsuario = 1;
            }
            contColocadas++;
        }
        aprovado = 1;
    }

    else if(lim + palavras[contColocadas].tamnho <= tamLin){

        for (int i = lim, j = 0; j < palavras[contColocadas].tamnho; i++, j++){
            if(tabuleiro[i][col].fazPartePalavra == 1 && tabuleiro[i][col].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1 && palavras[contColocadas].marcado == 0){
            
            for (int i = lim, j = 0; j < palavras[contColocadas].tamnho; i++, j++){
                tabuleiro[i][col].fazPartePalavra = 1;
                tabuleiro[i][col].marcadoUsuario = 0;
            }
            contColocadas++;
        }
        if(aprovado == 1 && palavras[contColocadas].marcado == 1){
            
            for (int i = lim, j = 0; j < palavras[contColocadas].tamnho; i++, j++){
                tabuleiro[i][col].fazPartePalavra = 1;
                tabuleiro[i][col].marcadoUsuario = 1;
            }
            contColocadas++;
        }

        aprovado = 1;
    }

    else if(lim + palavras[contColocadas].tamnho <= tamLin && col + palavras[contColocadas].tamnho <= tamCol){
        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++, k++){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1 && palavras[contColocadas].marcado == 0){
            
            for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++, k++){
                tabuleiro[i][k].fazPartePalavra = 1;
                tabuleiro[i][k].marcadoUsuario = 0;
            }
            contColocadas++;
        }
        if(aprovado == 1 && palavras[contColocadas].marcado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++, k++){
                tabuleiro[i][k].fazPartePalavra = 1;
                tabuleiro[i][k].marcadoUsuario = 1;
            }
            contColocadas++;
        }
        aprovado = 1;
    }

    else if(col + palavras[contColocadas].tamnho <= tamCol && lim - palavras[contColocadas].tamnho >= 0){
       
        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++, k++){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1 && palavras[contColocadas].marcado == 0){
            
            for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++, k++){
                tabuleiro[i][k].fazPartePalavra = 1;
                tabuleiro[i][k].marcadoUsuario = 0;
            }
            contColocadas++; 
        }
        if(aprovado == 1 && palavras[contColocadas].marcado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++, k++){
                tabuleiro[i][k].fazPartePalavra = 1;
                tabuleiro[i][k].marcadoUsuario = 1;
            }
            contColocadas++; 
        }
        aprovado = 1;
    }

    else if(lim - palavras[contColocadas].tamnho >= 0){
        for (int i = lim, j = 0; j < palavras[contColocadas].tamnho; i--, j++){
            if(tabuleiro[i][col].fazPartePalavra == 1 && tabuleiro[i][col].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1 && palavras[contColocadas].marcado == 0){
            
            for (int i = lim, j = 0; j < palavras[contColocadas].tamnho; i--, j++){
                tabuleiro[i][col].fazPartePalavra = 1;
                tabuleiro[i][col].marcadoUsuario = 0;
            }
            contColocadas++;
        }
        if(aprovado == 1 && palavras[contColocadas].marcado == 1){
            
            for (int i = lim, j = 0; j < palavras[contColocadas].tamnho; i--, j++){
                tabuleiro[i][col].fazPartePalavra = 1;
                tabuleiro[i][col].marcadoUsuario = 1;
            }
            contColocadas++;
        }
        aprovado = 1;
    }

    else if(col - palavras[contColocadas].tamnho >= 0){
        for (int i = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++){
            if(tabuleiro[i][lim].fazPartePalavra == 1 && tabuleiro[i][lim].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1 && palavras[contColocadas].marcado == 0){
            
            for (int i = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++){
                tabuleiro[i][lim].fazPartePalavra = 1;
                tabuleiro[i][lim].marcadoUsuario = 0;
            }
            contColocadas++;
        }
        if(aprovado == 1 && palavras[contColocadas].marcado == 1){
            
            for (int i = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++){
                tabuleiro[i][lim].fazPartePalavra = 1;
                tabuleiro[i][lim].marcadoUsuario = 1;
            }
            contColocadas++;
        }
        aprovado = 1;
    }

    else if(lim - palavras[contColocadas].tamnho >= 0 && col - palavras[contColocadas].tamnho >= 0){
        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++, k--){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1 && palavras[contColocadas].marcado == 0){
            
            for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++, k--){
                tabuleiro[i][k].fazPartePalavra = 1;
                tabuleiro[i][k].marcadoUsuario = 0;
            }
            contColocadas++;
        }
        if(aprovado == 1 && palavras[contColocadas].marcado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i--, j++, k--){
                tabuleiro[i][k].fazPartePalavra = 1;
                tabuleiro[i][k].marcadoUsuario = 1;
            }
            contColocadas++;
        }
        aprovado = 1;
    }

    else if(lim + palavras[contColocadas].tamnho <= tamLin && col - palavras[contColocadas].tamnho >= 0){
        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++, k--){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].fazPartePalavra != palavras[contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1 && palavras[contColocadas].marcado == 0){
            
            for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++, k--){
                tabuleiro[i][k].fazPartePalavra = 1;
                tabuleiro[i][k].marcadoUsuario = 0;
            }
            contColocadas++;
        }

        if(aprovado == 1 && palavras[contColocadas].marcado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamnho; i++, j++, k--){
                tabuleiro[i][k].fazPartePalavra = 1;
                tabuleiro[i][k].marcadoUsuario = 1;
            }
            contColocadas++;
        }
        aprovado = 1;
    }

}