// Escreva uma função que gere e imprima o quinto número natural perfeito. 
// Um número perfeito é aquele que é igual à soma dos seus divisores exceto o próprio número. (Ex.: 6 = 1+2+3; 28= 1+2+4+7+14, etc).

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void calculo(){
    int i=1, j=1;
    int somaDivisores = 0, contPerfeitos = 0;

    while (i > 0){
        
        printf("\n");

        for (j = 1; j < i; j++){
            if(i%j==0)
                somaDivisores = somaDivisores + j;             
        }

        printf("\n-----O numero (i) atual e %i-------------", i);
        printf("\n-----A soma dos divisores de %i e %i-----", i, somaDivisores);
        

        if(somaDivisores == i){
            printf("\n");
            printf("\n*******O NUMERO %i E PERFEITO*******", i);
            contPerfeitos++;        

        }
        if(contPerfeitos == 5)
            break;

        i++;
        j = 1;
        somaDivisores = 0;
    }
    
    //printf("\n%i e o quisto numero perfeito");
    
}

int main(){
    
    calculo();

    return 0;
}