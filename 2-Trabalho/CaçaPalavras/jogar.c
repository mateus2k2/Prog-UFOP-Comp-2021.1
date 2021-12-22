//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    //Print o estado atual do tabuleiro como parametro 0 no final para mostrar apenas os ja marcados
    printResolvido(tamLin, tamCol, tabuleiro, 0);

    //---------------------------------------------------------------------------------------------
 
    //Caso esteja restaurando um jogo se soma as palavras ja marcadas
    for (int i = 0; i < quantidade; i++){
        if(palavras[i].marcado == 1)
            encontradas++;
    }

    //Caso por algum motivo se tenha restaurado o jogo e todas as palavras ja estiverem marcadas estão se encerra o jogo    
    if(encontradas == quantidade){
        sairJogo(tabuleiro, palavras, tamLin);
        printf("\nTodas as palavra encontradas!");
    }

    //---------------------------------------------------------------------------------------------

    //Enquanto nao se encontrar todas as palavras
    while (encontradas != quantidade){

        //Inicializa essas as variavais para entrar no loop de ler o comando
        comando.numeroComando = 0;
        comando.limC = tamLin+1; 
        comando.colC = tamCol+1;
        comando.limF = tamLin+1;
        comando.colF = tamCol+1;
        
        //---------------------------------------------------------------------------------------------
        
        //Enquanto nao forem digitados comando validos ou
        //As coordenadas digitadas estiverem fora do tabuleiro
        //Permanece do loop de leitura do comando
        while (comando.numeroComando == 0 || (comando.numeroComando == 1 && (comando.limC > tamLin-1 || comando.limF > tamLin-1 || comando.colC > tamCol-1 || comando.colF > tamCol-1))){
            printf("\nDigite o Comando: ");
            fgets(comandoCompleto, 100, stdin);
            //Remove '\n' do final
            comandoCompleto[strlen(comandoCompleto)-1] = '\0';

            //Interpreta comando
            comando = interpretaComando(comandoCompleto);    

            //Print erros
            if(comando.numeroComando == 0)
                printf("Comando Invalido!\n");

            if(comando.numeroComando == 1 && (comando.limC > tamLin-1 || comando.limF > tamLin-1 || comando.colC > tamCol-1 || comando.colF > tamCol-1))
                printf("Indice Invalido!\n");        
        }

        //---------------------------------------------------------------------------------------------

        //Marcar
        if(comando.numeroComando == 1){
            //Verifica a escolha das coordenadas
            retornoVerificacao = verificaEscolha(comando, palavras, tabuleiro, &encontradas, quantidade, tamCol, tamLin);

            //Print do retorno. Sucessor ou erro.
            if(retornoVerificacao == 0)
                printf("Palavra invalida\n");
            if(retornoVerificacao == 1)
                printf("Palavra marcada\n");
            if(retornoVerificacao == 2)
                printf("Palavra repetida ou ja marcada\n");
        }

        //Salvar
        else if(comando.numeroComando == 2){
            salvaJogo(quantidade, tamLin, tamCol, tabuleiro, palavras, comando.nomeArquivoSave);
        }

        //Resolver
        else if(comando.numeroComando == 3){
            //Print o tabuleiro resolvido chamando a função com parametro 1 no final para mostrar todas as  palavras
            printResolvido(tamLin, tamCol, tabuleiro, 1);
            sairJogo(tabuleiro, palavras, tamLin);
            printf("\nPena que nao conseguiu resolver, tchau!");
            return;
        } 
        
        //Sair
        else{
            sairJogo(tabuleiro, palavras, tamLin);
            return;
        }

        //---------------------------------------------------------------------------------------------

        printf("\n");    

        //Print o estado atual do tabuleiro como parametro 0 no final para mostrar apenas os ja marcados
        printResolvido(tamLin, tamCol, tabuleiro, 0);

        //Caso por algum motivo se tenha restaurado o jogo e todas as palavras ja estiverem marcadas estão se encerra o jogo    
        if(encontradas == quantidade){
            sairJogo(tabuleiro, palavras, tamLin);
            printf("\nTodas as palavra encontradas!");

        }
    }

    return;
}

int verificaEscolha(Comando comando, Palavra *palavras, Item **tabuleiro, int *encontradas, int quantidade, int tamCol, int tamLin){
    int direcao;

    //linC = Linha inicial
    //colC = Coluna inicial
    //linF = linha Final
    //colF = Coluna Final

    //Verificar direcao baseada na coordenada
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
    //Se tudo for igual então a coordenada é apenas 1 letras. Poderia ser qualquer direção
    else if(comando.colC == comando.colF && comando.limC == comando.limF)
        direcao = 0;
    
    //Verifica qual direção foi escolhida
    if(direcao == 0){
        //Passa por todas as palavras 
        for (int t = 0; t < quantidade; t++){
            //Percorre a matriz do tabuleiro na direção especificada.
            //Nesse caso é Horizontal, Esquerda para direita Fixa a linha atual e aumenta a coluna
            for (int i = comando.colC, j = 0; j < palavras[(t)].tamanho; i++, j++){
                //Se algum elementa do tabuleiro for diferente da palavra sai do loop
                if(tabuleiro[comando.limC][i].caractere != palavras[(t)].palavra[j]){
                    break;
                }                     

                //Se chegou no último caso do loop e o valor de i é igual a coordenada da coluna final e a palavra ainda não foi marcada
                //A palavra foi encontrada 
                if(i == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 0){
                    //Incrementa nas encontradas e marca palavra
                    palavras[t].marcado = 1;
                    (*encontradas)++;

                    //Armazena a coordenada da palavra
                    palavras[t].limC = comando.limC;
                    palavras[t].colC = comando.colC;
                    palavras[t].limF = comando.limF;
                    palavras[t].colF = comando.colF;

                    //Percorre a matriz na mesma forma de antes agora inicializando 'marcadoUsuario' com 1
                    for (int u = comando.colC, p = 0; p < palavras[(t)].tamanho; u++, p++){                         
                        tabuleiro[comando.limC][u].marcadoUsuario = 1;
                    }

                    //Return 1 (palavra encontrada)
                    return 1;
                }
                //Se chegou no último caso do loop e o valor de i é igual a coordenada da coluna final e a palavra ainda não foi marcada
                //E 'marcado' for 1 A palavra foi encontrada mas ela ja foi marcada então return 2 (palavra repetida) 
                if(i == comando.colF && j == palavras[(t)].tamanho - 1 && palavras[t].marcado == 1){
                    return 2;
                }
            }
        }
        //Return 0 (palavra invalida)
        return 0;
    }

    //Todos o resto é a mesma coisa, mudando apenasa forma como se percorre o tabuleiro para verificar todas as direções
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

    //Alguma variaveis de auxilio
    char marcar[] = "MARCAR\0";
    char salvar[] = "SALVAR\0";
    char nomeArquivoTmp[100];
    int indiceFim = 0;
    int tamanhoTmp;

    //Copia o comando digitado para outra string e transforma a original tudo em maiúscula
    for (int i = 0; i < strlen(comandoCompleto); i++){
        nomeArquivoTmp[i] = comandoCompleto[i];

        if(comandoCompleto[i] >= 'a' && comandoCompleto[i] <= 'z')
                comandoCompleto[i] = comandoCompleto[i] - 32;        
    }
    nomeArquivoTmp[strlen(comandoCompleto)] = '\0';

    //Verifica se 'marcar' esta contina na string e se o proximo caractere depois do 'R' é um ' '(espaço)
    if(strstr(comandoCompleto, "MARCAR") != NULL && comandoCompleto[6] == ' ') {
        //Confere se realmente "MARCAR" esta nos 6 primeiros caracteres da string de comando
        for (int i = 0; i < 6; i++){
            if(comandoCompleto[i] != marcar[i]){
                comando.numeroComando = 0;
                return comando;
            }
        }

        //Verifica se depois da palavra marcar existem 2 pares de letras separadas por um espaço
        if( (comandoCompleto[6] == ' ') && 
            (comandoCompleto[7] >= 'A' && comandoCompleto[7] <= 'Z') &&
            (comandoCompleto[8] >= 'A' && comandoCompleto[8] <= 'Z') &&
            (comandoCompleto[9] == ' ') &&
            (comandoCompleto[10] >= 'A' && comandoCompleto[10] <= 'Z') &&
            (comandoCompleto[11] >= 'A' && comandoCompleto[11] <= 'Z')){    
              
            //Converte as coordenadas de letras para números  
            comando.limC =  comandoCompleto[7] - 'A';
            comando.colC =  comandoCompleto[8] - 'A';
            comando.limF =  comandoCompleto[10] - 'A';
            comando.colF =  comandoCompleto[11] - 'A';
        }

        //Se cair nesse else então o comando e valido mas as coordenadas são invalidas
        else{
            comando.numeroComando = 0;
            return comando;
        } 
        
        //comando.numeroComando = 1 (Marcar) e retorna o comando 
        comando.numeroComando = 1;
        return comando;        
    }

    //Salvar
    //Verifica se 'salvar' esta contina na string e se o proximo caractere depois do 'R' é um ' '(espaço)
    else if(strstr(comandoCompleto, "SALVAR") != NULL){
        //Confere se realmente "SALVAR" esta nos 6 primeiros caracteres da string de comando
        for (int i = 0; i < 6; i++){
            if(comandoCompleto[i] != salvar[i]){
                comando.numeroComando = 0;
                return comando;
            }
        }
        if(comandoCompleto[6] == ' '){
            //Percorre todo o comando
            for (int i = 0; i < strlen(comandoCompleto); i++){  
                //Encontra se tem '.txt' no fim da string
                //Coso tenha quarda o valor do fim e sai do loop 
                if(comandoCompleto[i] == '.' && comandoCompleto[i+1] == 'T' && comandoCompleto[i+2] == 'X' && comandoCompleto[i+3] == 'T'){
                    indiceFim = i;
                    break;
                }

                //Caso tenha algum caractere proibido para nome de arquivo retorna comando invalido
                if((comandoCompleto[i] == '<') || (comandoCompleto[i] == '>') || (comandoCompleto[i] == ':') || (comandoCompleto[i] == '"') || (comandoCompleto[i] == '|') || (comandoCompleto[i] == '?') || (comandoCompleto[i] == '*')){
                    comando.numeroComando = 0;
                    return comando;
                }
                
            }

            //Se o indiceFim for diferente de 0 então a string ja tem o '.txt' no final
            //Basta copiar a string para comando.nomeArquivoSave e colocar '\0' no final
            if(indiceFim != 0)
                for (int i = 7, j = 0; j < indiceFim - 7; i++, j++){
                    comando.nomeArquivoSave[j] = nomeArquivoTmp[i];
                    if(j == (indiceFim - 7)-1)
                        comando.nomeArquivoSave[j+1] = '\0';
                }
            //Se o indiceFim for 0 então a string não tem o '.txt' no final
            else{
                //Copia a string para comando.nomeArquivoSave e colocar '\0' no final
                for (int i = 7, j = 0; j < strlen(comandoCompleto) - 7; i++, j++){
                    comando.nomeArquivoSave[j] = nomeArquivoTmp[i];
                    if(j == (strlen(comandoCompleto) - 7)-1)
                        comando.nomeArquivoSave[j+1] = '\0';

                }                
            }
            //Adciona o '.txt' ao final da string
            tamanhoTmp = strlen(comando.nomeArquivoSave);
            comando.nomeArquivoSave[tamanhoTmp+0] = '.';
            comando.nomeArquivoSave[tamanhoTmp+1] = 't';
            comando.nomeArquivoSave[tamanhoTmp+2] = 'x';
            comando.nomeArquivoSave[tamanhoTmp+3] = 't';
            comando.nomeArquivoSave[tamanhoTmp+4] = '\0';

            //Retorna comando como 2 (salvar)
            comando.numeroComando = 2;
            return comando;           
        }

        //Se algo deu errado retorna comando como 0 (inválido)
        else{
            comando.numeroComando = 0;
            return comando;
        }

    }

    //Resolver
    //Verifica se a string comando é igual a "RESOLVER" se sim  então o comando é 3
    else if(strcmp(comandoCompleto, "RESOLVER") == 0){
        comando.numeroComando = 3;
        return comando;
    }

    //SAIR
    //Verifica se a string comando é igual a "SAIR" se sim  então o comando é 4
    else if(strcmp(comandoCompleto, "SAIR") == 0) {
        comando.numeroComando = 4;
        return comando;
    }

    //Comando como 0 (invalido)
    else{
        comando.numeroComando = 0;
        return comando;
    }

}   
