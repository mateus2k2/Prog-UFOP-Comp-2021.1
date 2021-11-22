// Fazer uma função que leia uma string do teclado (máx. 50
// caracteres) e imprima uma “estatística” dos caracteres
// digitados. Isto é, imprima a quantidade de vogais, a
// quantidade de consoantes e a quantidade de outros
// caracteres.

#include <stdio.h>
#include <string.h>

void estatistica(char frase[]){
    int vogais = 0, consoantes = 0, outros = 0;

    for (int i = 0; frase[i] != '\0'; i++){
        if( (frase[i] >= 65 && frase[i] <= 90) || (frase[i] >= 97 && frase[i] <= 122) ){

            if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u' || frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U')
                vogais++;
            if(frase[i] != 'a' && frase[i] != 'e' && frase[i] != 'i' && frase[i] != 'o' && frase[i] != 'u' && frase[i] != 'A' && frase[i] != 'E' && frase[i] != 'I' && frase[i] != 'O' && frase[i] != 'U')
                consoantes++;
        }
        
        else{
            outros++;
        }

        
    }

    printf("\nVogais %i", vogais);
    printf("\nConsoantes %i", consoantes);
    printf("\nOutros %i", outros-1);   

}

int main(){
    int frase[50];

    printf("Digite a frase: ");
    fgets(frase, 50, stdin);

    estatistica(frase);

    return 0;
}