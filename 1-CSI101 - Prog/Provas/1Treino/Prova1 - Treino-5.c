//Faça um programa que receba o número de notas que o usuário digitar. Calcule e mostre a média ponderada dessas notas. O usuário deverá entrar com o peso de cada uma das notas que ele digitou. No final esta média deverá ser mostrada.

//Matrícula 20.2.8093
//Nome: Mateus Filipe Moreira Silva

#include <stdio.h>

int main(){

    int cont = 0, numeroNotas, peso, somaPeso = 0;
    float nota, mediaParcial, media = 0;

    printf("Digite a quantidade de notas que voce pretende digitar: ");
    scanf("%i", &numeroNotas);

    while(cont < numeroNotas){
        
        printf("Digite a nota: ");
        scanf("%f", &nota);

        printf("Digite o peso: ");
        scanf("%i", &peso);

        mediaParcial = nota * peso;
        somaPeso = somaPeso + peso;
        media = media + mediaParcial;
        
        cont++;
    }

    media = media / somaPeso;


    printf("A media ponderada das notas digitadas e %f", media );

    return 0;
    
}