// O setor que terceirizao restaurante de uma empresa realizou uma pesquisa com os funcionários pedindo que cada um avaliasse a qualidade das refeições informando uma nota de 0 a 100. 
// O setor quer saber o percentual de funcionários que considera as refeições péssimas (nota entre0 e 25), ruins (nota acima de 25 e até 50), boas (nota acima de 50 e até 75) e ótimas (acima de 75 até 100). 
// Escrevauma funçãoque leia as notas informadase imprima o percentual de funcionários que votou em cada faixa. A entrada de dados deve terminar quando for lido um valorque não pertença a nenhum dos intervalos acima.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int leitor(float faixaNotas[], int tamVotos){
    int j, i = 0, contVotos = 0;

    printf("\n");

    while(i == 0){

        printf("Digite a sua nota de 0 a 100: ");
        scanf("%i", &j);

        if(j >= 0 && j <= 25){
            faixaNotas[0]++;
        }
        else if(j >= 26 && j <= 50){
                faixaNotas[1]++;
             }
        else if(j >= 51 && j <= 75){
                faixaNotas[2]++;
             }
        else if(j >= 76 && j <= 100){
                faixaNotas[3]++;
             }    
        else
            break;

        contVotos++;
    }

    return contVotos;
}

void apurador(float faixaNotas[], int TamfaixaNotas, int contVotos){

    printf("\nA porcentagem de votos bons e %.2f", (faixaNotas[0]/contVotos)*100);
    printf("\nA porcentagem de votos bons e %.2f", (faixaNotas[1]/contVotos)*100);
    printf("\nA porcentagem de votos bons e %.2f", (faixaNotas[2]/contVotos)*100);
    printf("\nA porcentagem de votos bons e %.2f", (faixaNotas[3]/contVotos)*100);

}

int main(){
    float faixaNotas[4] = {0.0};
    int contVotos;

    contVotos = leitor(faixaNotas, 4);
    apurador(faixaNotas, 4, contVotos);
}
