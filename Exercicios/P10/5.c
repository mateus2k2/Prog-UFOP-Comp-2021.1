//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <stdio.h>
#include <string.h>
#define MAX 256

int main() {
    int num;
    double doub;
    char ch, src[MAX], tgt[MAX];

    double tmpNota;
    int tmpFreq;
    char aprovados[50][100];

    double mediaNota = 0, mediaFreq = 0, percentAprov = 0;
    int quantidade;

    FILE *fp1, *fp2;

    // printf("Digite o nome do arquivo de entrada:"); scanf("%s", src);
    // printf("Digite o nome do arquivo de saida:"); scanf("%s", tgt);

    fp1 = fopen("file.txt", "r");

    if(!fp1) {
        printf("Erro ao abrir arquivo!!\n");
        return 0;
    }

    fp2 = fopen("file.dat", "wb");

    if(!fp2){
        printf("Erro ao abrir arquivo!!\n");
        return 0;
    }

    fscanf(fp1, "%i\n", &num);
    printf("\nnum: %i\n", num);

    fwrite(&num, sizeof(int), 1, fp2);

    quantidade = num;

    for (int i = 0, j = 0; i < quantidade; i++, j++){
        fseek(fp1, 1, SEEK_CUR);

        fgets(aprovados[j], 100, fp1);
        aprovados[j][strlen(aprovados[j])-1] = '\0';
        fwrite(&aprovados[j], sizeof(char), 100, fp2);
        // puts(aprovados[j]);

        fscanf(fp1, "%lf", &tmpNota);
        fwrite(&tmpNota, sizeof(double), 1, fp2);
        // printf("\ntmpNota: %lf", tmpNota);
        
        fscanf(fp1, "%i", &tmpFreq);
        fwrite(&tmpFreq, sizeof(int), 1, fp2);
        // printf("\ntmpFreq: %i\n", tmpFreq);
    }

    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 100; j++)
            aprovados[i][j] = '-';

    tmpFreq = 0;
    tmpNota = 0; 

    for (int i = 0, j = 0; i < quantidade; i++){
        fseek(fp2, 1, SEEK_CUR);

        fread(&aprovados[i], sizeof(char), 100, fp2);
        puts(aprovados[i]);

        fread(&tmpNota, sizeof(double), 1, fp2);
        mediaNota = tmpNota + mediaNota;
        printf("\nmediaNota: %lf", mediaNota);
        
        fread(&tmpFreq, sizeof(int), 1, fp2);
        mediaFreq = tmpFreq + mediaFreq;
        printf("\nmediaFreq: %lf\n", mediaFreq);

        // if(tmpNota < 60 && tmpFreq < 15){ 
        //     aprovados[j][0] = '\0';
        // }
        // else{
        //     j++;
        //     percentAprov++;
        // }
        
    }

    // mediaNota = mediaNota/quantidade;
    // mediaFreq = mediaFreq/quantidade;
    // percentAprov = (percentAprov/quantidade) * 100;

    // printf("\nNota media: %.2lf", mediaNota);
    // printf("\nFrequencia media: %.2lf", mediaFreq);
    // printf("\nPercentual de aprovacao: %.0lf%c \n", percentAprov, '%');


    // printf("\nNomes dos alunos com nota acima da nota media:");
    // for (int i = 0; i < quantidade; i++){
    //     if(aprovados[i][0] != '\0')
    //         printf("\nNome: %s", aprovados[i]);
    // }

    printf("\n");

    fclose(fp1);
    fclose(fp2);
    return 0;
}
