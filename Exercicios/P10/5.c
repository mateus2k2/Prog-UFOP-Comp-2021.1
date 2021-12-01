//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <stdio.h>
#include <string.h>

int main() {
    char arquivoTxt[50], arquivoDat[50], datName[5] = ".dat\0";

    double tmpNota;
    int tmpFreq;
    char maiorMedia[50][100];

    double mediaNota = 0, mediaFreq = 0, percentAprov = 0;
    int quantidade;

    FILE *texto, *dat;

    //Lendo nome do arquivo
    printf("Digite o nome do arquivo texto: "); fgets(arquivoTxt, 100, stdin);
    arquivoTxt[strlen(arquivoTxt)-1] = '\0';


    //Copiando e gerando o nome do arquivo .dat
    for (int i = 0, j = 0; i < strlen(arquivoTxt)+1; i++){
        if(i < strlen(arquivoTxt)-4)
            arquivoDat[i] = arquivoTxt[i];
        else{
            arquivoDat[i] = datName[j];
            j++;
        }         
    }   

    //Abrindo os arquivos e monstando erro caso não abra
    //O .dat oara escrita e o de .txt para leitura
    texto = fopen(arquivoTxt, "r");

    if(!texto) {
        printf("Erro ao abrir arquivo!!\n"); return 0;
    }

    dat = fopen(arquivoDat, "wb");

    if(!dat){
        printf("Erro ao abrir arquivo!!\n"); return 0;
    }

    //Lendo e escrevendo primeira linha do arquivo de texto referente a quantidade de alunos que se espera 
    fscanf(texto, "%i", &quantidade);
    fwrite(&quantidade, sizeof(int), 1, dat);

    //Convertendo do arquivo texto para o arquivo binario
    for (int i = 0, j = 0; i < quantidade; i++, j++){
        fseek(texto, 1, SEEK_CUR);

        fgets(maiorMedia[i], 100, texto);
        fwrite(&maiorMedia[i], sizeof(char), 100, dat);
        maiorMedia[i][strlen(maiorMedia[i])-1] = '\0';

        fscanf(texto, "%lf", &tmpNota);
        fwrite(&tmpNota, sizeof(double), 1, dat);
        
        fscanf(texto, "%i", &tmpFreq);
        fwrite(&tmpFreq, sizeof(int), 1, dat);

    }

    //'Limpando' as variaveis tmp e a string de alunos com nota maior que media
    //Mais para teste doque algum motivo prático 
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 100; j++)
            maiorMedia[i][j] = '-';
    tmpFreq = 0;
    tmpNota = 0; 

    //Fechando o arquivo dat e abrindo de novo para leitura
    fclose(dat);
    dat = fopen(arquivoDat, "rb");
    fread(&quantidade, sizeof(int), 1, dat);
    
    //Agora percorrendo o arquivo .dat para ler as informações e armazena-las
    for (int i = 0, j = 0; i < quantidade; i++){

        fread(&maiorMedia[i], sizeof(char), 100, dat);

        fread(&tmpNota, sizeof(double), 1, dat);
        mediaNota = tmpNota + mediaNota;
        
        fread(&tmpFreq, sizeof(int), 1, dat);
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

    //Fechando o arquivo dat e abrindo de novo para leitura para percorre-lo novamente
    fclose(dat);
    dat = fopen(arquivoDat, "rb");
    fread(&quantidade, sizeof(int), 1, dat);

    //'Limpando' as variaveis tmp e a string de de alunos com nota maior que media
    //Mais para teste doque algum motivo prático 
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 100; j++)
            maiorMedia[i][j] = '\0';
    tmpFreq = 0;
    tmpNota = 0; 

    //Lendo o arquivo .dat Agora para determinar os alunos com nota mior que a media
    for (int i = 0, j = 0; i < quantidade; i++){

        fread(&maiorMedia[j], sizeof(char), 100, dat);
        maiorMedia[j][strlen(maiorMedia[j])-1] = '\0';

        fread(&tmpNota, sizeof(double), 1, dat);
                
        fread(&tmpFreq, sizeof(int), 1, dat);
        
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

    fclose(texto);
    fclose(dat);

    return 0;
}
