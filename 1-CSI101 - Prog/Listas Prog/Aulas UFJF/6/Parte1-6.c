#include <stdio.h>

int main(){
    int valores[10]; 
    int acima[10] = {0};
    int abaixo[10] = {0};
    int media = 0;

    printf("\n-------------------------------\n");
    for (int i = 0; i < 10; i++){
        printf("Digite os valores: ");
        scanf("%i", &valores[i]);

        media = media + valores[i];
    }
    
    media = media/10;
    printf("\nA MEDIA E IGUAL A: %i", media);

    for (int i = 0; i < 10; i++){
        if(valores[i] > media){
            acima[i] = valores[i];
        }
        else{
            abaixo[i] = valores[i];
        }
    }

    printf("\n-------------------------------\n");
    printf("\nVALORES ABAIXO DA MEDIA");
    for (int i = 0; i < 10; i++){
        if(abaixo[i] != 0)
            printf("\nO valor %i esta  abaixo da media", abaixo[i]);
    }
    
    printf("\n-------------------------------\n");
    printf("\nVALORES ACIMA DA MEDIA");
    for (int i = 0; i < 10; i++){
        if(acima[i] != 0)
            printf("\nO valor %i esta  acima da media", acima[i]);
    }
    
    return 0;

}