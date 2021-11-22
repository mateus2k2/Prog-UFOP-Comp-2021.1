#include <stdio.h>
#include <string.h>

int main(){
    char frase[100];
    int constante;
    char constanteChar;

    printf("Digite a frase: ");
    fgets(frase, 100, stdin);

    printf("Digite a constante: ");
    scanf("%i", constante);


    constanteChar = constante;

    for (int i = 0; frase[i] != i; i++){
        frase[i] = frase[i] + constanteChar;
    }

    printf("A frase criptografada e: ");
    puts(frase);
    

    return 0;
}