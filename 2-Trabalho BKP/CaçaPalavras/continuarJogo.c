//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/structs.h"
#include "Headers/menus.h"
#include "Headers/continuarJogo.h"
#include "Headers/jogar.h"
#include "Headers/outros.h"


void salvaJogo(int quantidade, int tamLin, int tamCol, Item **tabuleiro, Palavra *palavras, char nomeArquivoSave[]){

    //----------------------------------------------------------------------

    //Abrir arquivo para escrever o save
    FILE *save = fopen(nomeArquivoSave, "w");

    printf("\nAbrindo \"%s\"...\n", nomeArquivoSave);
    if(save == NULL){
        printf("Erro ao abrir Arquivo.");
        return;
    }

    //FILE *save = fopen("Files/save.txt", "r");

    //----------------------------------------------------------------------

    //Escrevendo o tabuleiro no arquivo de save  
    fprintf(save, "%i %i\n", tamLin, tamCol);

    for (int i = 0; i < tamLin; i++){
        for (int j = 0; j < tamCol; j++){
            fprintf(save, "%c ", tabuleiro[i][j].caractere);
        }
        fprintf(save, "\n");        
    }    

    //----------------------------------------------------------------------

    //Escrevendo as palavras no arquivo de save 
    fprintf(save, "%i\n", quantidade);

    for (int i = 0; i < quantidade; i++){
        //Caso a mapalava tenha sido encontrada coloca a coodenadas (convertida de números para letras)
        if(palavras[i].marcado == 1)
            fprintf(save, "%s %c%c %c%c\n", palavras[i].palavra, palavras[i].limC + 'A', palavras[i].colC + 'A', palavras[i].limF + 'A', palavras[i].colF + 'A');
        //Se nao for marcada coloca apenas -- --
        else
            fprintf(save, "%s -- --\n", palavras[i].palavra);
    }

    //----------------------------------------------------------------------

    //Fechando o arquivo
    fclose(save);
}

void continuaJogo(){

    Item **tabuleiro;
    Palavra *palavras;

    //Uma variavel char temporatia para ler os caracteres do tabuleiro
    char tmp;

    //Tamanho do tabuleiro e quantidade de palavras
    int tamLin, tamCol, quantidade;

    //------------------------------------------------------------------------

    //ler nome do arquivo
    char *nomeArquivo;
    nomeArquivo = malloc(100 * sizeof(char));

    if(nomeArquivo == NULL){
        printf("Erro");
        return;
    }

    FILE *save;  
   
    leNomeArquivo(&nomeArquivo);
    if(strcmp(nomeArquivo, "SAIR") == 0)
        return;
    save = fopen(nomeArquivo, "r");
    free(nomeArquivo);

    //FILE *save = fopen("Files/save.txt", "r");

    //------------------------------------------------------------------------

    //Ler as dimensões do tabuleiro e aloca dinamicamente o tabuleiro
    fscanf(save, "%i %i", &tamLin, &tamCol);
    tabuleiro = (Item**)malloc(tamLin*sizeof(Item*));
    for(int i = 0; i < tamLin; i++)
        (tabuleiro)[i] = (Item*)malloc(tamCol*sizeof(Item));

    //Caso o malloc falhe ele retornará NULL caso isso acontece o programa se encerra 
    if(tabuleiro == NULL){
        printf("\nErro.");
        return;
    }

    //Lendo cada caractere do arquivo  
    for (int i = 0; i < tamLin; i++){
        for (int j = 0; j < tamCol; j++){
            fscanf(save, "%c", &tmp);
            //Se o caractere lido do arquivo for diferente de um espaço ou uma quebra de linha adciona ele no tabuleiro
            if(tmp != ' ' && tmp != '\n'){
                //Se estiver minúscula converte para maiúscula
                if(tmp >= 'a' && tmp <= 'z')
                    tmp = tmp - 32;

                tabuleiro[i][j].caractere = tmp;
            }
            //Se não reduz o contador da coluna 
            else
                j--;
        }
    }  


    //---------------------------------------------------------------------------------------------

    //Le e aloca o vetor de palavras (do tipo Palavra)
    fscanf(save, "%i", &quantidade);
    palavras = malloc(quantidade * sizeof(Palavra));

    //Caso o malloc falhe ele retornará NULL caso isso acontece o programa se encerra 
    if(palavras == NULL){
        printf("\nErro.");
        return;
    }

    //---------------------------------------------------------------------------------------------

    //Faz um fscanf para ler o '\n' na linha da quantidade de palavras 
    fscanf(save, "%c", &tmp);

    //Le de 0 até a quantidade de palavras
    for (int i = 0; i < quantidade; i++){

        //Le de 0 ate o tamanho máximo para um palavra (100 caracteres)
        for (int j = 0; j < 100; j++){
            fscanf(save, "%c", &tmp);   
            //Se o caractere lido do arquivo for diferente de um espaço ou uma quebra de linha adciona ele na palavra
            if(tmp != ' ' && tmp != '\n'){
                //Se estiver minúscula converte para maiúscula
                if(tmp >= 'a' && tmp <= 'z')
                    tmp = tmp - 32;

                palavras[i].palavra[j] = tmp;
            }
            //Se foi lido um espaço então significa que a palavra acabou então sai desse loop
            if(tmp == ' ')
                break;
        }
        
        //Faz mais uma leitura do arquivo (deposi do espaço do fim da palavra)
        fscanf(save, "%c", &tmp);
        //Se estiver minúscula converte para maiúscula
        if(tmp >= 'a' && tmp <= 'z')
                tmp = tmp - 32;

        //Caso seja uma letra significa que ele foi encontrado e existe uma coordenada a ser lida
        if(tmp >= 'A' && tmp <= 'Z'){
            //Adicioana a coodenada da linha inicial 
            palavras[i].limC = tmp - 'A';

            //Le e Adicioana a coodenada da Coluna Inicial 
            fscanf(save, "%c", &tmp);
            //Se estiver minúscula converte para maiúscula
            if(tmp >= 'a' && tmp <= 'z')
                tmp = tmp - 32;
            palavras[i].colC = tmp - 'A';

            //Le o espaço 
            fscanf(save, "%c", &tmp);

            //Le e Adicioana a coodenada da Linha Final 
            fscanf(save, "%c", &tmp);  
            //Se estiver minúscula converte para maiúscula
            if(tmp >= 'a' && tmp <= 'z')
                tmp = tmp - 32;          
            palavras[i].limF = tmp - 'A';

            //Le e Adicioana a coodenada da Coluna Final
            fscanf(save, "%c", &tmp);
            //Se estiver minúscula converte para maiúscula
            if(tmp >= 'a' && tmp <= 'z')
                tmp = tmp - 32;
            palavras[i].colF = tmp - 'A';
            
            //Marca a palavra
            fscanf(save, "%c", &tmp);
            //Se estiver minúscula converte para maiúscula
            if(tmp >= 'a' && tmp <= 'z')
                tmp = tmp - 32;
            palavras[i].marcado = 1;
        }
        else{
            //Le os caracteres
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);

            //Não marca a palavra
            palavras[i].marcado = 0;
        }    

        //Adiciona o tamanho da palavra
        palavras[i].tamanho = strlen(palavras[i].palavra);    

    }  
    //Fecha o arquivo
    fclose(save);
    
    //Resolve o tabuleiro (encontra as palavras)
    //Se retornar 1 nem todas as palavras form encontras e o programa se encerra 
    if(resolveTabuleiroSaveGame(quantidade, tamLin, tamCol, tabuleiro, palavras) == 1){
        printf("\nArquivo de save corrompido. \nNão foram encontradas todas as palavras. \nTente novamente com outro arquivo ou concerte o arquivo atual\n");
        return;
    }
    
    //Se todas as palavras foram encontradas 
    else
        //Chama a função jogar
        jogar(palavras, tabuleiro, tamLin, tamCol, quantidade);
}

int resolveTabuleiroSaveGame(int quantidade, int tamLin, int tamCol, Item **tabuleiro, Palavra *palavras){
    
    int aprovado = 1, teste = 0;
    int encontradas = 0;
    

    //Inicializa o elemento fazPartePalava da struct tabuleiro com 0
    for (int i = 0; i < tamLin; i++)
        for (int j = 0; j < tamCol; j++)
            tabuleiro[i][j].fazPartePalavra = 0;

    //Vai de 0 ate quantidade
    for (int contEncontradas = 0; contEncontradas < quantidade; contEncontradas++){
        
        //Percore toda a matriz
        for (int lim = 0; lim < tamLin; lim++){
            for (int col = 0; col < tamCol; col++){

                //----------------------------------------------------------------------------------------------------------------- 0

                //Para cara direção é verificado se a palavra atual caberia começando da linha (lin) e coluna (col) atual
                if(col + palavras[contEncontradas].tamanho <= tamCol){
                    //Se colber a matriz e percorrida na direção especificada. 
                    //Nesse caso é horizontal, esquerda para a direita. Fixa a linha atual e aumenta a coluna
                    for (int i = col, j = 0; j < palavras[contEncontradas].tamanho; i++, j++){
                        //Se algum elementa do tabuleiro for diferente da palavra sai do loop e aprovado recebe 0
                        if(tabuleiro[lim][i].caractere != palavras[contEncontradas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }
                    //Como aprovado é inicializado com 1. Se não entrar no if anterior (ou seja) se os elementos forem todos iguais a palavra foi encontradas.
                    //Caso a componente 'marcado' (que indica se o usuário encontrou ou nao a palavra)  seja 0 entra nesse if 
                    if(aprovado == 1 && palavras[contEncontradas].marcado == 0){
                        //Percorre o tabuleiro da mesma forma de antes. Agora inicializando 'FazPartePalavra' com 1 e 'marcadaUsuário' com 0
                        for (int i = col, j = 0; j < palavras[contEncontradas].tamanho; i++, j++){
                            tabuleiro[lim][i].fazPartePalavra = 1;
                            tabuleiro[lim][i].marcadoUsuario = 0;
                        }
                        //Depois inicializa teste com 1 (para sair do desse for e do proximo. Fazendo com que comece a procurar a proxima palavra do começo do tabuleiro)
                        teste = 1;
                        //Cont das encontradar para verificar se realmente encontrou todas as palavras
                        encontradas++;
                        //Sai do loop
                        break;
                    }
                    //Faz a mesma coisa so if anterior mas inicializando 'marcadoUsuario' com 1
                    if(aprovado == 1 && palavras[contEncontradas].marcado == 1){
                        for (int i = col, j = 0; j < palavras[contEncontradas].tamanho; i++, j++){
                            tabuleiro[lim][i].fazPartePalavra = 1;
                            tabuleiro[lim][i].marcadoUsuario = 1;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    //Reset aprovado para 1
                    aprovado = 1;

                }

                //Todos o resto é a mesma coisa, mudando apenasa forma como se percorre o tabuleiro para verificar todas as direções
                //----------------------------------------------------------------------------------------------------------------- 1

                if(lim + palavras[contEncontradas].tamanho <= tamLin){

                    for (int i = lim, j = 0; j < palavras[contEncontradas].tamanho; i++, j++){
                        if(tabuleiro[i][col].caractere != palavras[contEncontradas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contEncontradas].marcado == 0){                        
                        for (int i = lim, j = 0; j < palavras[contEncontradas].tamanho; i++, j++){
                            tabuleiro[i][col].fazPartePalavra = 1;
                            tabuleiro[i][col].marcadoUsuario = 0;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    if(aprovado == 1 && palavras[contEncontradas].marcado == 1){
                        
                        for (int i = lim, j = 0; j < palavras[contEncontradas].tamanho; i++, j++){
                            tabuleiro[i][col].fazPartePalavra = 1;
                            tabuleiro[i][col].marcadoUsuario = 1;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    aprovado = 1;
                }

                //----------------------------------------------------------------------------------------------------------------- 2

                if(lim + palavras[contEncontradas].tamanho <= tamLin && col + palavras[contEncontradas].tamanho <= tamCol){
                    for (int i = lim, k = col, j = 0; j < palavras[contEncontradas].tamanho; i++, j++, k++){
                        if(tabuleiro[i][k].caractere != palavras[contEncontradas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contEncontradas].marcado == 0){                        
                        for (int i = lim, k = col, j = 0; j < palavras[contEncontradas].tamanho; i++, j++, k++){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 0;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    if(aprovado == 1 && palavras[contEncontradas].marcado == 1){                        
                        for (int i = lim, k = col, j = 0; j < palavras[contEncontradas].tamanho; i++, j++, k++){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 1;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    aprovado = 1;
                }

                //----------------------------------------------------------------------------------------------------------------- 3

                if(col + palavras[contEncontradas].tamanho <= tamCol && lim - palavras[contEncontradas].tamanho >= 0){
                
                    for (int i = lim, k = col, j = 0; j < palavras[contEncontradas].tamanho; i--, j++, k++){
                        if(tabuleiro[i][k].caractere != palavras[contEncontradas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contEncontradas].marcado == 0){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contEncontradas].tamanho; i--, j++, k++){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 0;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    if(aprovado == 1 && palavras[contEncontradas].marcado == 1){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contEncontradas].tamanho; i--, j++, k++){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 1;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    aprovado = 1;
                }
    
                //----------------------------------------------------------------------------------------------------------------- 4

                if(lim - palavras[contEncontradas].tamanho >= 0){
                    for (int i = lim, j = 0; j < palavras[contEncontradas].tamanho; i--, j++){
                        if(tabuleiro[i][col].caractere != palavras[contEncontradas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contEncontradas].marcado == 0){
                        
                        for (int i = lim, j = 0; j < palavras[contEncontradas].tamanho; i--, j++){
                            tabuleiro[i][col].fazPartePalavra = 1;
                            tabuleiro[i][col].marcadoUsuario = 0;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    if(aprovado == 1 && palavras[contEncontradas].marcado == 1){
                        
                        for (int i = lim, j = 0; j < palavras[contEncontradas].tamanho; i--, j++){
                            tabuleiro[i][col].fazPartePalavra = 1;
                            tabuleiro[i][col].marcadoUsuario = 1;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    aprovado = 1;
                }

                //----------------------------------------------------------------------------------------------------------------- 5

                if(col - palavras[contEncontradas].tamanho >= 0){
                    for (int i = col, j = 0; j < palavras[contEncontradas].tamanho; i--, j++){
                        if(tabuleiro[lim][i].caractere != palavras[contEncontradas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contEncontradas].marcado == 0){
                        
                        for (int i = col, j = 0; j < palavras[contEncontradas].tamanho; i--, j++){
                            tabuleiro[lim][i].fazPartePalavra = 1;
                            tabuleiro[lim][i].marcadoUsuario = 0;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    if(aprovado == 1 && palavras[contEncontradas].marcado == 1){
                        
                        for (int i = col, j = 0; j < palavras[contEncontradas].tamanho; i--, j++){
                            tabuleiro[lim][i].fazPartePalavra = 1;
                            tabuleiro[lim][i].marcadoUsuario = 1;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    aprovado = 1;
                }

                //----------------------------------------------------------------------------------------------------------------- 6

                if(lim - palavras[contEncontradas].tamanho >= 0 && col - palavras[contEncontradas].tamanho >= 0){
                    for (int i = lim, k = col, j = 0; j < palavras[contEncontradas].tamanho; i--, j++, k--){
                        if(tabuleiro[i][k].caractere != palavras[contEncontradas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contEncontradas].marcado == 0){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contEncontradas].tamanho; i--, j++, k--){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 0;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    if(aprovado == 1 && palavras[contEncontradas].marcado == 1){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contEncontradas].tamanho; i--, j++, k--){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 1;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }
                    aprovado = 1;
                }
                
                //----------------------------------------------------------------------------------------------------------------- 7

                if(lim + palavras[contEncontradas].tamanho <= tamLin && col - palavras[contEncontradas].tamanho >= 0){
                    

                    for (int i = lim, k = col, j = 0; j < palavras[contEncontradas].tamanho; i++, j++, k--){
                        if(tabuleiro[i][k].caractere != palavras[contEncontradas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contEncontradas].marcado == 0){
                        for (int i = lim, k = col, j = 0; j < palavras[contEncontradas].tamanho; i++, j++, k--){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 0;
                        }
                        teste = 1;
                        encontradas++;
                        break;
                    }

                    if(aprovado == 1 && palavras[contEncontradas].marcado == 1){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contEncontradas].tamanho; i++, j++, k--){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 1;
                        }
                        teste = 1;
                        encontradas++;
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
    
    //Se todas as palavras foram encontras return 0 caso contrario return 1
    if(encontradas != quantidade)
        return 1;

    else if(encontradas == quantidade)
        return 0;
}
