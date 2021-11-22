// Escreva uma função que insira um espaço em branco antes de cada letra maiúscula da string passada por parâmetro.
// Assuma que o espaço reservado para a string é, no mínimo, o dobro do tamanho da string.Cuidado para não perder nenhum caractere ao longo de seu algoritmo.



#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void espaco(char strA[]){
    int i = 0, k = 0;
    char tmp[20];

    for(i=0; strA[i]; i++){
     	
        strA[i] = strA[i+k];
 
     	if(strA[i] >= 65 && strA[i] <= 90){
		    k++;
		    i--;
            strA[i - 1] = ' ';
	    }
    }

    printf("A string com espacos antes das letras maiusculas e: ");
    puts(strA);    

}

int main(){
    char strA[20];

    printf("Digite a string: ");
    fgets(strA, 10, stdin);

    espaco(strA);

    return 0;
    
}