/*
Faça uma função que receba como parâmetro uma nota de uma aluno e, se o valor for maior ou igual a 60, imprimir na tela "APROVADO", 
se for menor, imprimir "REPROVADO". Testar ainda se o valor lido foi maior do que 100 ou menor do que zero. Neste caso, imprimir "NOTA INVÁLIDA".
*/

#include <stdio.h>

void verificador(N1){

//if(N1 > 100 || N1 < 0){
//    printf("Nota invalida");
//}

if(N1 >= 60 && N1 < 100 ){
    printf("Aluno Aprovado");
}

if(N1 < 60 && N1 > 0){
    printf("Aluno Reprovado");
}
else{
    printf("Nota invalida");
}

}


int main() {
    
    int nota;

    printf("Digite a nota: ");
    scanf("%d", &nota);

    verificador(nota);

    return 0;
}