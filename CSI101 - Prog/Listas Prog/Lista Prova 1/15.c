/*
Desenvolva um algoritmo que leia duas notas de um aluno, um trabalho (todos os valores entre 0 e 10) 
e sua frequência, definindo e imprimindo se ele foi aprovado, reprovado ou se fará prova final. O aluno será reprovado se faltou mais de 15 aulas.
*/

#include <stdio.h>

void calculo(float prova1, float prova2, float trabalho, float freq){

if(freq >= 15){
    if( ((3 * prova1) + (5 * prova2) + (2 * trabalho)) / 10 >= 6 )
        printf("Aluno Aprovado");
    if( ((3 * prova1) + (5 * prova2) + (2 * trabalho)) / 10 <= 6 )
        printf("Aluno tera que fazer prova final");
}
else{
    printf("Aluno reprovado por frequencia menor que 15");
}
}

int main(){

    float notaProva1, notaProva2, notaTrabalho, frequencia;

    printf("Digite a nota da prova 1: ");
    scanf("%f", &notaProva1);

    printf("Digite a nota da prova 2: ");
    scanf("%f", &notaProva1);

    printf("Digite a nota do trabalho: ");
    scanf("%f", &notaTrabalho);

    printf("Digite a frequancia: ");
    scanf("%f", &frequencia);

    calculo(notaProva1, notaProva2, notaTrabalho, frequencia);

}