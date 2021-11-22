#include <stdio.h>
#include <string.h>

int contarEspacos(char str[]){

    int cont = 0;

    for (int i = 0; str[i] != '\0'; i++){
            if(str[i] == ' ')
                cont++;
        }

    return cont;
}

int main(){
    char str[50] = "Teste teste teste teste teste quantos espacos";
    int espacos;

    espacos = contarEspacos(str);
    
    printf("O numero de espaco na string e %i", espacos);

    return 0;

}