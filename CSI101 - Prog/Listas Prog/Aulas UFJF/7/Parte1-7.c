// Crie uma função que receba uma frase e a exiba na tela
// de forma soletrada, ou seja, cada letra deve ser exibida na
// tela separada por hífen.

#include <stdio.h>
#include <string.h>

void separar(char str[]){

    for (int i = 0; str[i] != '\0'; i++){
        
        if(str[i + 1] != ' ' && str[i] != ' ' && str[i + 1] != '\0')
            printf("%c-", str[i]);
        else   
            printf("%c", str[i]);
    }

}

int main(){
    char str[50] = "Teste teste teste teste teste quantos espacos";
    int cont = 0;

    printf("Digite a frase: ");
    fgets(str, 50, stdin);

    separar(str);
    
    return 0;

}