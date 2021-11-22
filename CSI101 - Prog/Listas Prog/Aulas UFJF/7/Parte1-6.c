// Escreva uma função que receba uma string, conte
// quantos caracteres desta string são iguais a 'a' e substitua
// os que forem iguais a 'a' por 'b'. A função deverá retornar o
// número de caracteres modificados

#include <stdio.h>
#include <string.h>

int main(){
    char str[50] = "Teste teste teste teste teste quantos espacos";
    int cont = 0;

    fgets(str, 50, stdin);

    for (int i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a'){
            cont++;
            str[i] = 'b';
        }
    }
    
    printf("\nO numero de caracteres modificados na string e %i", cont);
    printf("\n");
    puts(str);

    return 0;

}