// Crie uma estrutura representando os alunos do curso de Algoritmos. A estrutura deve conter a matrícula do aluno, nome e notas dos 3 TVCs. Faça:

// a)Leitura de dados de 5 alunos. 
// b)Encontre o aluno com maior nota da primeira prova. 
// c)Encontre o aluno com maior média geral. 
// d)Encontre o aluno com menor média geral

// Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 60 para aprovação.

#define MAX 2

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float nota1;
    float nota2;
    float nota3;
}notas;

typedef struct{
    char nome[100];
    char matricula[100];
    notas TVC;
}alunos;

int main(){
    alunos turma[MAX];
    float media, mediaMaior = -INFINITY, mediaMenor = INFINITY, maiorNota1 = -INFINITY;
    int indiceMaior, indiceMenor, indiceMairo1;
    int c;

    for (int i = 0; i < MAX; i++){
        printf("\nALUNO %i\n", i+1);

        printf("Digite o nome do aluno: ");
        gets(turma[i].nome);

        printf("Digite a matricula do aluno: ");
        gets(turma[i].matricula);

        printf("Digite as 3 notas no aluno (nota1 nota2 nota 3): ");
        scanf("%f %f %f", &turma[i].TVC.nota1, &turma[i].TVC.nota2, &turma[i].TVC.nota3);

        //Remove the \n from input stream
        while ( (c = getchar()) != '\n' && c != EOF );

        media = (turma[i].TVC.nota1 + turma[i].TVC.nota2 + turma[i].TVC.nota3) / 3;

        if(media >= 60)
            printf("\nAluno %i Aprovado com media %f\n", i+1, media);
        else
            printf("\nAluno %i Reprovado com media %f\n", i+1, media);

        if(media > mediaMaior){
            mediaMaior = media;
            indiceMaior = i;
        }

        if(media < mediaMenor){
            mediaMenor = media;
            indiceMenor = i;
        }

        if(turma[i].TVC.nota1 > maiorNota1){
            maiorNota1 = turma[i].TVC.nota1;
            indiceMairo1 = i;
        }
    
    }

    printf("\nO aluno %s de matricula %s de media %.2f teve menor media", turma[indiceMenor].nome, turma[indiceMenor].matricula, mediaMenor);
    printf("\nO aluno %s de matricula %s de media %.2f teve maior media", turma[indiceMaior].nome, turma[indiceMaior].matricula, mediaMaior);
    printf("\nO aluno %s de matricula %s teve maior nota %.2f na primeira prova", turma[indiceMairo1].nome, turma[indiceMairo1].matricula, maiorNota1);


    
}


