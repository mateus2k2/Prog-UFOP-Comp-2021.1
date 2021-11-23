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


int verifica(char tabuleiro[3][3]){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
        }
    }
    if(tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X' )
        return 0;
    if(tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X' )
        return 0;
    if(tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X' )
        return 0;
    if(tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X' )
        return 0;
    if(tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X' )
        return 0;
    if(tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X' )
        return 0;
    if(tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X' )
        return 0;
    if(tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X' )
        return 0;
    if(tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X' )
        return 0;

    if(tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O' )
        return 1;
    if(tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O' )
        return 1;
    if(tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O' )
        return 1;
    if(tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O' )
        return 1;
    if(tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O' )
        return 1;
    if(tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O' )
        return 1;
    if(tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O' )
        return 1;
    if(tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O' )
        return 1;
    if(tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O' )
        return 1;

    return 2;
}

int main(int argc, char *argv[ ]){
    int escolhaMP, escolhaBI;

    printf("Jogar com a maquina(1) ou com outro jogador(0): ");
    while (escolhaMP != 1 && escolhaMP != 0){
        scanf("%i", &escolhaMP);

        if(escolhaMP != 1 && escolhaMP != 0)
            printf("Erro. Tente Novament: "); 
    }               

    if(escolhaMP == 1){
        printf("Jogar com a maquina intelogente(1) ou com maquina aleatoria(0): ");
        while (escolhaBI != 1 && escolhaBI != 0){
            scanf("%i", &escolhaBI);

            if(escolhaBI != 1 && escolhaBI != 0)
                printf("Erro. Tente Novament: "); 
        }
    }

    printf("\n\n");

    //Jogo com outro jogador
    int linha, coluna, inverte = 2, cont = 0, continua = 1;
    char jogador = 'X';
    char tabuleiro[3][3];
    

    //Jogo com maquina aleatorio ------------------------------------------------------------------------------------------------------------------------------------------------------------
    if(escolhaMP == 0){

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                tabuleiro[i][j] = '-';
                printf(" %c ", tabuleiro[i][j]);
            }
            printf("\n");
        }
        
        while (1){
            printf("Jogador %c. Digite a linha e coluna: ", jogador);
            scanf("%i %i", &linha, &coluna);   
            while (linha > 3 || coluna > 3 || coluna < 1 || linha < 1 || tabuleiro[linha-1][coluna-1] == 'X' || tabuleiro[linha-1][coluna-1] == 'O'){   
                if(linha > 3 || coluna > 3 || coluna < 1 || linha < 1 || tabuleiro[linha-1][coluna-1] == 'X' || tabuleiro[linha-1][coluna-1] == 'O')
                    printf("Espaco ocupado ou numero invalido. Tente novamente: ");
                scanf("%i %i", &linha, &coluna);            
            }
            linha = linha - 1;
            coluna = coluna - 1;

            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if(i == linha && j == coluna){
                        tabuleiro[i][j] = jogador;
                        printf(" %c ", tabuleiro[i][j]);
                    }
                    else if(tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O'){
                        tabuleiro[i][j] = '-';
                        printf(" %c ", tabuleiro[i][j]);
                    }
                    else
                        printf(" %c ", tabuleiro[i][j]);       

                }
                printf("\n");      
            } 
            
            //Verificar vitoria, derrato, velha

            if(verifica(tabuleiro) == 0){
                printf("\nX Ganhou\n"); break;
            }
            if(verifica(tabuleiro) == 1){
                printf("\nO Ganhou\n"); break;
            }
            if(cont == 9){
                printf("\nDeu velha\n"); break;
            }

            if(inverte % 2 == 0)
                jogador = 'O';
            else
                jogador = 'X';
            
            inverte++;
            cont++;      

        }
    }
        //Jogo com maquina aleatorio ------------------------------------------------------------------------------------------------------------------------------------------------------------

    time_t t;   
    srand((unsigned) time(&t));

    int aleatorio;
    if(escolhaMP == 1 && escolhaBI == 0){

        printf("\nVoce e o jogar X\n");

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                tabuleiro[i][j] = '-';
                printf(" %c ", tabuleiro[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        
        while (1){
            if(inverte % 2 == 0){
                printf("Jogador X. Digite a linha e coluna: ");
                scanf("%i %i", &linha, &coluna);   
                while (linha > 3 || coluna > 3 || coluna < 1 || linha < 1 || tabuleiro[linha-1][coluna-1] == 'X' || tabuleiro[linha-1][coluna-1] == 'O'){   
                    if(linha > 3 || coluna > 3 || coluna < 1 || linha < 1 || tabuleiro[linha-1][coluna-1] == 'X' || tabuleiro[linha-1][coluna-1] == 'O')
                        printf("Espaco ocupado ou numero invalido. Tente novamente: ");
                    scanf("%i %i", &linha, &coluna);            
                }
            linha = linha - 1;
            coluna = coluna - 1;
            }

            if(inverte % 2 != 0){
                linha = rand() % (3);
                coluna = rand() % (3);
                while (linha > 3 || coluna > 3 || coluna < 1 || linha < 1 || tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O'){   
                    if(linha > 3 || coluna > 3 || coluna < 1 || linha < 1 || tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O'){
                        linha = rand() % (3);
                        coluna = rand() % (3);
                    }
                }
                printf("\nEscolha da maquina O (aleatoria): linha %i coluna %i\n", linha+1, coluna+1);
            }


       

            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if(i == linha && j == coluna){
                        tabuleiro[i][j] = jogador;
                        printf(" %c ", tabuleiro[i][j]);
                    }
                    else if(tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O'){
                        tabuleiro[i][j] = '-';
                        printf(" %c ", tabuleiro[i][j]);
                    }
                    else
                        printf(" %c ", tabuleiro[i][j]);       

                }
                printf("\n");      
            } 
            printf("\n");      

            
            //Verificar vitoria, derrato, velha

            if(verifica(tabuleiro) == 0){
                printf("\nX Ganhou\n"); break;
            }
            if(verifica(tabuleiro) == 1){
                printf("\nO Ganhou\n"); break;
            }
            if(cont == 9){
                printf("\nDeu velha\n"); break;
            }

            if(inverte % 2 == 0)
                jogador = 'O';
            else
                jogador = 'X';
            
            inverte++;
            cont++;      

        }


    }
    
    //jogo com maquina inteligente


    return 0;

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int pc_joga(){

    int x,y,mx,my;
    int k,j,i;
    int erro=0;

    char tabuleiro[3][3];
    char tabuleiroa[3][3];

    x=(rand()%3);
    y=(rand()%3);

    if(tabuleiro[x][y]!=' '){
        pc_joga();
        return(1);
    }
    else{

      /*
O Computador gerará 2 números aleatórios X e Y.
E verificará se as coordenadas do ponto (X,Y) estão livre.
Se estiverem livres (tabuleiro[x][y]==' ') então ele criará um
"backup" da tabuleiro original, e vai começas a jogar em cima delas.
      */
         for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                tabuleiroa[i][j]=tabuleiro[i][j];


        for(i=0;i<3;i++)
            for(j=0;j<3;j++){
                if (tabuleiro[i][j]==' '){
      /*Neste primeiro trecho de codigo, o computador
       já criou uma nova tabuleiro. Aqui, ele marca O num ponto
      qualquer e depois verifica se com este ponto ele consegue ganhar o jogo*/
      
        tabuleiro[i][j]='O';
        if((checar()!=0)){
            mx=i;
            my=j;
            erro=2;
        }
        else{
        /*
        Caso o computador não possa marcar zero neste ponto, ele
        fará o teste para ver se o jogador pode ganhar o jogo. Caso ele consiga vencer o jogo, o computador
        marca esta posição para evitar a vitória adversária.

        Logicamente, a varável erro é verificada como diferente de 2. Pois caso o computador ache
        um ponto onde ele possa ganhar, não vale a pena ele procurar outro para evitar a vitória adversária.
        */
            tabuleiro[i][j]='X';
                if((checar()!=0)&&(erro!=2)){
                    mx=i;
                    my=j;
                    erro=1;
                }
            }

            tabuleiro[i][j]=' ';
        }
    }

        //Restaura tabuleiro 
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                tabuleiro[i][j]=tabuleiroa[i][j];
      
        if (erro==0)
            tabuleiro[x][y]='O';
        if (erro!=0)
            tabuleiro[mx][my]='O';
    }
}