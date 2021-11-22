//Escreva um programa que leia de 3 numeros inteiros. Em seguida, o programa deve vericar qual dos valores e o menor, o intermediario e o maior.

#include <assert.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[ ]){

    int a, b, c;

    printf("Digite os valores a, b, c: \n");
    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);

    printf("\n");

    if(a>b && a>c){
        printf("Maior: %i\n", a);
        if(b>c){
            printf("Intermediario: %i\n", b);
            printf("Menor: %i\n", c);
        }
        else{
            printf("Intermediario: %i\n", c);
            printf("Menor: %i\n", b);
        }
    }
    else if(b>a && b>c){
            printf("Maior: %i\n", b);
            
            if(c>a){
                printf("Intermediario: %i\n", c);
                printf("Menor: %i\n", a);
            }

            else{
                printf("Intermediario: %i\n", a);
                printf("Menor: %i\n", c);
            }
    } 

    else if(c>a && c>b){
            printf("Maior: %i\n", c);
            
            if(a>b){
                printf("Intermediario: %i\n", a);
                printf("Menor: %i\n", b);
            }

            else{
                printf("Intermediario: %i\n", b);
                printf("Menor: %i\n", a);
            }
    } 

        


    return 0;
}