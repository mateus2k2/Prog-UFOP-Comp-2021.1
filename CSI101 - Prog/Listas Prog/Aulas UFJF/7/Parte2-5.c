// Escreva uma função que receba uma cadeia de caracteres
// de tamanho máximo 100, e retornar 1 se esta cadeia é
// palíndrome e zero caso contrário. Uma palavra é dita ser
// palíndrome se a seqüência de seus caracteres da esquerda
// para a direita é igual a seqüência de seus caracteres da
// direita para a esquerda. Ex.: arara, asa, ovo...

#include <stdio.h>
#include <string.h>

int checar(char frase[]){

    char fraseOriginal[100];
    char temp; 
    int tam, j = 0;

    strcpy(fraseOriginal, frase);

    tam = strlen(frase);

    for (int i = 0; i < tam/2; i++){
        temp = frase[i];

        frase[i] = frase[tam - i - 1];
        frase[tam - i - 1] = temp;   

    }

    printf("\nPalavra invertida: ");
    puts(frase);

    printf("\nPalavra original: ");
    puts(fraseOriginal);

    for (int i = 0; frase[i] != '\0'; i++){
        if(frase[i] != fraseOriginal)
            j = 1;
    }

    if(j = 0)
        printf("A palavra e palindrome");
    else
        printf("A palavra nao e palindrome");
;
    

}

int main(){
    char frase[100];

    printf("Digite a frase: ");
    fgets(frase, 100, stdin);

    checar(frase);

    return 0;
}

// strcpy(char destino[], char origem[])
// copia a string origem na string destino