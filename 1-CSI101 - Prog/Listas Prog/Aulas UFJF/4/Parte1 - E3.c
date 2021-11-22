/*

Elabore uma função que receba como
parâmetros dois números inteiros e imprima
uma mensagem se um for divisível pelo
outro.
Em seguida, faça um programa que leia
um número inteiro do teclado e chame a
função para verificar se este número é
divisível por 2, por 3, por 5 e por 7
(serão 4 chamadas).
Faça um teste de mesa com o valor 14.

*/

//Primeira Parte


#include <stdio.h>

// void TesteDiv12 (int N1, int N2){

//     if(N1%N2==0) {
// 		printf("%d e divisivel por %d", N1, N2);
// 	}
// 	else {
// 		printf("%d nao e divisivel por %d", N1, N2);
// 	}

// }

// int main(){

//     int numero1, numero2, resuldadoDivN1N2;
//     printf("Digite o primeiro numero: ");
//     scanf("%d", &numero1);

//     printf("Digite o primeiro numero: ");
//     scanf("%d", &numero2);

//     TesteDiv12(numero1, numero2);
//     return 0;
// }
//-------------------------------------------------------------


void TesteDiv (int N1){

   if (N1%2==0) {
    printf("%d e divisivel por 2, ", N1);
    }
    else {
    printf("%d nao e divisivel por 2, ", N1);
    }

    if (N1%3==0) {
   printf("divisivel por 3, ");
    }
    else {
   printf("nao e divisivel por 3, ");    
    }
    
    if (N1%5==0) {
    printf("divisivel por 5");
    }
    else {
    printf("nao e divisivel por 5, ");     
    }

    if (N1%7==0) {
    printf("e e divisivel por 7. ");
    }
    else {
    printf("e nao e divisivel por 7. ");     
    }
}

int main(){

    int numero1;
    printf("Digite o numero: ");
    scanf("%d", &numero1);

    TesteDiv(numero1);

    return 0;
}