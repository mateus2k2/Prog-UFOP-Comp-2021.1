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
    char nome[30];
    int matricula;
    int frequencia;
    double media;
}Aluno;

typedef struct{
    Aluno alunos[30];
    int controle;
    char qualTurma[30];
}Turma;

void imprimeInfo(Turma turma, int indexMaior, int indexMenor, int reprovadosFreq[], int reprovadosNota[]){

    printf("\nREPROVADO POR FREQUENCIA");
    for (int i = 0; reprovadosFreq[i] != 33; i++){
        printf("\nNome: %s", turma.alunos[reprovadosFreq[i]].nome);
        printf("\nMatricula: %i", turma.alunos[reprovadosFreq[i]].matricula);
        printf("\nMeida: %lf", turma.alunos[reprovadosFreq[i]].media);
        printf("\nFrequencia: %i\n\n", turma.alunos[reprovadosFreq[i]].frequencia);
    }

    printf("\nREPROVADO POR NOTA");
    for (int i = 0; reprovadosNota[i] != 33; i++){
        printf("\nNome: %s", turma.alunos[reprovadosNota[i]].nome);
        printf("\nMatricula: %i", turma.alunos[reprovadosNota[i]].matricula);
        printf("\nMeida: %lf", turma.alunos[reprovadosNota[i]].media);
        printf("\nFrequencia: %i\n\n", turma.alunos[reprovadosNota[i]].frequencia);
    }
}

void fazLeitura(){
    Turma turma;
    double maior = -INFINITY, menor = INFINITY;
    int indexMaior, indexMenor;
    int reprovadosNota[30], reprovadosFreq[30], k = 0, j = 0;
    
    printf("Digite o nome da turma: ");
    fgets(turma.qualTurma, 30, stdin);

    turma.qualTurma[strlen(turma.qualTurma)-1] = '\0';

    printf("Digite a quantidade de Alunos: ");
    scanf("%i", &turma.controle);
    while ((getchar()) != '\n');

    printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < turma.controle; i++){
        printf("\nALUNO %i\n", i+1);

        printf("Nome: "); fgets(turma.alunos[i].nome, 30, stdin);
        turma.alunos[i].nome[strlen(turma.alunos[i].nome)-1] = '\0';


        printf("Matricula: "); scanf("%i", &turma.alunos[i].matricula);
        printf("Media: "); scanf("%lf", &turma.alunos[i].media);
        printf("Frequencia: "); scanf("%i", &turma.alunos[i].frequencia);
        while ((getchar()) != '\n');

        if(turma.alunos[i].media > maior){
            maior = turma.alunos[i].media;
            indexMaior = i;
        }

        if(turma.alunos[i].media < menor){
            menor = turma.alunos[i].media;
            indexMenor = i;
        }

        if(turma.alunos[i].media < 6){
            reprovadosNota[k] = i;
            k++;
        }

        if(turma.alunos[i].frequencia < 60){
            reprovadosFreq[j] = i;
            j++;
        }


    }

    reprovadosFreq[j] = 33;
    reprovadosFreq[k] = 33;


    printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\nMAIOR MEDIA");
    printf("\nNome: %s", turma.alunos[indexMaior].nome);
    printf("\nMatricula: %i", turma.alunos[indexMaior].matricula);
    printf("\nMeida: %lf", turma.alunos[indexMaior].media);
    printf("\nFrequencia: %i\n\n", turma.alunos[indexMaior].frequencia);


    printf("\nMENOR MEDIA");
    printf("\nNome: %s", turma.alunos[indexMenor].nome);
    printf("\nMatricula: %i", turma.alunos[indexMenor].matricula);
    printf("\nMeida: %lf", turma.alunos[indexMenor].media);
    printf("\nFrequencia: %i\n\n", turma.alunos[indexMenor].frequencia);

    printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");

    imprimeInfo(turma, indexMaior, indexMenor, reprovadosFreq, reprovadosNota);

}

int main(int argc, char *argv[ ]){

    fazLeitura();

    return 0;
}