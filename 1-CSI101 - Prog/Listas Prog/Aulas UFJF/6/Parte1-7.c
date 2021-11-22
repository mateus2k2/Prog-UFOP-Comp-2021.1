/*
7) Um professor resolveu avaliar os trabalhos em
grupo de seguinte forma: em cada grupo de 8 alunos,
cada estudante dá uma nota de 1 a 10 para os outros
7 integrantes do grupo.
Faça um programa que calcule as notas de um grupo
lendo do teclado as notas atribuídas por cada
integrante e imprimindo a média das notas que cada
aluno recebeu.
Dica: Use um vetor que armazene em cada posição a
soma das notas recebidas por cada estudante.
Observe que não é necessário armazenar cada nota
de um aluno, mas apenas a soma de suas notas.
*/

#include <stdio.h>

int main(){
    int soma[8] = {0}; 
    float media[8] = {0}; 
    int somaa;
    int i = 0, ii = 0;

    for (i = 0; i < 8; i++){

        printf("\n");    
        printf("VEZ DO INTEGRANTE NUMERO %i AVALIAR OS OUTROS\n", i);

        for (ii = 0; ii < 8; ii++){
            if(i != ii){
            printf("Digite a nota que voce da para o integrante %i: ", ii);
            scanf("%i", &somaa);
            
            soma[ii] = somaa + soma[ii];
            }
        }
    ii = ii + 1;
    }

    printf("\n----------------------------------------------------------------\n");

    for (int j = 0; j < 8; j++){
        media[j] = soma[j] / 7;

        printf("\nA media das notas do integrante %i e %f", j, media[j]);
    }
    
    return 0;
}