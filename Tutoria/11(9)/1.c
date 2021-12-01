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
    int digito1, digito2, conta[100], j = 0;
    char c = '1';

    FILE *contas = fopen("contas.txt", "r");
    FILE *resultado = fopen("resultado.txt", "w");

    for (int i = 0; c != ';'; i++){
        fscanf(contas, "%c", &c);
        fseek(contas, -1, SEEK_CUR);

        if(c != '+' && c != '-' && c != '*' && c != '/' ){
            fscanf(contas, "%i", &digito1);
        }

        fscanf(contas, "%c", &c);
        fseek(contas, -1, SEEK_CUR);

        if(c != '+' && c != '-' && c != '*' && c != '/' ){
            fscanf(contas, "%i", &digito2);
        }
        

        if(c == '+'){
            conta[j] = digito1 + digito2;
            printf("\n%i\n", conta[j]);
            j++;
        }
        else if(c == '-'){
            conta[j] = digito1 - digito2;
            printf("\n%i\n", conta[j]);
            j++;
        }
        else if(c == '*'){
            conta[j] = digito1 * digito2;
            printf("\n%i\n", conta[j]);
            j++;
        }
        else{
            conta[j] = digito1 / digito2;
            printf("\n%i\n", conta[j]);
            j++;
        }

        if(fscanf(contas, "%c", &c) == ';')
            break;
    }
    
    



    return 0;
}