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
    int controleAlunos;
    char qualTurma[30];
}Turma;

typedef struct{
    Turma turmas[20];
    int controleTurmas;
    char nomeEscola[30];
    char nomeDiretor[30];

}Escola;


void imprimeInfo(Escola escola, int indexMaiorAluno, int indexMenorAluno, int indexMaiorEscola, int indexMenorEscola, 
                int reprovadosFreqAluno[], int reprovadosNotaAluno[], int reprovadosFreqEscola[], int reprovadosNotaEscola[]){

    printf("\nMAIOR MEDIA");
    printf("\nNome: %s", escola.turmas[indexMenorEscola].alunos[indexMaiorAluno].nome);
    printf("\nMatricula: %i", escola.turmas[indexMenorEscola].alunos[indexMaiorAluno].matricula);
    printf("\nMeida: %lf", escola.turmas[indexMenorEscola].alunos[indexMaiorAluno].media);
    printf("\nFrequencia: %i\n\n", escola.turmas[indexMenorEscola].alunos[indexMaiorAluno].frequencia);


    printf("\nMENOR MEDIA");
    printf("\nNome: %s", escola.turmas[indexMenorEscola].alunos[indexMenorAluno].nome);
    printf("\nMatricula: %i", escola.turmas[indexMenorEscola].alunos[indexMenorAluno].matricula);
    printf("\nMeida: %lf", escola.turmas[indexMenorEscola].alunos[indexMenorAluno].media);
    printf("\nFrequencia: %i\n\n", escola.turmas[indexMenorEscola].alunos[indexMenorAluno].frequencia);

    printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\nREPROVADO POR FREQUENCIA");
    for (int i = 0; reprovadosFreqEscola[i] != 100; i++){
        for (int j = 0; reprovadosFreqAluno[j] != 100; j++){
            printf("\nNome: %s", escola.turmas[reprovadosFreqEscola[i]].alunos[reprovadosFreqAluno[j]].nome);
            printf("\nMatricula: %i", escola.turmas[reprovadosFreqEscola[i]].alunos[reprovadosFreqAluno[j]].matricula);
            printf("\nMeida: %lf", escola.turmas[reprovadosFreqEscola[i]].alunos[reprovadosFreqAluno[j]].media);
            printf("\nFrequencia: %i\n", escola.turmas[reprovadosFreqEscola[i]].alunos[reprovadosFreqAluno[j]].frequencia);   
        }
    }

    printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\nREPROVADO POR NOTA");
    for (int i = 0; reprovadosNotaEscola[i] != 100; i++){
        for (int j = 0; reprovadosNotaAluno[j] != 100; j++){
            printf("\nNome: %s", escola.turmas[reprovadosNotaEscola[i]].alunos[reprovadosNotaAluno[j]].nome);
            printf("\nMatricula: %i", escola.turmas[reprovadosNotaEscola[i]].alunos[reprovadosNotaAluno[j]].matricula);
            printf("\nMeida: %lf", escola.turmas[reprovadosNotaEscola[i]].alunos[reprovadosNotaAluno[j]].media);
            printf("\nFrequencia: %i\n", escola.turmas[reprovadosNotaEscola[i]].alunos[reprovadosNotaAluno[j]].frequencia);   
        }
    }
}

void fazLeitura(){
    Escola escola;

    double maior = -INFINITY, menor = INFINITY;
    int indexMaiorAluno, indexMenorAluno, indexMaiorEscola, indexMenorEscola;
    int reprovadosNotaAluno[30], reprovadosFreqAluno[30], reprovadosFreqEscola[30], reprovadosNotaEscola[30], k = 0, l = 0, kk = 0, ll = 0;
    
    printf("Digite o nome da Escola: ");
    fgets(escola.nomeEscola, 30, stdin);
    escola.nomeEscola[strlen(escola.nomeEscola)-1] = '\0';

    printf("Digite o nome do Direotr: ");
    fgets(escola.nomeDiretor, 30, stdin);
    escola.nomeDiretor[strlen(escola.nomeDiretor)-1] = '\0';


    printf("Digite a quantidade de Turmas: ");
    scanf("%i", &escola.controleTurmas);
    while ((getchar()) != '\n');

    printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\nESCOLA: %s", escola.nomeEscola);
    printf("\nDIRETOR: %s\n\n", escola.nomeDiretor);
    for (int i = 0; i < escola.controleTurmas; i++){
        printf("\nTRUMA: %i\n", i+1);

        printf("Digite o nome da turma: ");
        fgets(escola.turmas[i].qualTurma, 30, stdin);

        escola.turmas[i].qualTurma[strlen(escola.turmas[i].qualTurma)-1] = '\0';

        printf("Digite a quantidade de Alunos: ");
        scanf("%i", &escola.turmas[i].controleAlunos);
        while ((getchar()) != '\n');

        for (int j = 0; j < escola.turmas[i].controleAlunos; j++){
            printf("\nALUNO %i\n", j+1);

            printf("Nome: "); fgets(escola.turmas[i].alunos[j].nome, 30, stdin);
            escola.turmas[i].alunos[j].nome[strlen(escola.turmas[i].alunos[j].nome)-1] = '\0';


            printf("Matricula: "); scanf("%i", &escola.turmas[i].alunos[j].matricula);
            printf("Media: "); scanf("%lf", &escola.turmas[i].alunos[j].media);
            printf("Frequencia: "); scanf("%i", &escola.turmas[i].alunos[j].frequencia);
            while ((getchar()) != '\n');

            if(escola.turmas[i].alunos[j].media > maior){
                maior = escola.turmas[i].alunos[j].media;
                indexMaiorAluno = j;
                indexMaiorEscola = i;
            }

            if(escola.turmas[i].alunos[j].media < menor){
                menor = escola.turmas[i].alunos[j].media;
                indexMenorAluno = j;
                indexMenorEscola = i;
            }

            if(escola.turmas[i].alunos[j].media < 6){
                reprovadosNotaAluno[k] = j;
                reprovadosNotaEscola[kk] = i;
                k++;
            }

            if(escola.turmas[i].alunos[j].frequencia < 60){
                reprovadosFreqAluno[l] = j;
                reprovadosFreqEscola[ll] = i;
                l++;
            }

        }
        printf("\n****************************\n");
        ll++;
        kk++;
    }

    reprovadosFreqAluno[l] = 100;
    reprovadosNotaAluno[k] = 100;
    reprovadosFreqEscola[ll] = 100;
    reprovadosNotaEscola[kk] = 100;


    printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");
    
    imprimeInfo(escola, indexMaiorAluno, indexMenorAluno, indexMaiorEscola, indexMenorEscola, 
                reprovadosFreqAluno, reprovadosNotaAluno, reprovadosFreqEscola, reprovadosNotaEscola);

}

int main(int argc, char *argv[ ]){

    fazLeitura(); //E chama função imprimeInfo

    return 0;
}