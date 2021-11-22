#include <stdio.h>
#include <string.h>

int main(){
    char str[50] = "a a a a a e i o i a";
    int cont = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            cont++;
    }
    
    printf("O numero de vogais na string e %i", cont);

    return 0;

}