//Na eleição para o representante dos alunos da sala, apareceram quatro candidatos: 
//Ana, Ari, Eva e Ivan. Faça uma função que receba o número de alunos presentes no dia da eleição e leia o nome do candidato em que cada aluno votou. 
//Ao final, exiba o número de votos que cada candidato obteve. Observe que eventuais erros de grafia no nome digitado por um eleitor indicam voto nulo.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void leitor(int votos[], int tamVotos, int numeroAlunos){
    char candidato[10];
    int ret1,  ret2, ret3, ret4, c;

    printf("\n");

    for (int i = 0; i < numeroAlunos; i++){

        //Remove the \n from input stream
        while ( (c = getchar()) != '\n' && c != EOF );

        printf("Digite o voto (Ana, Ari, Eva e Ivan), 0 para nulo, qualque outro para branco: ");
        fgets(candidato, 10, stdin);

        ret1 = strncmp(candidato, "Ana", 3);
        ret2 = strncmp(candidato, "Ari", 3);
        ret3 = strncmp(candidato, "Eva", 3);
        ret4 = strncmp(candidato, "Ivan", 4);

        if(ret1 == 0)
            votos[1]++;
        else if(ret2 == 0)
                votos[2]++;
        else if(ret3 == 0)
                votos[3]++;
        else if(ret4 == 0)
                votos[4]++;
        else if(candidato[0] == '0')
                votos[0]++;
        else
            votos[5]++;
    }
}

void apurador(int votos[], int tamVotos){


    printf("\nO numero de votos em Ana foi de %i", votos[1]);
    printf("\nO numero de votos em Ari foi de %i", votos[2]);
    printf("\nO numero de votos em Eva foi de %i", votos[3]);
    printf("\nO numero de votos em Ivan foi de %i", votos[4]);

    printf("\n");

    printf("\nO numero de votos brancos foi de %i", votos[0]);
    printf("\nO numero de votos nulos foi de %i", votos[5]);

}

int main(){
    int votos[6] = {0};
    int numeroAlunos;

    printf("Digite a quantidade de alunos presentes na sala: ");
    scanf("%i", &numeroAlunos);

    leitor(votos, 6, numeroAlunos);
    apurador(votos, 6);
}