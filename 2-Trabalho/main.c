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

void alocaMat(char*** mat, int lin, int col);
void liberaMat(char*** mat, int n);

void menu();
void criarJogo();
void colocaPalavra();

typedef struct{
    char *palavra;
    char cordenada[5];
    int marcado;
}Palavra;

int main(int argc, char *argv[ ]){
    time_t t;   
    srand((unsigned) time(&t));

    printf("Bem vindo ao Caca Palavras");
    menu();

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
    while (1){
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
    char **tabuleiro;
    Palavra *palavras;

    int tamLin, tamCol, quantidade, dificuldade;
    int escolhaDirecao, escolhaColocar, escolhaLetra;

    //---------------------------------------------------------------------------------------------
    
    printf("\nAbrindo \"dicionario.txt\"...");
    FILE *dicionario = fopen("dicionario.txt", "r");
    //Mostar erro se caso nao conseguir abrir o arquivo e perguntar se quer sair do jogo

    fscanf(dicionario, "%i %i", &tamLin, &tamCol);
    tabuleiro = (char**)malloc(tamLin*sizeof(char*));
    for(int i = 0; i < tamLin; i++)
        (tabuleiro)[i] = (char*)malloc(tamCol*sizeof(char));

    fscanf(dicionario, "%i", &quantidade);
    palavras = malloc(quantidade * sizeof(Palavra));
    
    //---------------------------------------------------------------------------------------------

    printf("\nDigite o nivel de dificuldade:\n");

    printf("\n1.  Facil");
    printf("\n2.  Medio");
    printf("\n3.  Dificil\n\n");

    printf("Escolha a opcao: ");
    while (dificuldade != 1 && dificuldade != 2 && dificuldade != 3){
        scanf("%i", &dificuldade);
        switch (dificuldade){
        case 1:
            dificuldade = 1; break;
        case 2:
            dificuldade = 2; break;
        case 3:
            dificuldade = 3; break;
        default: printf("Opcao Invalida. Tente Novamente: ");
            break;
        }
    }

    //---------------------------------------------------------------------------------------------

    for (int i = 0; i > tamLin; i++){
        for (int j = 0; j < tamCol; j++){
            if(dificuldade == 1){
                escolhaColocar = rand() % (3);
                escolhaDirecao = rand() % (3);
                escolhaLetra = rand() % (3);
            }

            else if(dificuldade == 2){
                
            }

            else{
                
            }
        
        }       
    }   
}

void colocaPalavra(){
    
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