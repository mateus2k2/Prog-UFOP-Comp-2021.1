//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/structs.h"
#include "Headers/menus.h"
#include "Headers/outros.h"
#include "Headers/jogar.h"
#include "Headers/criaTabuleiro.h"


void criarJogo(){
    Item **tabuleiro;
    Palavra *palavras;

    //Armazenam alguns valores Temporarios
    char tmp[100];
    int tmpTamanho;

    //Controle da criação do tabuleiro
    int contDirecao[8] = {0};
    int modoSemRegulacaoDirecao = 0;
    int tabuleiroPronto = 0;

    //Relacionadas coom a criação do tabuleiro
    int tamLin, tamCol;
    int quantidade, dificuldade;
    int escolhaDirecao = 0, escolhaColocar, escolhaLetra, contColocadas = 0;

    //Outras
    int totalLetrasPalavras = 0, TotalTamanhoTabuleiro = 0;
    double razao;
    double tentativas = 0;

    //--------------------------------------------------------------------------------
    //Criação do arquivo

    char *nomeArquivo;
    nomeArquivo = malloc(100 * sizeof(char));

    if(nomeArquivo == NULL){
        printf("Erro");
        return;
    }

    FILE *dicionario;  
   
    leNomeArquivo(&nomeArquivo);
    if(strcmp(nomeArquivo, "SAIR") == 0)
        return;
    dicionario = fopen(nomeArquivo, "r");
    free(nomeArquivo);

    // FILE *dicionario = fopen("Files/dicionario.txt", "r");

    //--------------------------------------------------------------------------------

    //Lendo dimensões do tabuleiro
    fscanf(dicionario, "%i %i", &tamLin, &tamCol);
    TotalTamanhoTabuleiro = tamLin * tamCol;

    //Como o sistema de coordenadas e baseado em Letras o tabuleiro nao pode ser maior que 26
    if(tamLin > 26 || tamCol > 26){
        printf("\nTabuleiro nao pode ser maior que 26 X 26...");
        return;
    }

    //Alocação do tabuleiro
    tabuleiro = (Item**)malloc(tamLin*sizeof(Item*));
    for(int i = 0; i < tamLin; i++)
        (tabuleiro)[i] = (Item*)malloc(tamCol*sizeof(Item));


    //--------------------------------------------------------------------------------
    
    //Leitura e alocação da quantidade de palavras
    fscanf(dicionario, "%i", &quantidade);
    palavras = malloc(quantidade * sizeof(Palavra));

    //--------------------------------------------------------------------------------

    //Caso alguma das alocações falhar imprime erro
    if(tabuleiro == NULL || palavras == NULL){
        printf("\nErro.");
        return;
    }

    //---------------------------------------------------------------------------------------------
    
    //Menu dificuldades
    dificuldade = menuDificuldade();

    if(dificuldade == 0)
        return;

    //---------------------------------------------------------------------------------------------
    
    //Caso a quantidade de palavras seja 0 o programa se encerra
    if(quantidade == 0){
        printf("\n0 Palavras no input"); 
        sairJogo(tabuleiro, palavras, tamLin);
        return;
    }

    //fgets para pegar o '\n' depois da 'quantidade de palavras' no arquivo
    fgets(tmp, 100, dicionario);

    //---------------------------------------------------------------------------------------------

    //Pegar as palavras do arquivo
    for (int i = 0; i < quantidade; i++){
        fgets(palavras[i].palavra, 100, dicionario);

        //Se Não for a última palavraou a palavra tiver um '\n' remove o '\n' do final e coloca um '\0'
        if(i != quantidade-1 || palavras[i].palavra[strlen(palavras[i].palavra)-1] == '\n'){
            palavras[i].palavra[strlen(palavras[i].palavra)-1] = '\0';
        }
        
        //Inicializa o 'tamanho' das palavras
        palavras[i].tamanho = strlen(palavras[i].palavra);

        //Se o tamanho das palavras for maior que o tamanho do tabuleiro então ele nao cabe no tabuleiro. Ela sera ignorada
        if(palavras[i].tamanho > tamCol && palavras[i].tamanho > tamLin){
            printf("\nPalavra \"%s\" Rejeitada. Muita grande para o tabuleiro.\n", palavras[i].palavra);
            i--;
            quantidade--;
        }
        //Acumula o total de letras
        else
            totalLetrasPalavras = totalLetrasPalavras + palavras[i].tamanho;
    } 

    //---------------------------------------------------------------------------------------------

    //Se a malha for composta ele terá um espaço (atletico mineiro)
    //Esse espaço é removido e substituído por um '-' para evitar problemas
    for (int i = 0; i < quantidade; i++){
        for (int j = 0; j < palavras[i].tamanho; j++){
            if(palavras[i].palavra[j] == ' ')
                palavras[i].palavra[j] = '-';
        }
    }    

    //---------------------------------------------------------------------------------------------


    //Verifica se tem repetidas e a remove
    for(int i = 0; i < quantidade; i++){
        for(int j = i+1; j < quantidade; j++){
            if(strcmp(palavras[i].palavra, palavras[j].palavra) == 0){
                printf("\nPalavar \"%s\" eh repetida. Sera ignorada\n", palavras[i].palavra);
                for (int k = j; k < quantidade - 1; k++){
                    strcpy(palavras[k].palavra, palavras[k+1].palavra);
                    palavras[k].tamanho = palavras[k+1].tamanho;  
                }
                quantidade--;
                j--;
            }
        }   
    }

    //---------------------------------------------------------------------------------------------

    //sort palavras maior para menor
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

    //---------------------------------------------------------------------------------------------

    //Coloca as palavras em caixa alta
    for (int i = 0; i < quantidade; i++){
        for (int j = 0; j < palavras[i].tamanho; j++){
            if(palavras[i].palavra[j] >= 'a' && palavras[i].palavra[j] <= 'z')
                palavras[i].palavra[j] = palavras[i].palavra[j] - 32;
        }        
    } 

    //---------------------------------------------------------------------------------------------

    //Calcula a razão em o total de palavras e o tomanho do tabuleiro
    razao = (double)totalLetrasPalavras / (double)TotalTamanhoTabuleiro;

    //---------------------------------------------------------------------------------------------

    //Se a razão for maior que 1 estão tem mais palavras que espaço no tabuleiro. Programa de encerra
    if(razao > 1){
        printf("Muitas palavras para o tabuleiro. ");
        sairJogo(tabuleiro, palavras, tamLin);
        return;
    }

    //---------------------------------------------------------------------------------------------

    //Caso Todas as palavras do input alguma restrição o programa se encerra
    if(quantidade == 0){
        printf("\nTodas as palavras do input alguma restrição"); 
        sairJogo(tabuleiro, palavras, tamLin);
        return;
    }

    //---------------------------------------------------------------------------------------------

    //Caso a menor palavra (a ultima da vetor de palavras) não caiba ou na linha ou na coluna e a razão foi maior que 0.7 (tem muitas palavras para o tabuleiro)
    //Entra no modo sem regulação de direção (ver mais a frente)
    if(palavras[quantidade-1].tamanho > tamLin || palavras[quantidade-1].tamanho > tamCol || razao > 0.7)
        modoSemRegulacaoDirecao = 1;

    //---------------------------------------------------------------------------------------------
    
    //Inicializa o cont de direção (conta quantas palavras tem em cada direção)
    for (int i = 0; i < 8; i++)
        contDirecao[i] = 0;

    //Inicializa o tabuleiro como 0 e letras aleatorias
    for (int l = 0; l < tamLin; l++){
        for (int k = 0; k < tamCol; k++){
            escolhaLetra = rand() % (26);
            tabuleiro[l][k].caractere = escolhaLetra + 'A';
            tabuleiro[l][k].fazPartePalavra = 0;
            tabuleiro[l][k].marcadoUsuario = 0;
        }       
    }

    //---------------------------------------------------------------------------------------------

    while (1){
        //Percorre a matriz do tabuleiro
        for (int i = 0; i < tamLin; i++){
            for (int j = 0; j < tamCol; j++){

                //Dificuldade 1
                if(dificuldade == 1){
                    //Geração dos numero aleatório
                    escolhaDirecao = rand() % (2);
                    //Quanto menenor a 'razão' menor é a frequência que se tenta colocar uma palavra no tabuleiro
                    escolhaColocar = rand() % (1000) + (razao * 200);

                    if(escolhaColocar >= 995){
                        colocaPalavra(escolhaDirecao, &contColocadas, i, j, tamLin, tamCol, palavras, tabuleiro, contDirecao);
                    }

                    //Se todas as palavra forem colocadas e se tenha ao menos 1 para a direção 0 e 1 então o tabuleiro esta pronto
                    if((quantidade == contColocadas && contDirecao[0] != 0 && contDirecao [1] != 0) && quantidade >= 2){
                        tabuleiroPronto = 1;
                        break;
                    }
                    //Se todas as palavra forem colocadas e a quantidade de palavras form menor que 2 então o tabuleiro esta pronto
                    //Se todas as palavra forem colocadas e o modo sem regulação de direção então o tabuleiro esta pronto
                    else if((quantidade == contColocadas && quantidade < 2) || (quantidade == contColocadas && modoSemRegulacaoDirecao == 1)){
                        tabuleiroPronto = 1;
                        break;
                    }
                }

                //Mesma coisa da primeira dificuldade muda apenas as possibilidade das direções
                //Dificuldade 2
                else if(dificuldade == 2){
                    escolhaDirecao = rand() % (3);
                    escolhaColocar = rand() % (1000) + (razao * 200);

                    if(escolhaColocar >= 995){
                        colocaPalavra(escolhaDirecao, &contColocadas, i, j, tamLin, tamCol, palavras, tabuleiro, contDirecao);
                    }

                    if((quantidade == contColocadas && contDirecao[0] != 0 && contDirecao [1] != 0 && contDirecao[2] != 0) && quantidade >= 3){
                        tabuleiroPronto = 1;
                        break;
                    }
                    else if((quantidade == contColocadas && quantidade < 3) || (quantidade == contColocadas && modoSemRegulacaoDirecao == 1)){
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

                    if(quantidade == contColocadas && contDirecao[0] != 0 && contDirecao [1] != 0 && contDirecao[2] != 0 && contDirecao[3] != 0 &&
                                                      contDirecao[4] != 0 && contDirecao [5] != 0 && contDirecao[6] != 0){
                        tabuleiroPronto = 1;
                        break;
                    }
                    else if((quantidade == contColocadas && quantidade < 7) || (quantidade == contColocadas && modoSemRegulacaoDirecao == 1)){
                        tabuleiroPronto = 1;
                        break;
                    }
                }
            }
    
            //Se o tabuleiroPronto for 1 então o tabuleiro esta completo sai do loop 
            if(tabuleiroPronto == 1)
                break;       
        }
        //Conta quantas tentativas foram feitas nesse tabuleiro
        tentativas++;

        //Se o tabuleiroPronto for 1 então o tabuleiro esta completo sai do loop 
        if(tabuleiroPronto == 1)
            break; 

        //Se o tabuleiroPronto for diferente de 1 e 5 tentativas foram feitas nesse tabuleiro então e resetado e começa de novo
        else if(tabuleiroPronto != 1 && tentativas == 5){
            tentativas = 0;
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

    //----------------------------------------------------------------------------------------------------- 0 

    //Se a direção sorteada for 0 e a palavra couber começando na linha e coluna atual entra no if
    if(escolhaDirecao == 0 && col + palavras[(*contColocadas)].tamanho <= tamCol){
        
        //Percorre a matriz do tabuleiro na direção especificada.
        //Nesse caso é Horizontal, Esquerda para direita Fixa a linha atual e aumenta a coluna
        for (int i = col, j = 0; j < palavras[(*contColocadas)].tamanho; i++, j++){
            //Se algum elementa do tabuleiro for diferente da palavra sai do loop e aprovado recebe 0
            if(tabuleiro[lim][i].fazPartePalavra == 1 && tabuleiro[lim][i].caractere != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }
        //Como aprovado é inicializado com 1. Se não entrar no if anterior (ou seja) se os elementos forem todos iguais a palavra foi encontradas.
        if(aprovado == 1){
            //Cópia as componentes da palavra para a tabuleiro
            //Inicializa 'fazPartePalavra' com 1 e 'marcadoUsuario' com 0
            for (int i = col, j = 0; j < palavras[(*contColocadas)].tamanho; i++, j++){
                tabuleiro[lim][i].caractere = palavras[(*contColocadas)].palavra[j];     
                tabuleiro[lim][i].fazPartePalavra = 1;
                tabuleiro[lim][i].marcadoUsuario = 0;
            }
            //Incrementa o contador das colocadas e o contador da direção específica
            (*contColocadas)++;
            contDirecao[0] = contDirecao[0] + 1;
        }
        //Reset do aprovado para 1
        aprovado = 1;
    }

    //Todos o resto é a mesma coisa, mudando apenasa forma como se percorre o tabuleiro para verificar todas as direções
    //----------------------------------------------------------------------------------------------------- 1

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

    //----------------------------------------------------------------------------------------------------- 2

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

    //----------------------------------------------------------------------------------------------------- 3

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

    // //----------------------------------------------------------------------------------------------------- 4

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

    // //----------------------------------------------------------------------------------------------------- 5

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

    // //----------------------------------------------------------------------------------------------------- 6

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

    // //----------------------------------------------------------------------------------------------------- 7

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

