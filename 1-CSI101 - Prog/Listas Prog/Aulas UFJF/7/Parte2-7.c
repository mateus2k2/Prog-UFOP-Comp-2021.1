#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int main(){
    char frase[100];
    int n, tam, ram;

    printf("Digite a frase: ");
    fgets(frase, 100, stdin);

    tam = strlen(frase);

    for (int i = 0; frase[i] != '\0'; i++){
        ram = rand() % 50;
    
        if(ram <= tam)
            frase[ram] = frase[ram] - 'a' + 'A';
        else
            frase[i] = frase[i];
    }

    puts(frase);

    return 0;
    

}