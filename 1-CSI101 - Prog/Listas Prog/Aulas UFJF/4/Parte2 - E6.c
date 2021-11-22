//não funciona caractere == > e <

#include <stdio.h>

void classificacaractere(char caractere){

if(caractere=='+' || caractere=='-' || caractere=='*' || caractere=='/' || caractere=='%' || caractere=='\>' || caractere=='<' || caractere=='!' || caractere=='&' || caractere=='\'' || caractere=='\"' || caractere=='(' || caractere=='{' ){
if(caractere=='+' || caractere=='-' || caractere=='*' || caractere=='/' || caractere=='%')
    printf("Operador matematico");
if(caractere=='<' || caractere=='<')
    printf("Operador relacionais");
if(caractere=='!')
    printf("Operador logico");
if(caractere=='&' || caractere=='=' || caractere=='\'' || caractere=='\"' || caractere=='(' || caractere=='{')
    printf("Outro simbolo valido em c");
}
else{
    printf("Caractere nao identificado");
}


}

int main(){
    
    char caractere;
    
    printf("Digite o simbolo: ");
    scanf("%c", &caractere);

    classificacaractere(caractere);

    return 0;
}