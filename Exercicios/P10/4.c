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

    double tmpNota;
    int tmpFreq;
    char maiorMedia[50][100];

    //Lendo o nome e abrindo o arquivo
    printf("Digite o nome do arquivo: "); fgets(nomeAquivo, 100, stdin);
    nomeAquivo[strlen(nomeAquivo)-1] = '\0';
    FILE *arquivo = fopen(nomeAquivo, "r");

    //Lendo primeira linha do arquivo de texto referente a quantidade de alunos que se espera 
    fscanf(arquivo, "%i", &quantidade);


    //Agora percorrendo o arquivo .txt para ler as informações e armazena-las
    for (int i = 0, j = 0; i < quantidade; i++){
        fseek(arquivo, 1, SEEK_CUR);

        fgets(maiorMedia[i], 100, arquivo);
        maiorMedia[i][strlen(maiorMedia[i])-1] = '\0';

        fscanf(arquivo, "%lf", &tmpNota);
        mediaNota = tmpNota + mediaNota;
        
        fscanf(arquivo, "%i", &tmpFreq);
        mediaFreq = tmpFreq + mediaFreq;

        //Determiani alunos aprovados com essa condição ja que não faz sentido um aluno ser aprovado por ter nota maior que a media da sala
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

    //fechando e abrindo o arquivo para voltar para o começo
    fclose(arquivo);
    arquivo = fopen(nomeAquivo, "r");

    //'Limpando' as variaveis tmp e a string de alunos com nota maior que media
    //Mais para teste doque algum motivo prático 
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 100; j++)
            maiorMedia[i][j] = '\0';
    tmpFreq = 0;
    tmpNota = 0; 

    //Lendo primeira linha do arquivo de texto referente a quantidade de alunos que se espera 
    fscanf(arquivo, "%i", &quantidade);

    //Lendo o arquivo .dat Agora para determinar os alunos com nota mior que a media
    for (int i = 0, j = 0; i < quantidade; i++){
        fseek(arquivo, 1, SEEK_CUR);

        fgets(maiorMedia[j], 100, arquivo);
        maiorMedia[j][strlen(maiorMedia[j])-1] = '\0';

        fscanf(arquivo, "%lf", &tmpNota);
        
        fscanf(arquivo, "%i", &tmpFreq);

        if(tmpNota < mediaNota){ 
            maiorMedia[j][0] = '\0';
        }
        else{
            j++;
        }   
    }

    printf("\nNomes dos alunos com nota acima da nota media:");
    for (int i = 0; i < quantidade; i++){
        if(maiorMedia[i][0] != '\0')
            printf("\nNome: %s", maiorMedia[i]);
    }

    printf("\n");

    fclose(arquivo);

    return 0;
}