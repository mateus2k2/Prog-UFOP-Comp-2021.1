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

typedef struct{
    char nome[100];
    double nota;
    int frequencia;
}Aluno;


int main(int argc, char *argv[]){
    Aluno alunos[100];
    int quantidade;

    FILE *arquivo = fopen("file.txt", "w");

    printf("Digite a quantidade de alunos: "); scanf("%i", &quantidade);
    fprintf(arquivo, "%i\n", quantidade);
    while ((getchar()) != '\n');


    for (int i = 0; i < quantidade; i++){
        printf("\nAluno %i\n", i+1);

        printf("Nome: "); fgets(alunos[i].nome, 100, stdin);
        alunos[i].nome[strlen(alunos[i].nome)-1] = '\0';
        fprintf(arquivo, "%s\n", alunos[i].nome);

        printf("Nota: "); scanf("%lf", &alunos[i].nota); 
        fprintf(arquivo, "%lf\n", alunos[i].nota);

        printf("Frequencia: "); scanf("%i", &alunos[i].frequencia); 
        fprintf(arquivo, "%i\n", alunos[i].frequencia);
        
        while ((getchar()) != '\n');
       
    }

    fclose(arquivo);
    

    return 0;
}