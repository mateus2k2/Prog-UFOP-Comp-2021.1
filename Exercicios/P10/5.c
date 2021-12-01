//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <stdio.h>
#include <string.h>

int main() {
    char arquivoTxt[50], arquivoDat[50], datName[5] = ".dat\0";

    double tmpNota;
    int tmpFreq;
    char aprovados[50][100];

    double mediaNota = 0, mediaFreq = 0, percentAprov = 0;
    int quantidade;

    FILE *texto, *dat;

    printf("Digite o nome do arquivo texto: "); scanf("%s", arquivoTxt);

    for (int i = 0, j = 0; i < strlen(arquivoTxt)+1; i++){
        if(i < strlen(arquivoTxt)-4)
            arquivoDat[i] = arquivoTxt[i];
        else{
            arquivoDat[i] = datName[j];
            j++;
        }         
    }   

    texto = fopen(arquivoTxt, "r");

    if(!texto) {
        printf("Erro ao abrir arquivo!!\n");
        return 0;
    }

    dat = fopen(arquivoDat, "wb");

    if(!dat){
        printf("Erro ao abrir arquivo!!\n");
        return 0;
    }

    fscanf(texto, "%i", &quantidade);
    fwrite(&quantidade, sizeof(int), 1, dat);

    for (int i = 0, j = 0; i < quantidade; i++, j++){
        fseek(texto, 1, SEEK_CUR);

        fgets(aprovados[i], 100, texto);
        fwrite(&aprovados[i], sizeof(char), 100, dat);
        aprovados[i][strlen(aprovados[i])-1] = '\0';

        fscanf(texto, "%lf", &tmpNota);
        fwrite(&tmpNota, sizeof(double), 1, dat);
        
        fscanf(texto, "%i", &tmpFreq);
        fwrite(&tmpFreq, sizeof(int), 1, dat);

    }

    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 100; j++)
            aprovados[i][j] = '-';

    tmpFreq = 0;
    tmpNota = 0; 

    fclose(dat);
    dat = fopen(arquivoDat, "rb");
    fread(&quantidade, sizeof(int), 1, dat);
    
    for (int i = 0, j = 0; i < quantidade; i++){

        fread(&aprovados[i], sizeof(char), 100, dat);

        fread(&tmpNota, sizeof(double), 1, dat);
        mediaNota = tmpNota + mediaNota;
        
        fread(&tmpFreq, sizeof(int), 1, dat);
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

    fclose(dat);
    dat = fopen(arquivoDat, "rb");
    fread(&quantidade, sizeof(int), 1, dat);

    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 100; j++)
            aprovados[i][j] = '\0';

    tmpFreq = 0;
    tmpNota = 0; 

    for (int i = 0, j = 0; i < quantidade; i++){

        fread(&aprovados[j], sizeof(char), 100, dat);
        aprovados[j][strlen(aprovados[j])-1] = '\0';

        fread(&tmpNota, sizeof(double), 1, dat);
                
        fread(&tmpFreq, sizeof(int), 1, dat);
        
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

    fclose(texto);
    fclose(dat);

    return 0;
}
