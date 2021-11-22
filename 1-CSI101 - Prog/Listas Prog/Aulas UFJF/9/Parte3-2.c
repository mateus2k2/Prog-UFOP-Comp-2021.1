// Defina uma estrutura para armazenar dados de uma disciplina: nome, número de alunos, número de avaliações, 
// uma matriz com as notas e um caractere indicando o critério de cálculo da nota final (M=média; S=soma). 
// A matriz deve armazenar até 7 avaliações para, no máximo, 150 alunos. 
// Faça um programa que leia os dados de uma turma e, em seguida, calcule e imprima a nota final de cada aluno.

typedef struct{
    float nota[7];
    char criterio;
}testes;


typedef struct {
    char nome[100];
    int numero;
    int numeroAvaliacoes;
    testes notas;
    char criterio; 
}diciplina;

int main(){

    
}


