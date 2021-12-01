//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

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


int main(int argc, char *argv[ ]){
    double mediaNota = 0, mediaFreq = 0, percentAprov = 0;
    int quantidade;
    char nomeAquivo[100];

    printf("Digite o nome do arquivo: "); fgets(nomeAquivo, 100, stdin);
    nomeAquivo[strlen(nomeAquivo)-1] = '\0';
    FILE *arquivo = fopen(nomeAquivo, "r");

    fscanf(arquivo, "%i", &quantidade);

    double tmpNota;
    int tmpFreq;
    char aprovados[50][100];
    for (int i = 0, j = 0; i < quantidade; i++){
        fseek(arquivo, 1, SEEK_CUR);

        fgets(aprovados[i], 100, arquivo);
        aprovados[i][strlen(aprovados[i])-1] = '\0';

        fscanf(arquivo, "%lf", &tmpNota);
        mediaNota = tmpNota + mediaNota;
        
        fscanf(arquivo, "%i", &tmpFreq);
        mediaFreq = tmpFreq + mediaFreq;

        if(tmpNota >= 60 && tmpFreq >= 15){ 
            percentAprov++;
        }
        
    }

    mediaNota = mediaNota/quantidade;
    mediaFreq = mediaFreq/quantidade;
    percentAprov = (percentAprov/(double)quantidade) * 100.0;

    printf("\nNota media: %.2lf", mediaNota);
    printf("\nFrequencia media: %.2lf", mediaFreq);
    printf("\nPercentual de aprovacao: %.2f%c \n", percentAprov, '%');

    fclose(arquivo);
    arquivo = fopen(nomeAquivo, "r");

    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 100; j++)
            aprovados[i][j] = '\0';

    tmpFreq = 0;
    tmpNota = 0; 

    fscanf(arquivo, "%i", &quantidade);

    for (int i = 0, j = 0; i < quantidade; i++){
        fseek(arquivo, 1, SEEK_CUR);

        fgets(aprovados[j], 100, arquivo);
        aprovados[j][strlen(aprovados[j])-1] = '\0';

        fscanf(arquivo, "%lf", &tmpNota);
        
        fscanf(arquivo, "%i", &tmpFreq);

        if(tmpNota < mediaNota){ 
            aprovados[j][0] = '\0';
        }
        else{
            j++;
        }   
    }

    printf("\nNomes dos alunos com nota acima da nota media:");
    for (int i = 0; i < quantidade; i++){
        if(aprovados[i][0] != '\0')
            printf("\nNome: %s", aprovados[i]);
    }

    printf("\n");

    fclose(arquivo);

    return 0;
}