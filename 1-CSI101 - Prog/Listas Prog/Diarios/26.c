//Entradas: n como as primeiras letras do alfabeto 
//Objetivo:  imprimir a permutação com as n primeiras letras do algabeto
//Saida: Nenhuma saida, apenas a impresão da permutação das n primeiras letras do afabeto

#include <stdio.h>
#include <string.h>

void mudaPosicao(char *ch1, char *ch2){
    char tmp;

    tmp = *ch1;
    *ch1 = *ch2;
    *ch2 = tmp;
}

void permuta(char *str, int comeco, int fim){

    if(comeco == fim)
        printf("%s  ", str);
    else{
        for(int i = comeco; i <= fim; i++){
            mudaPosicao((str+comeco), (str+i));
            permuta(str, comeco+1, fim);
            mudaPosicao((str+comeco), (str+i)); 
        }
    }
}


int main(){
    char alfabeto[] = "---------------------------";    
    char letra = 65;
    int n;


    printf("Digite um numero inteiro de 2 a 26: ");
    scanf("%i", &n);

    for (int i = 0; i < n; i++){
        alfabeto[i] = letra;
        letra++;
        if(i == n-1)
            alfabeto[i+1] = '\0';
    }
    
    printf("Todas as posiveis alternativas com as %i primeiras letras no alfabeto: \n", n);
    permuta(alfabeto, 0, n-1);
    
    return 0;
}