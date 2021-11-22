#include <stdio.h>
#include <string.h>

void checar(char palavra[]){

    char invertida[100];
    char temp; 

    strcpy(invertida, palavra);

    int tam;
    tam = strlen(palavra);

    for (int i = 0; i < tam/2; i++){
        temp = invertida[i];
        invertida[i] = invertida[tam - i - 1];
        invertida[tam - i - 1] = temp;   

    }

    if(strcmp(palavra, invertida) == 0)
        printf("A palavra e palindrome");
    else
        printf("A palavra nao e palindrome");

    printf("\n");

}

int main(){
    char palavra[100];

    printf("Digite a palavra: ");
    fgets(palavra, 100, stdin);

    int tam = strlen(palavra);
    palavra[tam-1] = '\0';

    checar(palavra);

    return 0;
}
