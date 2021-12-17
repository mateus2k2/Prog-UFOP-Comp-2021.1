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
}Item;

typedef struct{
    int numeroComando;
    int limC, colC;
    int limF, colF;
}Comando;

int colocaPalavra(int escolhaDirecao, int *contColocadas, int lim, int col, int tamLin, int tamCol, Palavra *palavras, Item **tabuleiro, int *contDirecao){
    
    int aprovado = 1, quantidade, *encontradas, suceso = 1;  
    Comando comando;
    

    //-----------------------------------------------------------------------------------------------------0 
    if(escolhaDirecao == 0){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.colC, j = 0; j < palavras[(t)].tamnho; i++, j++){
                if(tabuleiro[comando.limC][i].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado != 0){
                    palavras[t].marcado == 1;
                    *encontradas++;
                    return 1;
                }
                
                if(i == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    //-----------------------------------------------------------------------------------------------------1

    else if(escolhaDirecao == 1){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, j = 0; j < palavras[t].tamnho; i++, j++){
                if(tabuleiro[comando.colC][i].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado != 0){
                    palavras[t].marcado == 1;
                    *encontradas++;
                    return 1;
                }
                
                if(i == comando.limF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    //-----------------------------------------------------------------------------------------------------2

   else if(escolhaDirecao == 2){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.colC, j = 0; j < palavras[t].tamnho; i++, j++, k++){
                if(tabuleiro[i][k].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado != 0){
                    palavras[t].marcado == 1;
                    *encontradas++;
                    return 1;
                }
                
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    //-----------------------------------------------------------------------------------------------------3

    else if(escolhaDirecao == 3){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.colC, j = 0; j < palavras[t].tamnho; i--, j++, k++){
                if(tabuleiro[i][k].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado != 0){
                    palavras[t].marcado == 1;
                    *encontradas++;
                    return 1;
                }
                
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    // //-----------------------------------------------------------------------------------------------------4

    else if(escolhaDirecao == 4){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, j = 0; j < palavras[t].tamnho; i--, j++){
                if(tabuleiro[i][comando.colC].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado != 0){
                    palavras[t].marcado == 1;
                    *encontradas++;
                    return 1;
                }
                
                if(i == comando.limF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    // //-----------------------------------------------------------------------------------------------------5

    else if(escolhaDirecao == 5){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.colC, j = 0; j < palavras[t].tamnho; i--, j++){
                if(tabuleiro[i][comando.limC].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado != 0){
                    palavras[t].marcado == 1;
                    *encontradas++;
                    return 1;
                }
                
                if(i == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    // //-----------------------------------------------------------------------------------------------------6

    else if(escolhaDirecao == 6){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.colC, j = 0; j < palavras[t].tamnho; i--, j++, k--){
                if(tabuleiro[i][k].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado != 0){
                    palavras[t].marcado == 1;
                    *encontradas++;
                    return 1;
                }
                
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

    // //-----------------------------------------------------------------------------------------------------7

    else if(escolhaDirecao == 7){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.limC, j = 0; j < palavras[(*contColocadas)].tamnho; i++, j++, k--){
                if(tabuleiro[i][k].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado != 0){
                    palavras[t].marcado == 1;
                    *encontradas++;
                    return 1;
                }
                
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        return 0;
    }

}