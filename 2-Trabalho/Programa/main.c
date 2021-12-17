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

#define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_BOLD             "\x1b[1m"  // coloca o texto em negrito
#define ANSI_COLOR_BLACK      "\x1b[30m"
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"
#define ANSI_COLOR_WHITE      "\x1b[37m"
#define ANSI_BG_COLOR_BLACK   "\x1b[40m"
#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_GREEN   "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
#define ANSI_BG_COLOR_BLUE    "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN    "\x1b[46m"
#define ANSI_BG_COLOR_WHITE   "\x1b[47m"

// macros para facilitar o uso
#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET
#define WHITE(string)      ANSI_COLOR_WHITE      string ANSI_RESET
#define BG_BLACK(string)   ANSI_BG_COLOR_BLACK   string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string)    ANSI_BG_COLOR_CYAN    string ANSI_RESET
#define BG_WHITE(string)   ANSI_BG_COLOR_WHITE   string ANSI_RESET

// caracteres uteis para tabelas
#define TAB_HOR "\u2501" // ━ (horizontal)
#define TAB_VER "\u2503" // ┃ (vertical)
#define TAB_TL  "\u250F" // ┏ (top-left)
#define TAB_ML  "\u2523" // ┣ (middle-left)
#define TAB_BL  "\u2517" // ┗ (bottom-left)
#define TAB_TJ  "\u2533" // ┳ (top-join)
#define TAB_MJ  "\u254B" // ╋ (middle-join)
#define TAB_BJ  "\u253B" // ┻ (bottom-join)
#define TAB_TR  "\u2513" // ┓ (top-right)
#define TAB_MR  "\u252B" // ┫ (middle-right)
#define TAB_BR  "\u251B" // ┛ (bottom-right)

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

void menu();
void menuDificuldade();

void criarJogo();
void colocaPalavra(int escolhaDirecao, int *contColocadas, int lim, int col, int tamLin, int tamCol, Palavra *palavras ,Item **tabuleiro, int *contDirecao);

int jogar(Palavra *palavras ,Item **tabuleiro, int tamLin, int tamCol, int quantidade);
Comando interpretaComando(char comandoCompleto[]);
int verificaEscolha(Comando comando, Palavra *palavras ,Item **tabuleiro, int *encontradas, int quantidade, int tamCol, int tamLin);

void resolveTabuleiro();
void salvaJogo();
void continuaJogo();

int main(int argc, char *argv[ ]){
    time_t t;   
    srand((unsigned) time(&t));

    printf("Bem vindo ao Caca Palavras");
    menu();

    printf("\n");

    return 0;
}

void menu(){

    int escolha;

    printf("\nO que deseja fazer:\n");

    printf("\n1.  Comecar um novo jogo");
    printf("\n2.  Continuar um novo jogo");
    printf("\n3.  Instrucoes do jogo\n\n");

    //Sair do Jogo == Sair do programa
    printf("Escolha a opcao (digite ”sair” em qualquer lugar para sair do jogo): ");
    while (escolha != 1 && escolha != 2 && escolha != 3){
        scanf("%i", &escolha);
        switch (escolha){
        case 1:
            criarJogo();
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        default: printf("Opcao Invalida. Tente Novamente: ");
            break;
        }
    }
}

void criarJogo(){
    Item **tabuleiro;
    Palavra *palavras;

    char lixo[100];
    int contDirecao[8] = {0};
    int feito = 0;
    int retornoJogo;

    char nomeArquivo[100];

    int tamLin, tamCol, quantidade, dificuldade;
    int escolhaDirecao = 0, escolhaColocar, escolhaLetra, contColocadas = 0;

    FILE *dicionario = fopen("dicionario.txt", "r");

    //---------------------------------------------------------------------------------------------
    
    printf("\nAbrindo \"dicionario.txt\"...");
    if(dicionario == NULL){
        printf("\nErro ao abrir arquivo..");
        return;
    }

    fscanf(dicionario, "%i %i", &tamLin, &tamCol);

    if(tamLin > 26 || tamCol > 26){
        printf("\nTabuleiro nao pode ser maior que 26 X 26...");
        return;
    }

    tabuleiro = (Item**)malloc(tamLin*sizeof(Item*));
    for(int i = 0; i < tamLin; i++)
        (tabuleiro)[i] = (Item*)malloc(tamCol*sizeof(Item));

    fscanf(dicionario, "%i", &quantidade);
    palavras = malloc(quantidade * sizeof(Palavra));

    if(tabuleiro == NULL || dicionario == NULL){
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
        switch (dificuldade){
        case 1: dificuldade = 1; break;
        case 2: dificuldade = 2; break;
        case 3: dificuldade = 3; break;
        default: printf("Opcao Invalida. Tente Novamente: ");
            break;
        }
    }
    while ((getchar()) != '\n');

    //---------------------------------------------------------------------------------------------

    fgets(lixo, 100, dicionario);
    for (int i = 0; i < quantidade; i++){
        fgets(palavras[i].palavra, 100, dicionario);

        if(i != quantidade-1){
            palavras[i].palavra[strlen(palavras[i].palavra)-1] = '\0';
        }
        
        palavras[i].tamnho = strlen(palavras[i].palavra);

    } 

    for (int i = 0; i < quantidade; i++){
        for (int j = 0; j < palavras[i].tamnho; j++){
            if(palavras[i].palavra[j] >= 'a' && palavras[i].palavra[j] <= 'z')
                palavras[i].palavra[j] = palavras[i].palavra[j] - 32;
        }        
    } 

    //---------------------------------------------------------------------------------------------
    
    for (int i = 0; i < 8; i++)
        contDirecao[i] = 0;

    for (int l = 0; l < tamLin; l++){
        for (int k = 0; k < tamCol; k++){
            escolhaLetra = rand() % (26);
            tabuleiro[l][k].caractere = escolhaLetra + 'A';
            tabuleiro[l][k].fazPartePalavra = 0;
        }       
    }

    while (1){

        for (int i = 0; i < tamLin; i++){
            for (int j = 0; j < tamCol; j++){
                
                //Dificuldade 1
                if(dificuldade == 1){
                    escolhaDirecao = rand() % (2);
                    escolhaColocar = rand() % (100);

                    if(escolhaColocar >= 90){
                        colocaPalavra(escolhaDirecao, &contColocadas, i, j, tamLin, tamCol, palavras, tabuleiro, contDirecao);
                    }

                    if(quantidade == contColocadas && contDirecao[0] != 0 && contDirecao [1] != 0){
                        feito = 1;
                        break;
                    }
                }

                //Dificuldade 2
                else if(dificuldade == 2){
                    escolhaDirecao = rand() % (3);
                    escolhaColocar = rand() % (100);

                    if(escolhaColocar >= 90){
                        colocaPalavra(escolhaDirecao, &contColocadas, i, j, tamLin, tamCol, palavras, tabuleiro, contDirecao);
                    }

                    if(quantidade == contColocadas && contDirecao[0] != 0 && contDirecao [1] != 0 && contDirecao[2] != 0){
                        feito = 1;
                        break;
                    }
                }

                //Dificuldade 3
                else{
                    escolhaDirecao = rand() % (8);
                    escolhaColocar = rand() % (100);

                    if(escolhaColocar >= 90){
                        colocaPalavra(escolhaDirecao, &contColocadas, i, j, tamLin, tamCol, palavras, tabuleiro, contDirecao);
                    }

                    if(quantidade == contColocadas && contDirecao[0] != 0 && contDirecao [1] != 0 && contDirecao[2] != 0 && contDirecao[7] != 0){
                        feito = 1;
                        break;
                    }
                }
            }

            if(feito == 1)
                break;       
        }

        if(feito == 1)
            break; 

        else{
            contColocadas = 0;
            feito = 0;
            for (int l = 0; l < tamLin; l++){
                for (int k = 0; k < tamCol; k++){
                    escolhaLetra = rand() % (26);
                    tabuleiro[l][k].caractere = escolhaLetra + 'A';
                    tabuleiro[l][k].fazPartePalavra = 0;
                }       
            }
            for (int i = 0; i < 8; i++)
                contDirecao[i] = 0;  
        }        
    }

    
    //---------------------------------------------------------------------------------------------

    printf("  ");
    for (int i = 0; i < tamCol; i++)
        printf(BLUE("%c "), 'A'+ i);

    printf("\n");

    for (int i = 0; i < tamLin; i++){
        printf(BLUE("%c "), 'A'+ i);
        for (int j = 0; j < tamCol; j++){
            if(tabuleiro[i][j].fazPartePalavra == 1){
                printf(BOLD(RED("%c ")), tabuleiro[i][j].caractere);
            }
            else
                printf("%c ", tabuleiro[i][j].caractere);
        }       
        printf("\n");        
    } 

    //---------------------------------------------------------------------------------------------


    for (int i = 0; i < quantidade; i++)
        palavras[i].marcado = 0;

    
    while (retornoJogo != quantidade){
        retornoJogo = jogar(palavras ,tabuleiro, tamLin, tamCol, quantidade);
        
        if(retornoJogo == quantidade){
            printf("\nTodas as palavras Encontradas");
            printf("\nSalvando no arquivo save.txt");
            return;
        }

    }

}

void colocaPalavra(int escolhaDirecao, int *contColocadas, int lim, int col, int tamLin, int tamCol, Palavra *palavras, Item **tabuleiro, int *contDirecao){
    
    int aprovado = 1;

    //-----------------------------------------------------------------------------------------------------0 
    if(escolhaDirecao == 0 && col + palavras[(*contColocadas)].tamnho <= tamCol){

        for (int i = col, j = 0; j < palavras[(*contColocadas)].tamnho; i++, j++){
            if(tabuleiro[lim][i].fazPartePalavra == 1 && tabuleiro[lim][i].fazPartePalavra != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            for (int i = col, j = 0; j < palavras[(*contColocadas)].tamnho; i++, j++){
                tabuleiro[lim][i].caractere = palavras[(*contColocadas)].palavra[j];     
                tabuleiro[lim][i].fazPartePalavra = 1;
            }
            (*contColocadas)++;
            contDirecao[0] = contDirecao[0] + 1;
        }
        aprovado = 1;
    }

    //-----------------------------------------------------------------------------------------------------1

    else if(escolhaDirecao == 1 && lim + palavras[(*contColocadas)].tamnho <= tamLin){

        for (int i = lim, j = 0; j < palavras[(*contColocadas)].tamnho; i++, j++){
            if(tabuleiro[i][col].fazPartePalavra == 1 && tabuleiro[i][col].fazPartePalavra != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, j = 0; j < palavras[(*contColocadas)].tamnho; i++, j++){
                tabuleiro[i][col].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][col].fazPartePalavra = 1;
            }
            (*contColocadas)++;
            contDirecao[1] = contDirecao[1] + 1;
        }
        aprovado = 1;
    }

    //-----------------------------------------------------------------------------------------------------2

   else if(escolhaDirecao == 2 && lim + palavras[(*contColocadas)].tamnho <= tamLin && col + palavras[(*contColocadas)].tamnho <= tamCol){
        for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamnho; i++, j++, k++){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].fazPartePalavra != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamnho; i++, j++, k++){
                tabuleiro[i][k].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][k].fazPartePalavra = 1;
            }
            (*contColocadas)++;
            contDirecao[2] = contDirecao[2] + 1;
        }
        aprovado = 1;
    }

    //-----------------------------------------------------------------------------------------------------3

    else if(escolhaDirecao == 3 && col + palavras[(*contColocadas)].tamnho <= tamCol && lim - (int)palavras[(*contColocadas)].tamnho >= 0){
       
        for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamnho; i--, j++, k++){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].fazPartePalavra != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamnho; i--, j++, k++){
                tabuleiro[i][k].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][k].fazPartePalavra = 1;
            }
            (*contColocadas)++;
            contDirecao[3]++;
        }
        aprovado = 1;
    }

    // //-----------------------------------------------------------------------------------------------------4

    else if(escolhaDirecao == 4 && lim - (int)palavras[(*contColocadas)].tamnho >= 0){
        for (int i = lim, j = 0; j < palavras[(*contColocadas)].tamnho; i--, j++){
            if(tabuleiro[i][col].fazPartePalavra == 1 && tabuleiro[i][col].fazPartePalavra != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, j = 0; j < palavras[(*contColocadas)].tamnho; i--, j++){
                tabuleiro[i][col].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][col].fazPartePalavra = 1;
            }
            (*contColocadas)++;
            contDirecao[4] = contDirecao[4] + 1;
        }
        aprovado = 1;
    }

    // //-----------------------------------------------------------------------------------------------------5

    else if(escolhaDirecao == 5 && col - (int)palavras[(*contColocadas)].tamnho >= 0){
        for (int i = col, j = 0; j < palavras[(*contColocadas)].tamnho; i--, j++){
            if(tabuleiro[i][lim].fazPartePalavra == 1 && tabuleiro[i][lim].fazPartePalavra != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = col, j = 0; j < palavras[(*contColocadas)].tamnho; i--, j++){
                tabuleiro[i][lim].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][lim].fazPartePalavra = 1;
            }
            (*contColocadas)++;
            contDirecao[5] = contDirecao[5] + 1;
        }
        aprovado = 1;
    }

    // //-----------------------------------------------------------------------------------------------------6

    else if(escolhaDirecao == 6 && lim - (int)palavras[(*contColocadas)].tamnho >= 0 && col + (int)palavras[(*contColocadas)].tamnho >= 0){
        for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamnho; i--, j++, k--){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].fazPartePalavra != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamnho; i--, j++, k--){
                tabuleiro[i][k].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][k].fazPartePalavra = 1;
            }
            (*contColocadas)++;
            contDirecao[6] = contDirecao[6] + 1;
        }
        aprovado = 1;
    }

    // //-----------------------------------------------------------------------------------------------------7

    else if(escolhaDirecao == 7 && lim + palavras[(*contColocadas)].tamnho <= tamLin && col + (int)palavras[(*contColocadas)].tamnho >= 0){
        for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamnho; i++, j++, k--){
            if(tabuleiro[i][k].fazPartePalavra == 1 && tabuleiro[i][k].fazPartePalavra != palavras[*contColocadas].palavra[j]){
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            
            for (int i = lim, k = col, j = 0; j < palavras[(*contColocadas)].tamnho; i++, j++, k--){
                tabuleiro[i][k].caractere = palavras[(*contColocadas)].palavra[j];
                tabuleiro[i][k].fazPartePalavra = 1;
            }
            (*contColocadas)++;
            contDirecao[7] = contDirecao[7] + 1;
        }
        aprovado = 1;
    }

}

int jogar(Palavra *palavras ,Item **tabuleiro, int tamLin, int tamCol, int quantidade){
    
    char comandoCompleto[100];
    int encontradas=0, retornoVerificacao;
    Comando comando;

    //---------------------------------------------------------------------------------------------

    printf("\n");
    
    printf("  ");
    for (int i = 0; i < tamCol; i++)
        printf(BLUE("%c "), 'A'+ i);

    printf("\n");

    for (int i = 0; i < tamLin; i++){
        printf(BLUE("%c "), 'A'+ i);
        for (int j = 0; j < tamCol; j++){
            if(tabuleiro[i][j].marcadoUsuario == 1){
                printf(BOLD(YELLOW("%c ")), tabuleiro[i][j].caractere);
            }
            else
                printf("%c ", tabuleiro[i][j].caractere);
        }       
        printf("\n");        
    } 

    //---------------------------------------------------------------------------------------------

    comando.numeroComando = 0;
    comando.limC = tamLin+1; 
    comando.colC = tamCol+1;
    comando.limF = tamLin+1;
    comando.colF = tamCol+1;
    
    //---------------------------------------------------------------------------------------------

    while (comando.numeroComando == 0 || comando.limC > tamLin-1 || comando.limF > tamLin-1 || comando.colC > tamCol-1 || comando.colF > tamCol-1){
        printf("\nDigite o Comando: ");
        fgets(comandoCompleto, 100, stdin);
        comandoCompleto[strlen(comandoCompleto)-1] = '\0';

        comando = interpretaComando(comandoCompleto);    

        if(comando.numeroComando == 0)
            printf("Comando Invalido!\n");

        if(comando.limC > tamLin-1 || comando.limF > tamLin-1 || comando.colC > tamCol-1 || comando.colF > tamCol-1)
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
        return 1; //salvaJogo();
    }

    else if(comando.numeroComando == 3){
        return 1; //resolveTabuleiro();
    } 
    
    else
        return 1;

    //---------------------------------------------------------------------------------------------

    return encontradas;
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

    else if(direcao == 3){
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

    else if(direcao == 4){
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

    else if(direcao == 5){
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

    else if(direcao == 6){
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

    else if(direcao == 7){
        for (int t = 0; t < quantidade; t++){
            for (int i = comando.limC, k = comando.limC, j = 0; j < palavras[t].tamnho; i++, j++, k--){
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

Comando interpretaComando(char comandoCompleto[]){
    Comando comando;
    char marcar[] = "MARCAR\0";


    for (int i = 0; i < strlen(comandoCompleto); i++){
        if(comandoCompleto[i] >= 'a' && comandoCompleto[i] <= 'z')
                comandoCompleto[i] = comandoCompleto[i] - 32;
    }

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
    else if(strstr(comandoCompleto, "SALVAR") != NULL && strlen(comandoCompleto) == 6){
        comando.numeroComando = 2;
        return comando;
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