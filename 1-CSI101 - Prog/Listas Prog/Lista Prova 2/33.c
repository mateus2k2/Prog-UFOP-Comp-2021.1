//Em uma eleição para prefeito,existem quatro candidatos. A cidade tem 25 mil eleitores, embora nem todos participem da eleição. 
// Cada eleitor indica seu voto através de um único número inteiro, da seguinte forma:

// A 1,2,3,4 = voto para os respectivos candidatos;
// B 0= voto em branco;
// C Qualquer outro valorpositivo = voto nulo.

// a) Elabore uma função que leia todos os votos, armazenando-os. Assuma que a sequência de votos será finalizada por um número negativo. A função deve retornar o número de votos computados.
// b) Faça uma segunda função que receba o número de votos armazenados e a relação completa de votos e imprima o resultado completo da eleição (número de votos nulos, brancos e de cada candidato). 
// c) Faça um programa para computar e apurar a eleição que chame as funções acima.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void leitor(int votos[], int tamVotos){
    int i = 0, j;

    while (votos[i] >= 0){
        printf("Digite o voto (1, 2, 3, 4), 0 para nulo, qualque outro para branco: ");
        scanf("%i", &j);

        if(j < 0)
            break;

        switch (j){
        case 0: votos[0]++;
            break;
        case 1: votos[1]++;
            break;
        case 2: votos[2]++;
            break;
        case 3: votos[3]++;
            break;
        case 4: votos[4]++;
            break;

        default: votos[5]++;
            break;
        }
    }
}

void apurador(int votos[], int tamVotos){


    printf("\nO numero de votos do candidato 1 foi de %i", votos[1]);
    printf("\nO numero de votos do candidato 2 foi de %i", votos[2]);
    printf("\nO numero de votos do candidato 3 foi de %i", votos[3]);
    printf("\nO numero de votos do candidato 4 foi de %i", votos[4]);

    printf("\n");

    printf("\nO numero de votos brancos foi de %i", votos[0]);
    printf("\nO numero de votos nulos foi de %i", votos[5]);

}

int main(){
    int votos[6] = {0};

    leitor(votos, 6);
    apurador(votos, 6);
}