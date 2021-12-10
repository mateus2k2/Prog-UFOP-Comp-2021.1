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

typedef struct{
    char nome[50];
    double salario;
    int DiaPagamento;
    char funcao[20];
}Funcionario;

int main(int argc, char *argv[ ]){
    int n;
    Funcionario *funcionarios;
    FILE *binEscrever = fopen("matrizes", "wb");

    printf("Digite o numero de funcionarios a serem lidos: "); scanf("%i", &n);
    while ((getchar()) != '\n');

    funcionarios = malloc(n * sizeof(Funcionario));

    printf("\nLEITURA\n");
    for (int i = 0; i < n; i++){
        printf("\nFUNCIONARIO: %i\n", i+1);

        printf("Nome: "); fgets(funcionarios[i].nome, 50, stdin);
        funcionarios[i].nome[strlen(funcionarios[i].nome)-1] = '\0';

        printf("Salario: "); scanf("%lf", &funcionarios[i].salario);
        printf("Dia de Pagamento: "); scanf("%i", &funcionarios[i].DiaPagamento);

        while ((getchar()) != '\n');

        printf("Funcao: "); fgets(funcionarios[i].funcao, 20, stdin);
        funcionarios[i].funcao[strlen(funcionarios[i].funcao)-1] = '\0';

        fwrite(&funcionarios[i], sizeof(Funcionario), 1, binEscrever);
    }

    char tempNome[50], tempFuncao[20];
    double tmpSalario;
    int tmpDiaPagamento; 


    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++){
            if(strcmp(funcionarios[i].nome, funcionarios[j].nome) > 0){
                strcpy(tempNome, funcionarios[i].nome);
                strcpy(funcionarios[i].nome, funcionarios[j].nome);
                strcpy(funcionarios[j].nome, tempNome);

                strcpy(tempFuncao, funcionarios[i].funcao);
                strcpy(funcionarios[i].funcao, funcionarios[j].funcao);
                strcpy(funcionarios[j].funcao, tempFuncao);

                tmpSalario = funcionarios[i].salario;
                funcionarios[i].salario = funcionarios[j].salario;
                funcionarios[j].salario = tmpSalario;

                tmpDiaPagamento = funcionarios[i].DiaPagamento;
                funcionarios[i].DiaPagamento = funcionarios[j].DiaPagamento;
                funcionarios[j].DiaPagamento = tmpDiaPagamento;

        }
    }
    fclose(binEscrever);

    binEscrever = fopen("matrizes", "wb");
    for (int i = 0; i < n; i++)
        fwrite(&funcionarios[i], sizeof(Funcionario), 1, binEscrever);
    fclose(binEscrever);


    FILE *binLer = fopen("matrizes", "rb");

    printf("\nPRINT\n");
    for (int i = 0; i < n; i++){
        printf("\nFUNCIONARIO: %i", i+1);

        fread(&funcionarios[i], sizeof(Funcionario), 1, binEscrever);

        printf("\nNome: %s", funcionarios[i].nome);
        printf("\nSalario: %lf", funcionarios[i].salario); 
        printf("\nDia de Pagamento: %i", funcionarios[i].DiaPagamento); 
        printf("\nFuncao: %s\n", funcionarios[i].funcao); 

    }

    fclose(binLer);

    return 0;
}