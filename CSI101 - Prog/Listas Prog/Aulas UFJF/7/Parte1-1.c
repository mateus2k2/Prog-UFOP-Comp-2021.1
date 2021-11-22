#include <stdio.h>
#include <string.h>

int main(){
    char str[50] = "Teste teste teste teste teste quantos espacos";
    int cont = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if(str[i] == ' ')
            cont++;
    }
    
    printf("O numero de espaco na string e %i", cont);

    return 0;

}