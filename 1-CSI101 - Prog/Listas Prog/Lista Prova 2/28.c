//Escrevauma função que retorne o número de espaços em branco contidos em uma string passada como parâmetro. 


#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int verifica(char n1[]){
   int cont = 0;

    for (int i = 0; n1[i] != '\0'; i++){
        if(n1[i] == ' ')
            cont++;
    }

    return cont; 
    
}

int main(){
    char n1[10];
    int numeroEspacos;

    printf("Digite a string: ");
    fgets(n1, 10, stdin);

    numeroEspacos = verifica(n1);

    printf("O numero de espacos em branco na string e %i", numeroEspacos);

    return 0;
    
}