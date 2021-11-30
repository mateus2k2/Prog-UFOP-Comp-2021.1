//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <stdio.h>
#include <string.h>
#define MAX 256

int main() {
    int num;
    FILE *fp1, *fp2;
    char ch, src[MAX], tgt[MAX];

    printf("Digite o nome do arquivo de entrada:"); scanf("%s", src);
    printf("Digite o nome do arquivo de saida:"); scanf("%s", tgt);

    fp1 = fopen(src, "r");

    if(!fp1) {
        printf("Erro ao abrir arquivo!!\n");
        return 0;
    }

    fp2 = fopen(tgt, "wb");

    if(!fp2){
        printf("Erro ao abrir arquivo!!\n");
        return 0;
    }
  
    while(!feof(fp1)) {
        fread(&ch, sizeof(char), 1, fp1);
        num = ch;
        fwrite(&num, sizeof(int), 1, fp2);
    }

    double tmpNota;
    int tmpFreq;
    char aprovados[50][100];

    double mediaNota = 0, mediaFreq = 0, percentAprov = 0;
    int quantidade;
    char nomeAquivo[100];

    fread(&quantidade, sizeof(int), 1, fp2);

    for (int i = 0, j = 0; i < quantidade; i++){
        fseek(fp2, 1, SEEK_CUR);
        fread(&aprovados[j], sizeof(char), 100, fp2);
        aprovados[j][strlen(aprovados[j])-1] = '\0';

        fread(&tmpNota, sizeof(double), 1, fp2);
        mediaNota = tmpNota + mediaNota;
        
        fread(&tmpFreq, sizeof(int), 1, fp2);
        mediaFreq = tmpFreq + mediaFreq;

        if(tmpNota < 60 && tmpFreq < 15){ 
            aprovados[j][0] = '\0';
        }
        else{
            j++;
            percentAprov++;
        }
        
    }

    mediaNota = mediaNota/quantidade;
    mediaFreq = mediaFreq/quantidade;
    percentAprov = (percentAprov/quantidade) * 100;

    printf("\nNota media: %.2lf", mediaNota);
    printf("\nFrequencia media: %.2lf", mediaFreq);
    printf("\nPercentual de aprovacao: %.0lf%c \n", percentAprov, '%');


    printf("\nNomes dos alunos com nota acima da nota media:");
    for (int i = 0; i < quantidade; i++){
        if(aprovados[i][0] != '\0')
            printf("\nNome: %s", aprovados[i]);
    }

    printf("\n");

    fclose(fp1);
    fclose(fp2);
    return 0;
}
