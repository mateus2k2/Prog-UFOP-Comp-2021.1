#include <stdio.h>
#include <string.h>

int contarEspacos(char str[]){

    int cont = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            cont++;
    }

    return cont;
}

int main(){
    char str[50] = "Teste teste teste teste teste quantos espacos";
    int vogais;

    vogais = contarEspacos(str);
    
    printf("O numero de vogais na string e %i", vogais);

    return 0;

}