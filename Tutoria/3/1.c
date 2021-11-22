#include <math.h>
#include <stdio.h>


int main(){
    float numero = 1, media = 0;
    float maior = -INFINITY, menor = INFINITY;
    float cont = 0;

    printf("\nDigite os numeros(Digite 0 para receber os resultados): \n");
    while (1){
        scanf("%f", &numero);

        if(numero == 0)
            break;

        if(numero > maior){
            maior = numero;
        }

        if(numero < menor){     
            menor = numero;
        }
        
        media = media + numero;
        cont++;
    }

    media = media/cont;

    printf("\nMaior: %.0f \nMenor: %.0f\nMedia: %.2f\n", maior, menor, media);
    printf("\n");

    return 0;
}