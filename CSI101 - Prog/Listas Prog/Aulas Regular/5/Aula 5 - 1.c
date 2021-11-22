#include <stdio.h>


int main(){
    
    float nota_trab, ava_sem, exame_esp, media;

    printf("Escreva a nota do trabalho de laboratorio: ");
    scanf("%f", &nota_trab);

    printf("Escreva a nota da avaliacao semestral: ");
    scanf("%f", &ava_sem);

    printf("Escreva a nota do exame especial: ");
    scanf("%f", &exame_esp);

    media = (2*nota_trab + 3*ava_sem + 5*exame_esp)/10;
    printf("A media ponderada e: %0.2f", media);

    if(media <= 10 && media >= 8)
        printf("\nO conceito do aluno e A");
    else if(media <= 8 && media >= 7)
        printf("\nO conceito do aluno e A");
    else if(media <= 7 && media >= 6)
        printf("\nO conceito do aluno e A");
    else if(media <= 6 && media >= 5)
        printf("\nO conceito do aluno e A");
    else if(media <= 5 && media >= 0)
        printf("\nO conceito do aluno e A");
    else
        printf("\nA media da nota e maior do que 10 ou menor do que zero o que nao e permitido");
    
    
    return 0;
}