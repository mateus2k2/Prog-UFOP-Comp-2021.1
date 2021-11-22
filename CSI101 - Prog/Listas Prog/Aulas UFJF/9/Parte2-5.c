// Para participar do reality show Masterchef no Brasil é necessário apresentar um prato para os jurados Henrique Fogaça, 
// Paola Carosella ou Erick Jacquin. Cada candidato executa a um prato na frente dos 3 jurados o qual será avaliado por eles. 
// Você foi chamado para ajudar na emocionante tarefa de fazer um software para ajudar na classificação dos competidores.   

// a) Crie uma estrutura chamada Competidor com os seguintes campos: int inscricao char nome[100] float notas[3] \\3 notas de 0 a 10 

// b) Faça uma função que irá mostrar os candidatos foram classificados. Essa função deverá receber um vetor de N candidatos (utilize #define para N) 
//    e imprimir na tela o nome dos candidatos que tiveram pontuação média maior que 7.0 (ou seja, foi classificado) 
//    e, ao final, retornar quantos competidores foram classificados.
   
// c) Faça um programa que crie e leia um vetor de N Competidores, além disso, este programa deverá chamar a 
//    função descrita no item anterior, de forma adequada à sua definição, e imprimir na tela quantos competidores foram classificados.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define N 2

typedef struct{
    int inscricao;
    char nome[100];
    float notas[3];
}competidores;

int verificaClassificados(competidores grupo[], int tamanho){
    float total = 0;
    float contAprovados= 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < 3; j++){
            total = total + grupo[i].notas[j];
        }

        if(total/3 > 7){
            printf("\nO candidato %s teve media %.2f e foi aprovado", grupo[i].nome, total/3);
            contAprovados++;
        }
    }    
    return contAprovados;
}

int main(){
    competidores grupo[N];
    int classificados;
    int c;

    for (int i = 0; i < N; i++){
        printf("\nCANDIDATO %i\n", i+1);
    
        printf("Digite o nome: ");
        gets(grupo[i].nome);

        printf("Digite a inscricao: ");
        scanf("%i", &grupo[i].inscricao);

        printf("Digite as notas (1 a 10) (nota1 nota2 nota3): ");
        scanf("%f %f %f", &grupo[i].notas[0], &grupo[i].notas[1], &grupo[i].notas[2]);

        //Remove the \n from input stream
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    
    classificados = verificaClassificados(grupo, N);

    printf("\nA quantidade de aprovados foi de %i", classificados);

}
