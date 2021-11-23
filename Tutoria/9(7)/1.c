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

// O cavalo é uma peça menor do xadrez ocidental de um valor aproximado de três peões. Tem um movimento assemelhado a um "L" e, diferente das outras peças, 
// pode pular as peças intervenientes. Captura tomando a casa ocupada pela peça adversária, sendo sempre no final do L.

int main(int argc, char *argv[ ]){
    char posicaoCavalo[2], posicaoRei[2];
    int posicaoCavaloN[2], posicaoReiN[2]; 
    
    printf("Posição inicial do cavaloe (LetraMaiusculaNumero): "); fgets(posicaoCavalo, 2, stdin);
    //Remover \n do final da string
    posicaoCavalo[strlen(posicaoCavalo)-1] = '\0';

    //Remover \n do input do teclado
    while ((getchar()) != '\n');

    printf("Posição inicial do rei (LetraMaiusculaNumero): "); fgets(posicaoRei, 2, stdin);
    //Remover \n do final da string
    posicaoRei[strlen(posicaoRei)-1] = '\0';

    //Remover \n do input do teclado
    while ((getchar()) != '\n');

    for (int i = 0; i < 8; i++){
        if(posicaoCavalo[0] == 'A' + i)
            posicaoCavaloN[0] = i;
        if(posicaoCavalo[1] == 48 + i) 
            posicaoCavaloN[1] = i;
    }   

    for (int i = 0; i < 8; i++){
        if(posicaoRei[0] == 'A' + i)
            posicaoReiN[0] = i;
        if(posicaoRei[1] == 48 + i) 
            posicaoReiN[1] = i;
    }   

    printf("\nPosicao Rei: %i %i\n", posicaoCavaloN[0], posicaoCavaloN[1]);
    printf("\nPosicao Cavalo: %i %i\n", posicaoReiN[0], posicaoReiN[1]);

    

    //Possiveis movimentos do cavalo
    //Pra cada movimento verificar se alcança o rei dessa possição

    //Canto superior esquerdo
    if(posicaoCavalo[1] + '2' <= '8' && posicaoCavalo[0] - '2' >= 'a'){
        //posicaoCavalo[0] - 2 || posicaoCavalo[1] + 2
        //posicaoCavalo[0] + 2 || posicaoCavalo[1] + 2
    }

    //Canto superior direito
    if(posicaoCavalo[1] + '2' <= '8' && posicaoCavalo[0] + '2' <= 'h'){
        //posicaoCavalo[0] - 2 || posicaoCavalo[1] - 2
        //posicaoCavalo[0] + 2 || posicaoCavalo[1] - 2
    }

    //Canto infeiror esquerdo
    if(posicaoCavalo[1] - '2' >= '1' && posicaoCavalo[0] - '2' >= 'a'){
        //posicaoCavalo[0] - 2 || posicaoCavalo[1] - 2
        //posicaoCavalo[0] - 2 || posicaoCavalo[1] + 2
    }

    //Canto inferior direito
    if(posicaoCavalo[1] - '2' >= '1' && posicaoCavalo[0] + '2' <= 'h'){
        //posicaoCavalo[0] + 2 || posicaoCavalo[1] - 2
        //posicaoCavalo[0] + 2 || posicaoCavalo[1] + 2
    } 


    return 0;
}