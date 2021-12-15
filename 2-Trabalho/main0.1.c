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

typedef struct{
    char palavra[100];
    int marcado;
    int linC, colC;
    int linF, colF
}Palavra;

typedef struct{
    char caractere;
    int fazPartePalavra;
}Item;

//Marcar os itens preenchidos por palavra como fazPartePalavra;
//Caso uma posicão fassa parte palavra verificar se e a mesma letra caso nao for não contar nos marcados e pular 

void alocaMat(char*** mat, int lin, int col);
void liberaMat(char*** mat, int n);

void menu();
void criarJogo();
void colocaPalavra(int escolhaDirecao, int *contColocadas, int lim, int col, int tamLin, int tamCol, Palavra *palavras ,Item **tabuleiro);
void verificaEscolha();
void resolveTabuleiro();
void continuaJogo();
void converterCoordenada();



//Mostar erro se caso nao conseguir abrir o arquivo e perguntar se quer sair do jogo
//Mostar erro se caso nao conseguir fazer malloc
//Erro caso palavra seja impossivel de caber no tabuleiro
//Não chegando na ultima palavra
//Caso de palavras se interceptando em lugares indevidos
//Converteer minusculo maiusculo

//Qual o tamanho maximo das palavras
//Palavras podem ter espaço?

//if strlem(palavras[contColocadas].palavra) > Maior espaco disponivel no tabuleiro
//printf palavra é muito grande para o tabuleiro
//contColocadas++; 

//no semicolon at end of struct or union in c


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
    int tamLin, tamCol, quantidade, dificuldade;
    int escolhaDirecao = 0, escolhaColocar, escolhaLetra, contColocadas = 0;

    //---------------------------------------------------------------------------------------------
    
    printf("\nAbrindo \"dicionario.txt\"...");
    FILE *dicionario = fopen("dicionario.txt", "r");
    //Mostar erro se caso nao conseguir abrir o arquivo e perguntar se quer sair do jogo

    fscanf(dicionario, "%i %i", &tamLin, &tamCol);
    tabuleiro = (Item**)malloc(tamLin*sizeof(Item*));
    for(int i = 0; i < tamLin; i++)
        (tabuleiro)[i] = (Item*)malloc(tamCol*sizeof(Item));

    fscanf(dicionario, "%i", &quantidade);
    palavras = malloc(quantidade * sizeof(Palavra));
    //quantidade = quantidade + 1;
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

    //---------------------------------------------------------------------------------------------
   
    //Qual o tamanho maximo das palavras
    //Palavras podem ter espaço?
    fgets(lixo, 100, dicionario);
    for (int i = 0; i < quantidade; i++){
        fgets(palavras[i].palavra, 100, dicionario);

        if(i != quantidade-1){
            palavras[i].palavra[strlen(palavras[i].palavra)-1] = '\0';
        }
    } 

    // for (int i = 0; i < quantidade; i++){
    //     for (int j = 0; j < strlen(palavras[i].palavra); j++){
    //         palavras[i].palavra[j] = palavras[i].palavra[j] - 32;
    //         printf("%c ", palavras[i].palavra[j]);   
    //     }        
    //     printf("\n"); 
    // } 

    // pause();

    //---------------------------------------------------------------------------------------------

    while (1){
       
        for (int i = 0; i < tamLin; i++){
            for (int j = 0; j < tamCol; j++){
                escolhaLetra = rand() % (26);
                tabuleiro[i][j].caractere = escolhaLetra + 'A';
                tabuleiro[i][j].fazPartePalavra == 0;
            }       
        }


        for (int i = 0; i < tamLin; i++){
            for (int j = 0; j < tamCol; j++){
                
                //Dificuldade 1
                if(dificuldade == 1){
                    escolhaDirecao = rand() % (2);
                    escolhaColocar = rand() % (100);

                    if(contColocadas != quantidade && escolhaColocar >= 90){
                        colocaPalavra(escolhaDirecao, &contColocadas, i, j, tamLin, tamCol, palavras, tabuleiro);
                    }

                }

                //Dificuldade 2
                else if(dificuldade == 2){
                  
                }

                //Dificuldade 3
                else{
                   
                }

                if(quantidade == contColocadas)
                    break;
            }
            if(quantidade == contColocadas)
                break;       
        }

        if(quantidade == contColocadas)
            break; 
        else
            contColocadas = 0;
        
    }

    
    //---------------------------------------------------------------------------------------------
    

    printf("\n");        
    for (int i = 0; i < tamLin; i++){
        for (int j = 0; j < tamCol; j++){
            printf("%c ", tabuleiro[i][j].caractere);        
        }       
        printf("\n");        

    } 

}

void colocaPalavra(int escolhaDirecao, int *contColocadas, int lim, int col, int tamLin, int tamCol, Palavra *palavras ,Item **tabuleiro){
    int aprovado = 0;

    printf("\n");        
    for (int i = 0; i < tamLin; i++){
        for (int j = 0; j < tamCol; j++){
            printf("%c ", (tabuleiro)[i][j].caractere);      
        }       
        printf("\n");      
    } 


    //-----------------------------------------------------------------------------------------------------
    if(escolhaDirecao == 0 && col + strlen(palavras[(*contColocadas)].palavra) <= tamCol){
        puts(palavras[(*contColocadas)].palavra);

        for (int i = col, j = 0; j < strlen(palavras[(*contColocadas)].palavra); i++, j++){
            if(tabuleiro[lim][i].fazPartePalavra == 0){
                aprovado = 1;
            }
            else{ 
                aprovado = 0;
                break;
            }
        }

        if(aprovado == 1){
            for (int i = col, j = 0; j < strlen(palavras[(*contColocadas)].palavra); i++, j++){
                if(tabuleiro[lim][i].fazPartePalavra == 0){
                    tabuleiro[lim][i].caractere = palavras[(*contColocadas)].palavra[j];     
                    tabuleiro[lim][i].fazPartePalavra = 1;
                }
                else 
                    break;
                if(j == strlen(palavras[(*contColocadas)].palavra) - 1)
                    (*contColocadas)++;
            }
        }
        aprovado = 0;
    }

    //-----------------------------------------------------------------------------------------------------

    else if(escolhaDirecao == 1 && lim + strlen(palavras[(*contColocadas)].palavra) <= tamLin){
        puts(palavras[(*contColocadas)].palavra);

        for (int i = lim, j = 0; j < strlen(palavras[(*contColocadas)].palavra); i++, j++){
            if(tabuleiro[i][col].fazPartePalavra == 0){
                aprovado = 1;
            }
            else{ 
                aprovado = 0;
                break;
            }
        }

        if(aprovado = 1){
            for (int i = lim, j = 0; j < strlen(palavras[(*contColocadas)].palavra); i++, j++){
                if(tabuleiro[i][col].fazPartePalavra == 0){
                    tabuleiro[i][col].caractere = palavras[(*contColocadas)].palavra[j];
                    tabuleiro[lim][i].fazPartePalavra = 1;
                }
                else 
                    break;
                if(j == strlen(palavras[(*contColocadas)].palavra) - 1)
                    (*contColocadas)++;
            }
        }
        aprovado = 0;
    }

    //-----------------------------------------------------------------------------------------------------

    else if(escolhaDirecao == 2){
        
    }

    //-----------------------------------------------------------------------------------------------------

    else if(escolhaDirecao == 3){
        
    }

    //-----------------------------------------------------------------------------------------------------

    else if(escolhaDirecao == 4){
        
    }

    //-----------------------------------------------------------------------------------------------------

    else if(escolhaDirecao == 5){
        
    }

    //-----------------------------------------------------------------------------------------------------

    else if(escolhaDirecao == 6){
        
    }

    //-----------------------------------------------------------------------------------------------------

    else{
        
    }

    //(*contColocadas) = (*contColocadas) - 1;

}


void alocaMat(char*** mat, int lin, int col){
    int i;
    *mat = (char**)malloc(lin*sizeof(char*));
    for( i=0; i<lin; i++)
        (*mat)[i] = (char*)malloc(col*sizeof(char));

    //Verificar e retornar erro se nao alocou direito
} 

void liberaMat(char*** mat, int lin){
    int i;
    for (i = 0; i < lin; i++)
        free((*mat)[i]);
    free(*mat); 
}