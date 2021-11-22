// Crie uma matriz tridimensional onde as linhas indicam as notas de matemática, 
// história e geografia de 10 alunos e crie uma função que verifique quantos alunos passaram, ou seja, os que tenham média aritmética > 60 nas 3 disciplinas.

#include <stdio.h>
#include <string.h>

#define NOTAS 3
#define ALUNOS 10
#define MEDIA 10


void checaPassou(float turma[NOTAS][ALUNOS]){
    
    float acumula = 0;

    for (int i = 0; i < ALUNOS; i++){
        for (int j = 0; j < NOTAS; j++){
            acumula = acumula + turma[i][j];
            
            if(j == NOTAS-1)
                if(acumula/3 >= 60)
                    printf("\nO aluno %i passou com %f: ", i+1, acumula/3);
                else{
                    printf("\nO aluno %i nao  passou com %f: ", i+1, acumula/3);
                acumula = 0;
            }
        }
    }
}


int main(){
    float turma[NOTAS][ALUNOS];
    
    // int k=0;
    // int acumula;

    printf("\nDigite a notas = (1 - Matematica. 2 - Historia. 3 - Geografia)\n");
    for (int i = 0; i < ALUNOS; i++){
        for (int j = 0; j < NOTAS; j++){
            printf("Digite a nota %i do aluno %i: ", j+1, i+1);
            scanf("%f", &turma[j][i]);

            // acumula = acumula + turma[j][i];

            // if(j == NOTAS -1){
            //     turma[i][j][k] = acumula/3;
            //     k++;
            // }
        }
        printf("\n");
    }

    for (int i = 0; i < NOTAS; i++){
        for (int j = 0; j < ALUNOS; j++){
            printf("%8.2f", turma[i][j]);
        }
        printf("\n");
    }

    checaPassou(turma);

    return 0;
}