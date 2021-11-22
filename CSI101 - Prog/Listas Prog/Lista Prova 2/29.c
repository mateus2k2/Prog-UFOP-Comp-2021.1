//Faça uma função que recebe como parâmetros duas strings, strAe strB, e um número inteiro k.
//A função deve copiar os k primeiros caracteres de strB para strA de forma invertida. Se k for maior que o tamanho da string,
//toda a string strBdeverá aparecer invertida em strA.Assuma que as duas strings foram alocadas com o mesmo tamanho.
//Exemplo: se strB="ABCDE" e k=3, a string strA deverá receber "CBA".Se strB="ABCDE" e k=10, a string strAdeverá receber "EDCBA".

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void inverte(char strA[], char strB[], int k){
    int tam;
    char tmp;
    char strC[10];

    for (int i = 0; i < k; i++){ 
        strA[i] = strB[i];
    }

    strA[k] = '\0';

    tam = strlen(strA);

    for (int i = 0; i < tam/2; i++){
        
        tmp = strA[i];
        strA[i] = strA[tam - i - 1];
        strA[tam - i - 1] = tmp;

    }
    
    strA[k] = '\0';

    printf("A nova string A e: ");
    puts(strA);

}

int main(){
    char strA[10];
    char strB[10];
    int k;

    printf("Digite a string: ");
    fgets(strB, 10, stdin);

    printf("Digite o k: ");
    scanf("%i", &k);

    inverte(strA, strB, k);

    return 0;
    
}