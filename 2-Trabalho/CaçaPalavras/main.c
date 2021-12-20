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

//**********************************************************************************************************************

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


//**********************************************************************************************************************

typedef struct{
    char palavra[100];
    int marcado;
    int tamanho;
    int limC, colC;
    int limF, colF;
}Palavra;

typedef struct{
    char caractere;
    int dificuldade;
    int fazPartePalavra;
    int marcadoUsuario;
}Item;

typedef struct{
    int numeroComando;
    char nomeArquivoSave[100];
    int limC, colC;
    int limF, colF;
}Comando;

// typedef struct{
//     int limC, colC;
//     int limF, colF;
// }Coordenada;

//**********************************************************************************************************************

void menu();
void menuDificuldade();
void printInstrucoes();
void printTabuleiroInstrucao(int tamLin, int tamCol, Item tabuleiro[11][11], int escolha);

//-----------------------------------------------------------------------------------------------------------------------

void criarJogo();
void colocaPalavra(int escolhaDirecao, int *contColocadas, int lim, int col, int tamLin, int tamCol, Palavra *palavras ,Item **tabuleiro, int *contDirecao);

//-----------------------------------------------------------------------------------------------------------------------

void jogar(Palavra *palavras ,Item **tabuleiro, int tamLin, int tamCol, int quantidade);
Comando interpretaComando(char comandoCompleto[]);
int verificaEscolha(Comando comando, Palavra *palavras ,Item **tabuleiro, int *encontradas, int quantidade, int tamCol, int tamLin);

//-----------------------------------------------------------------------------------------------------------------------

void salvaJogo(int quantidade, int tamLin, int tamCol, Item **tabuleiro, Palavra *palavras, char nomeArquivoSave[]);
void printResolvido(int tamLin, int tamCol, Item **tabuleiro, int escolha);
void continuaJogo();
void resolveTabuleiroSaveGame(int quantidade, int tamLin, int tamCol, Item **tabuleiro, Palavra *palavras);
void sairJogo(Item **tabuleiro, Palavra *palavras, int tamLin);

//**********************************************************************************************************************

int main(int argc, char *argv[ ]){
    time_t t;   
    srand((unsigned) time(&t));
    setlocale(LC_ALL,"");

    printf("Bem vindo ao Caça Palavras");
    menu();


    printf("\n");

    return 0;
}

void menu(){

    int escolha;
    char escolhaChar[20];

    printf("\nO que deseja fazer:\n");

    printf("\n1.  Comecar um novo jogo");
    printf("\n2.  Continuar um novo jogo");
    printf("\n3.  Instrucoes do jogo\n\n");

    printf("Escolha a opcao (digite ”sair” em qualquer lugar para sair do jogo): ");
    while (strcmp(escolhaChar,"1") != 0 || strcmp(escolhaChar,"2") != 0 && strcmp(escolhaChar,"3") != 0 && strcmp(escolhaChar,"SAIR") != 0){
        fgets(escolhaChar, 20, stdin);
        escolhaChar[strlen(escolhaChar)-1] = '\0';

        for (int i = 0; i < strlen(escolhaChar); i++){
            if(escolhaChar[i] >= 'a' && escolhaChar[i] <= 'z')
                escolhaChar[i] = escolhaChar[i]-32;
        }        

        if(strcmp(escolhaChar,"1") == 0){
            criarJogo();
            break;
        }
        
        else if(strcmp(escolhaChar,"2") == 0){
            continuaJogo();
            break;
        }
        else if(strcmp(escolhaChar,"3") == 0){
            printInstrucoes();
            printf("Vistas as instruções oque deseja fazer? ");
        }
        else if(strcmp(escolhaChar,"SAIR") == 0){
            return;
        }
        else
            printf("Opcao Invalida. Tente Novamente: ");
    }
}

void menuDificuldade(){
    //menu
}

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

void jogar(Palavra *palavras ,Item **tabuleiro, int tamLin, int tamCol, int quantidade){
    
    char comandoCompleto[100];
    int encontradas=0, retornoVerificacao;
    Comando comando;

    //---------------------------------------------------------------------------------------------

    printf("\n");

    printResolvido(tamLin, tamCol, tabuleiro, 0);

    //----------------------------------------------------------------------    

    while (encontradas != quantidade){

        comando.numeroComando = 0;
        comando.limC = tamLin+1; 
        comando.colC = tamCol+1;
        comando.limF = tamLin+1;
        comando.colF = tamCol+1;
        
        //---------------------------------------------------------------------------------------------
        
        while (comando.numeroComando == 0 || (comando.numeroComando == 1 && (comando.limC > tamLin-1 || comando.limF > tamLin-1 || comando.colC > tamCol-1 || comando.colF > tamCol-1))){
            printf("\nDigite o Comando: ");
            fgets(comandoCompleto, 100, stdin);
            comandoCompleto[strlen(comandoCompleto)-1] = '\0';

            comando = interpretaComando(comandoCompleto);    

            if(comando.numeroComando == 0)
                printf("Comando Invalido!\n");

            if(comando.numeroComando == 1 && (comando.limC > tamLin-1 || comando.limF > tamLin-1 || comando.colC > tamCol-1 || comando.colF > tamCol-1))
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
            salvaJogo(quantidade, tamLin, tamCol, tabuleiro, palavras, comando.nomeArquivoSave);
        }

        else if(comando.numeroComando == 3){
            printResolvido(tamLin, tamCol, tabuleiro, 1);
            sairJogo(tabuleiro, palavras, tamLin);
            printf("\nPena que nao conseguiu resolver, tchau!");
            return;
        } 
        
        else{
            sairJogo(tabuleiro, palavras, tamLin);
            return;
        }

        //---------------------------------------------------------------------------------------------

        printf("\n");    

        printResolvido(tamLin, tamCol, tabuleiro, 0);

        if(encontradas == quantidade){
            sairJogo(tabuleiro, palavras, tamLin);
            printf("\nTodas as palavra encontradas!");

        }
    }

    return;
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
    else if(comando.colC == comando.colF && comando.limC == comando.limF)
        direcao = 0;
    

    if(direcao == 0){
            for (int t = 0; t < quantidade; t++){
                for (int i = comando.colC, j = 0; j < palavras[(t)].tamanho; i++, j++){
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

                        for (int u = comando.colC, p = 0; p < palavras[(t)].tamanho; u++, p++)   {                         
                            tabuleiro[comando.limC][u].marcadoUsuario = 1;
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

    char marcar[] = "MARCAR\0";

    char salvar[] = "SALVAR\0";
    char nomeArquivoTmp[100];
    int indiceFim = 0;
    int tamanhoTmp;

    for (int i = 0; i < strlen(comandoCompleto); i++){
        nomeArquivoTmp[i] = comandoCompleto[i];

        if(comandoCompleto[i] >= 'a' && comandoCompleto[i] <= 'z')
                comandoCompleto[i] = comandoCompleto[i] - 32;        
    }
    nomeArquivoTmp[strlen(comandoCompleto)] = '\0';

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
    else if(strstr(comandoCompleto, "SALVAR") != NULL){
        for (int i = 0; i < 6; i++){
            if(comandoCompleto[i] != salvar[i]){
                comando.numeroComando = 0;
                return comando;
            }
        }
        if(comandoCompleto[6] == ' '){
            for (int i = 0; i < strlen(comandoCompleto); i++){   
                if(comandoCompleto[i] == '.' && comandoCompleto[i+1] == 'T' && comandoCompleto[i+2] == 'X' && comandoCompleto[i+3] == 'T'){
                    indiceFim = i;
                    break;
                }

                if((comandoCompleto[i] == '/')){
                    comando.numeroComando = 0;
                    return comando;
                }
                
            }

            if(indiceFim != 0)
                for (int i = 7, j = 0; j < indiceFim - 7; i++, j++){
                    comando.nomeArquivoSave[j] = nomeArquivoTmp[i];
                    if(j == (indiceFim - 7)-1)
                        comando.nomeArquivoSave[j+1] = '\0';
                }
            else{
                for (int i = 7, j = 0; j < strlen(comandoCompleto) - 7; i++, j++){
                    comando.nomeArquivoSave[j] = nomeArquivoTmp[i];
                    if(j == (strlen(comandoCompleto) - 7)-1)
                        comando.nomeArquivoSave[j+1] = '\0';

                }                
            }
            tamanhoTmp = strlen(comando.nomeArquivoSave);
            comando.nomeArquivoSave[tamanhoTmp+0] = '.';
            comando.nomeArquivoSave[tamanhoTmp+1] = 't';
            comando.nomeArquivoSave[tamanhoTmp+2] = 'x';
            comando.nomeArquivoSave[tamanhoTmp+3] = 't';
            comando.nomeArquivoSave[tamanhoTmp+4] = '\0';

            comando.numeroComando = 2;
            return comando;           
        }

        else{
            comando.numeroComando = 0;
            return comando;
        }

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

void salvaJogo(int quantidade, int tamLin, int tamCol, Item **tabuleiro, Palavra *palavras, char nomeArquivoSave[]){
    FILE *save = fopen(nomeArquivoSave, "w");

    printf("\nAbrindo \"%s\"...\n", nomeArquivoSave);
    if(save == NULL){
        printf("Erro ao abrir Aquivo.");
        return;
    }

    fprintf(save, "%i %i\n", tamLin, tamCol);

    for (int i = 0; i < tamLin; i++){
        for (int j = 0; j < tamCol; j++){
            fprintf(save, "%c ", tabuleiro[i][j].caractere);
        }
        fprintf(save, "\n");        
    }    

    fprintf(save, "%i\n", quantidade);

    for (int i = 0; i < quantidade; i++){
        if(palavras[i].marcado == 1)
            fprintf(save, "%s %c%c %c%c\n", palavras[i].palavra, palavras[i].limC + 'A', palavras[i].colC + 'A', palavras[i].limF + 'A', palavras[i].colF + 'A');

        else
            fprintf(save, "%s -- --\n", palavras[i].palavra);
    }


    fclose(save);
}

void printResolvido(int tamLin, int tamCol, Item **tabuleiro, int escolha){

    printf(BG_BLACK(TAB_TL));
    for (int i = 0; i < tamCol+1; i++){
        if(i != tamCol)
            printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_TJ));
    }
    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_TR) "\n");

    //----------------------------------------------------------------------

    printf(BG_BLACK(TAB_VER));

    printf(BG_BLACK("   "));
    for (int i = 0; i < tamCol; i++)
        printf(BG_BLACK(TAB_VER BLUE(" %c ")), 'A'+ i);

    printf(BG_BLACK(TAB_VER));

    printf("\n");

    //----------------------------------------------------------------------

    printf(BG_BLACK(TAB_ML));

    for (int i = 0; i < tamCol; i++)
        printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MJ));

    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MR) "\n");


    //----------------------------------------------------------------------


    for (int i = 0; i < tamLin; i++){
        printf(BG_BLACK(TAB_VER BLUE(" %c ")), 'A'+ i);
        for (int j = 0; j < tamCol; j++){
            if(tabuleiro[i][j].fazPartePalavra == 1 && escolha == 1){
                printf(BG_BLACK(TAB_VER BOLD(RED(" %c "))), tabuleiro[i][j].caractere);
            }
            else if(tabuleiro[i][j].marcadoUsuario == 1 && escolha == 0){
                printf(BG_BLACK(TAB_VER BOLD(YELLOW(" %c "))), tabuleiro[i][j].caractere);
            }
            
            else
                printf(BG_BLACK(TAB_VER " %c "), tabuleiro[i][j].caractere);
        }  
        printf(BG_BLACK(TAB_VER));

        if(i != tamLin - 1){     

            printf("\n");

            printf(BG_BLACK(TAB_ML));

            for (int i = 0; i < tamCol; i++)
                printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MJ));

            printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MR));    
        }

        printf("\n");
        
    } 


    //----------------------------------------------------------------------

    printf(BG_BLACK(TAB_BL));
    for (int i = 0; i < tamCol+1; i++){
        if(i != tamCol)
            printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_BJ));
    }
    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_BR) "\n");


}

void continuaJogo(){

    Item **tabuleiro;
    Palavra *palavras;

    char tmp;
    char nomeArquivo[100], nomeArquivoTmp[100];
    int tamanhoTmp, verificado = 0;
    int tamLin, tamCol, quantidade;

    FILE *save;

    // while (1){
    //     printf("\nDigite o nome do arquivo: ");
    //     while (verificado == 0){
    //         fgets(nomeArquivo, 100, stdin);
    //         nomeArquivo[strlen(nomeArquivo)-1] = '\0';

    //         for (int i = 0; i < strlen(nomeArquivo); i++){
    //             if((nomeArquivo[i] >= 'a' && nomeArquivo[i] <= 'z'))
    //                 nomeArquivoTmp[i] = nomeArquivo[i]-32;

    //             else if(nomeArquivo[i] != '/')
    //                 nomeArquivoTmp[i] = nomeArquivo[i];
                
    //             else{
    //                 verificado = 0;
    //                 break;
    //             }

    //             if(i == strlen(nomeArquivo) - 1){
    //                 verificado = 1;
    //                 nomeArquivoTmp[strlen(nomeArquivo)] = '\0';
    //             }
    //         }        

    //         if(strcmp(nomeArquivoTmp,"SAIR") == 0)
    //             return;
            
    //         if(verificado == 0)
    //             printf("Nome do arquivo invalido. Tente Novamente: ");
    //     }    


    //     tamanhoTmp = strlen(nomeArquivoTmp);
    //     if(nomeArquivoTmp[tamanhoTmp-1] != 'T' && nomeArquivoTmp[tamanhoTmp-2] != 'X' && nomeArquivoTmp[tamanhoTmp-3] != 'T' && nomeArquivoTmp[tamanhoTmp-4] != '.'){
    //         nomeArquivo[tamanhoTmp] = '.';
    //         nomeArquivo[tamanhoTmp+1] = 't';
    //         nomeArquivo[tamanhoTmp+2] = 'x';
    //         nomeArquivo[tamanhoTmp+3] = 't';
    //         nomeArquivo[tamanhoTmp+4] = '\0';
    //     }

    //     save = fopen(nomeArquivo, "r");

    //     //---------------------------------------------------------------------------------------------
        
    //     printf("Abrindo \"%s\"...\n", nomeArquivo);
    //     if(save == NULL){
    //         printf("\nErro ao abrir arquivo..");
    //         verificado = 0;
    //     }
    //     else
    //         break;

    // }  

    save = fopen("Files/save.txt", "r");

    fscanf(save, "%i %i", &tamLin, &tamCol);
    tabuleiro = (Item**)malloc(tamLin*sizeof(Item*));
    for(int i = 0; i < tamLin; i++)
        (tabuleiro)[i] = (Item*)malloc(tamCol*sizeof(Item));

    if(tabuleiro == NULL){
        printf("\nErro.");
        return;
    }
    
    for (int i = 0; i < tamLin; i++){
        for (int j = 0; j < tamCol; j++){
            fscanf(save, "%c", &tmp);
            if(tmp >= 'A' && tmp <= 'Z')
                tabuleiro[i][j].caractere = tmp;
            else
                j--;
        }
    }  


    //---------------------------------------------------------------------------------------------

    fscanf(save, "%i", &quantidade);
    palavras = malloc(quantidade * sizeof(Palavra));

    if(palavras == NULL){
        printf("\nErro.");
        return;
    }

    //---------------------------------------------------------------------------------------------

    fscanf(save, "%c", &tmp);
    for (int i = 0; i < quantidade; i++){
        for (int j = 0; j < 100; j++){
            fscanf(save, "%c", &tmp);   

            if(tmp >= 'A' && tmp <= 'Z')
                palavras[i].palavra[j] = tmp;

            if(tmp == ' ')
                break;
        }
        
        fscanf(save, "%c", &tmp);
        if(tmp >= 'A' && tmp <= 'Z'){
            palavras[i].limC = tmp - 'A';
            fscanf(save, "%c", &tmp);
            palavras[i].colC = tmp - 'A';
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            palavras[i].limF = tmp - 'A';
            fscanf(save, "%c", &tmp);
            palavras[i].colF = tmp - 'A';
            fscanf(save, "%c", &tmp);
            palavras[i].marcado = 1;
        }
        else{
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            fscanf(save, "%c", &tmp);
            palavras[i].marcado = 0;
        }    

        palavras[i].tamanho = strlen(palavras[i].palavra);    

    }  

    fclose(save);
    
    
    resolveTabuleiroSaveGame(quantidade, tamLin, tamCol, tabuleiro, palavras);
    jogar(palavras, tabuleiro, tamLin, tamCol, quantidade);
}

void resolveTabuleiroSaveGame(int quantidade, int tamLin, int tamCol, Item **tabuleiro, Palavra *palavras){
    
    int aprovado = 1, teste = 0;

    for (int i = 0; i < tamLin; i++)
        for (int j = 0; j < tamCol; j++)
            tabuleiro[i][j].fazPartePalavra == 0;

    for (int contColocadas = 0; contColocadas < quantidade; contColocadas++){
        
        for (int lim = 0; lim < tamLin; lim++){
            for (int col = 0; col < tamCol; col++){

                //######################################################################################################################## 0

                if(col + palavras[contColocadas].tamanho <= tamCol){

                    for (int i = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++){
                        if(tabuleiro[lim][i].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){
                        for (int i = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++){
                            tabuleiro[lim][i].fazPartePalavra = 1;
                            tabuleiro[lim][i].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        for (int i = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++){
                            tabuleiro[lim][i].fazPartePalavra = 1;
                            tabuleiro[lim][i].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;

                }

                //######################################################################################################################## 1

                if(lim + palavras[contColocadas].tamanho <= tamLin){

                    for (int i = lim, j = 0; j < palavras[contColocadas].tamanho; i++, j++){
                        if(tabuleiro[i][col].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){                        
                        for (int i = lim, j = 0; j < palavras[contColocadas].tamanho; i++, j++){
                            tabuleiro[i][col].fazPartePalavra = 1;
                            tabuleiro[i][col].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        
                        for (int i = lim, j = 0; j < palavras[contColocadas].tamanho; i++, j++){
                            tabuleiro[i][col].fazPartePalavra = 1;
                            tabuleiro[i][col].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }

                //######################################################################################################################## 2

                if(lim + palavras[contColocadas].tamanho <= tamLin && col + palavras[contColocadas].tamanho <= tamCol){
                    for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++, k++){
                        if(tabuleiro[i][k].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++, k++){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++, k++){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }

                //######################################################################################################################## 3

                if(col + palavras[contColocadas].tamanho <= tamCol && lim - palavras[contColocadas].tamanho >= 0){
                
                    for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++, k++){
                        if(tabuleiro[i][k].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++, k++){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++, k++){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }
    
                //######################################################################################################################## 4

                if(lim - palavras[contColocadas].tamanho >= 0){
                    for (int i = lim, j = 0; j < palavras[contColocadas].tamanho; i--, j++){
                        if(tabuleiro[i][col].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){
                        
                        for (int i = lim, j = 0; j < palavras[contColocadas].tamanho; i--, j++){
                            tabuleiro[i][col].fazPartePalavra = 1;
                            tabuleiro[i][col].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        
                        for (int i = lim, j = 0; j < palavras[contColocadas].tamanho; i--, j++){
                            tabuleiro[i][col].fazPartePalavra = 1;
                            tabuleiro[i][col].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }

                //######################################################################################################################## 5

                if(col - palavras[contColocadas].tamanho >= 0){
                    for (int i = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++){
                        if(tabuleiro[lim][i].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){
                        
                        for (int i = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++){
                            tabuleiro[lim][i].fazPartePalavra = 1;
                            tabuleiro[lim][i].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        
                        for (int i = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++){
                            tabuleiro[lim][i].fazPartePalavra = 1;
                            tabuleiro[lim][i].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }

                //######################################################################################################################## 6

                if(lim - palavras[contColocadas].tamanho >= 0 && col - palavras[contColocadas].tamanho >= 0){
                    for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++, k--){
                        if(tabuleiro[i][k].caractere != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++, k--){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }
                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i--, j++, k--){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 1;
                        }
                        teste = 1;
                        break;
                    }
                    aprovado = 1;
                }
                
                //######################################################################################################################## 7

                if(lim + palavras[contColocadas].tamanho <= tamLin && col - palavras[contColocadas].tamanho >= 0){
                    for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++, k--){
                        if(tabuleiro[i][k].fazPartePalavra != palavras[contColocadas].palavra[j]){
                            aprovado = 0;
                            break;
                        }
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 0){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++, k--){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 0;
                        }
                        teste = 1;
                        break;
                    }

                    if(aprovado == 1 && palavras[contColocadas].marcado == 1){
                        
                        for (int i = lim, k = col, j = 0; j < palavras[contColocadas].tamanho; i++, j++, k--){
                            tabuleiro[i][k].fazPartePalavra = 1;
                            tabuleiro[i][k].marcadoUsuario = 1;
                        }
                        teste = 1;
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
    
}

void sairJogo(Item **tabuleiro, Palavra *palavras, int tamLin){

    for (int i = 0; i < tamLin; i++)
        free(tabuleiro[i]);
    free(tabuleiro); 

    free(palavras); 
}

void printInstrucoes(){

    Item tabuleiro[11][11] = 
{
//            |  COL 0  |  |  COL 1  |  |  COL 2  |  |  COL 3  |  |  COL 4  |  |  COL 5  |  |  COL 6  |  |  COL 7  |  |  COL 8  |  |  COL 9  |  |  COL 10  |
/* LIN 0 */ { {'E',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'E',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'E',3,0,0} },
/* LIN 1 */ { {'A',0,0,0}, {'T',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'T',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'T',3,0,0}, {'A',0,0,0} },
/* LIN 2 */ { {'A',0,0,0}, {'A',0,0,0}, {'S',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'S',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'S',3,0,0}, {'A',0,0,0}, {'A',0,0,0} },
/* LIN 3 */ { {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'E',3,0,0}, {'A',0,0,0}, {'E',3,0,0}, {'A',0,0,0}, {'E',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0} },
/* LIN 4 */ { {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'T',3,0,0}, {'T',3,0,0}, {'T',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0} },
/* LIN 5 */ { {'E',3,0,0}, {'T',3,0,0}, {'S',3,0,0}, {'E',3,0,0}, {'T',3,0,0}, {'A',0,0,0}, {'T',1,0,0}, {'E',1,0,0}, {'S',1,0,0}, {'T',1,0,0}, {'E',1,0,0} },
/* LIN 6 */ { {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'T',3,0,0}, {'T',1,0,0}, {'T',2,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0} },
/* LIN 7 */ { {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'E',3,0,0}, {'A',0,0,0}, {'E',1,0,0}, {'A',0,0,0}, {'E',2,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0} },
/* LIN 8 */ { {'A',0,0,0}, {'A',0,0,0}, {'S',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'S',1,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'S',2,0,0}, {'A',0,0,0}, {'A',0,0,0} },
/* LIN 9 */ { {'A',0,0,0}, {'T',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'T',1,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'T',2,0,0}, {'A',0,0,0} },
/* LIN 10*/ { {'E',3,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'E',1,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'A',0,0,0}, {'E',2,0,0} }

};  


    printf("\n-------------------------------------------------------------------------\n");

    printf("\nOPCOES MENU");
    printf("\n1-Começar Novo Jogo: Escolha a dificuldade e Digite o nome do arquivo de dicionario. Comece a jogar");
    printf("\n2-Continuar Jogo Existente: Digite o nome do arquivo para leitura. Comece a jogar");
    printf("\n3-Instrucoes: O Menu Atual\n");

    printf("\nCOMANDOS MARCAR");
    printf("\nDigite \"marcar\" seguido na coordenada desejada.");
    printf("\nA coordenada deve estar dentro no tabuleiro.");
    printf("\nNao deixo espaço no final.");
    printf("\nCoordenada deve ser em letras.");
    printf("\nPode ser em caixa alta ou não");
    printf("\nModelo: Marcar AB CD\n");

    printf("\nCOMANDOS SALVAR");
    printf("\nDigite \"salvar\" seguido do nome do arquivo desejado.");
    printf("\nCaso voce nao coloque \".txt\" no final do nome do arquivo ele sera adicioando automaticamente");
    printf("\nPode estar em caixa alta ou nao");
    printf("\nModelo: Salvar teste.txt\n");

    printf("\nCOMANDOS RESOLVER");
    printf("\nDigite apenas \"resolver\".");
    printf("\nA resposta sera mostrada");
    printf("\nO programa sera encerrado");
    printf("\nPode estar em caixa alta ou nao");
    printf("\nModelo: Resolver\n");

    printf("\nCOMANDOS SAIR");
    printf("\nDigite apenas \"sair\".");
    printf("\nPrograma se encerra sem salvar");
    printf("\nPode estar em caixa alta ou nao");
    printf("\nModelo: Sair\n");

    printf("\nTABULEIRO EXEMPLO\n");
    printTabuleiroInstrucao(11, 11, tabuleiro, 2);

    printf("\nAZUL: Apenas Auxilio. Não faz Parte do Tabuleiro (Se a acumulam a cada dificuldade)");
    printf("\nCOR VERDE: dificuldade 1");
    printf("\nCOR AMARELO: dificuldade 2");
    printf("\nCOR VERMELHO: dificuldade 3\n");

    printf("\nO JOGO ENCERRA CASO: ");
    printf("\nSeja digitado sair");
    printf("\nTodas as palavras sejam marcadas");
    printf("\nSeja digitado resolver\n");


    printf("\nOUTROS");
    printf("\nO caractere \"/\" eh proibido para nome de arquivo.");
    printf("\nExistem mais cacteres proibidos no windows e eles nao sao verificados.");
    printf("\nPodem ocorrer erros no windows.");
    printf("\nNo jogo, as palavras marcadas serão amarelas e se escolher resolver, elas ficarão vermelhas\n");
    
    printf("\n-------------------------------------------------------------------------\n\n");
    
}

void printTabuleiroInstrucao(int tamLin, int tamCol, Item tabuleiro[11][11], int escolha){

    printf(BG_BLACK(TAB_TL));
    for (int i = 0; i < tamCol+1; i++){
        if(i != tamCol)
            printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_TJ));
    }
    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_TR) "\n");

    //----------------------------------------------------------------------

    printf(BG_BLACK(TAB_VER));

    printf(BG_BLACK("   "));
    for (int i = 0; i < tamCol; i++)
        printf(BG_BLACK(TAB_VER BLUE(" %c ")), 'A'+ i);

    printf(BG_BLACK(TAB_VER));

    printf("\n");

    //----------------------------------------------------------------------

    printf(BG_BLACK(TAB_ML));

    for (int i = 0; i < tamCol; i++)
        printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MJ));

    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MR) "\n");


    //----------------------------------------------------------------------


    for (int i = 0; i < tamLin; i++){
        printf(BG_BLACK(TAB_VER BLUE(" %c ")), 'A'+ i);
        for (int j = 0; j < tamCol; j++){

            if(escolha == 2 && tabuleiro[i][j].dificuldade == 1){
                    printf(BG_BLACK(TAB_VER BOLD(GREEN(" %c "))), tabuleiro[i][j].caractere);
            }
            else if(escolha == 2 && tabuleiro[i][j].dificuldade == 2){
                printf(BG_BLACK(TAB_VER BOLD(YELLOW(" %c "))), tabuleiro[i][j].caractere);
            }
            else if(escolha == 2 && tabuleiro[i][j].dificuldade == 3){
                printf(BG_BLACK(TAB_VER BOLD(RED(" %c "))), tabuleiro[i][j].caractere);
            }
    
            else
                printf(BG_BLACK(TAB_VER " %c "), tabuleiro[i][j].caractere);
        }  
        printf(BG_BLACK(TAB_VER));

        if(i != tamLin - 1){     

            printf("\n");

            printf(BG_BLACK(TAB_ML));

            for (int i = 0; i < tamCol; i++)
                printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MJ));

            printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_MR));    
        }

        printf("\n");
        
    } 


    //----------------------------------------------------------------------

    printf(BG_BLACK(TAB_BL));
    for (int i = 0; i < tamCol+1; i++){
        if(i != tamCol)
            printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_BJ));
    }
    printf(BG_BLACK(TAB_HOR TAB_HOR TAB_HOR TAB_BR) "\n");


}