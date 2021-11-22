//Elabore uma função que receba uma string e um caractere e remova toda ocorrência do caractere na string.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void quebrar(char frase[], char caractere[]){

    int i = 0, k = 0, cont = 0;

    for(i=0; frase[i]; i++){

        frase[i] = frase[i+k];
 
     	if(frase[i] == caractere[0] || frase[i]=='\t'){
		    k++;
		    i--;
            cont++;
	    }
    }



    printf("\nO numero de ocorrencias do 'caractere' foi %i", cont);
    
    printf("\nA nova frase e: ");
    puts(frase);


}

int main(){
    char frase[20];
    char caractere[5];

    printf("Digite a frase: ");
    fgets(frase, 20, stdin);

    printf("Digite o caractere a ser removido: ");
    fgets(caractere, 5, stdin);

    quebrar(frase, caractere);

    return 0;
}