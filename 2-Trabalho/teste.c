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
    int limC, colC;
    int limF, colF;
}Comando;

int verificaEscolha(Comando comando, Palavra *palavras, Item **tabuleiro, int *encontradas, int quantidade, int tamCol, int tamLin){
    int direcao;

    //Verificar direcao 
    if(comando.colC != comando.colF && comando.limC == comando.limF && comando.colC < comando.colF)
        direcao = 0;
    else if(comando.colC == comando.colF && comando.limC != comando.limF && comando.limC < comando.limF)
        direcao = 1;
    else if(comando.colC < comando.colF && comando.limC < comando.limF)
        direcao = 2;
    else if(comando.colC > comando.colF && comando.limC < comando.limF)
        direcao = 3;
    else if(comando.colC == comando.colF && comando.limC != comando.limF && comando.limC > comando.limF)
        direcao = 4;
    else if(comando.colC != comando.colF && comando.limC == comando.limF && comando.colC > comando.colF)
        direcao = 5;
    else if(comando.colC > comando.colF && comando.limC > comando.limF)
        direcao = 6;
    else if(comando.colC > comando.colF && comando.limC < comando.limF)
        direcao = 7;

    if(direcao == 0){
            for (int t = 0; t < quantidade; t++){
                for (int i = comando.colC, j = 0; j < palavras[(t)].tamnho; i++, j++){
                    if(tabuleiro[comando.limC][i].caractere != palavras[(t)].palavra[j]){
                        break;
                    }                     
        
                    if(i == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 0){
                        palavras[t].marcado = 1;
                        (*encontradas)++;

                        palavras[t].limC = comando.limC;
                        palavras[t].colC = comando.colC;
                        palavras[t].limF = comando.limF;
                        palavras[t].colF = comando.colF;

                        for (int u = comando.colC, p = 0; p < palavras[(t)].tamnho; u++, p++)                            
                            tabuleiro[comando.limC][u].marcadoUsuario = 1;

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

    else if(direcao == 1){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, j = 0; j < palavras[t].tamnho; i++, j++){
                if(tabuleiro[i][comando.colC].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 0){
                        palavras[t].marcado = 1;
                        (*encontradas)++;

                        palavras[t].limC = comando.limC;
                        palavras[t].colC = comando.colC;
                        palavras[t].limF = comando.limF;
                        palavras[t].colF = comando.colF;

                        for (int u = comando.limC, p = 0; p < palavras[(t)].tamnho; u++, p++)                            
                            tabuleiro[u][comando.colC].marcadoUsuario = 1;

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

   else if(direcao == 2){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.colC, j = 0; j < palavras[t].tamnho; i++, j++, k++){
                if(tabuleiro[i][k].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 0){
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    for (int u = comando.limC, q = comando.colC, p = 0; p < palavras[t].tamnho; u++, p++, q++)                            
                        tabuleiro[u][q].marcadoUsuario = 1;

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

    else if(direcao == 3){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.colC, j = 0; j < palavras[t].tamnho; i--, j++, k++){
                if(tabuleiro[i][k].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 0){
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    for (int u = comando.limC, q = comando.colC, p = 0; p < palavras[t].tamnho; u--, p++, q++)                            
                        tabuleiro[u][q].marcadoUsuario = 1;

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

    else if(direcao == 4){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, j = 0; j < palavras[t].tamnho; i--, j++){
                if(tabuleiro[i][comando.colC].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 0){
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    for (int u = comando.limC, p = 0; p < palavras[t].tamnho; u--, p++)                            
                        tabuleiro[u][comando.colC].marcadoUsuario = 1;

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

    else if(direcao == 5){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.colC, j = 0; j < palavras[t].tamnho; i--, j++){
                if(tabuleiro[i][comando.limC].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 0){
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    for (int u = comando.colC, p = 0; p < palavras[t].tamnho; u--, p++)                            
                        tabuleiro[u][comando.limC].marcadoUsuario = 1;

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

    else if(direcao == 6){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.colC, j = 0; j < palavras[t].tamnho; i--, j++, k--){
                if(tabuleiro[i][k].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 0){
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    for (int u = comando.limC, q = comando.colC, p = 0; p < palavras[t].tamnho; u--, p++, q--)                            
                        tabuleiro[u][q].marcadoUsuario = 1;

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

    else if(direcao == 7){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.limC, j = 0; j < palavras[t].tamnho; i++, j++, k--){
                if(tabuleiro[i][k].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     
    
                if(i == comando.limF && k == comando.colF && j == palavras[(t)].tamnho - 1 && palavras[t].marcado == 0){
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    for (int u = comando.limC, q = comando.limC, p = 0; p < palavras[t].tamnho; u++, p++, q--)                            
                        tabuleiro[u][q].caractere = 1;

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