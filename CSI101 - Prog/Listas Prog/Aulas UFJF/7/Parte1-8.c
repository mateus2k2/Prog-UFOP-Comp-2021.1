// Crie uma função que receba uma string de no máximo 50
// caracteres e inverta a ordem da string digitada;
// Exemplo:
// Entrada: Teste
// Saída: etseT

#include <stdio.h>
#include <string.h>

void inverte(char palavra[]){
    char temp; 
    int tam;

    tam = strlen(palavra);

    for (int i = 0; i < tam/2; i++){
        temp = palavra[i];

        palavra[i] = palavra[tam - i - 1];
        palavra[tam - i - 1] = temp;   

    }

    puts(palavra);

}

int main(){
    char palavra[50] = "Teste";

    printf("Digite a palavra: ");
    fgets(palavra, 50, stdin);

    inverte(palavra);
    
    return 0;

}