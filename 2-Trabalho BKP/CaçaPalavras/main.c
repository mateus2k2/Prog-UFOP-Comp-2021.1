//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Headers/cores.h"
#include "Headers/structs.h"

#include "Headers/menus.h"
#include "Headers/criaTabuleiro.h"
#include "Headers/continuarJogo.h"
#include "Headers/jogar.h"
#include "Headers/outros.h"

//CONVENÇÃO DAS DIREÇÕES UTILIZADAS DURANTE O PROGRAMA
//https://imgur.com/a/PiEJwSM
//0 - Horizontal Direita Esquerda 
//1 - Vertical Cima para Baixo
//2 - Diagonal Cima para Baixo Esquerda para Direita
//3 - Diagonal Baixo para Cima Esquerda para Direita
//4 - Vertical Baixo para cima
//5 - Horizontal Esquerda para direita
//6 - Diagonal Baixo para Cima Direita para Esquerda
//7 - Diagonal Cima para Baixo Direita para Esquerda


int main(int argc, char *argv[ ]){
    
    //Gera uma seed aleatória baseada no tempo
    time_t t;   
    srand((unsigned) time(&t));

    //Seta a localização do código para Portuguese do Brasil
    setlocale(LC_ALL,"Portuguese_Brasil");

    printf("Bem vindo ao Caça Palavras");
    //Chama o menu principal
    menu();

    printf("\n");

    return 0;
}

