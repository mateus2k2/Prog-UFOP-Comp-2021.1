
//usar Múltipla escolha (switch)

#include <stdio.h>

float operacao (float N1, float N2, char oper){

float operacao;

if(N2 > 0){
if (oper == '/')
    operacao = N1 / N2;
}
else{
    printf("O segundo numero não pode ser");
    return 0;
}

if (oper == '+')
    operacao = N1 + N2;
if (oper == '-')
    operacao = N1 - N2;
if (oper == '*')
    operacao = N1 * N2;


return operacao;
}


int main(){
    
    float a1, a2, resultado;
    char op;
    
    printf("Digite o primeiro numero: ");
    scanf("%f", &a1);

    printf("Digite o segundo numero: ");
    scanf("%f", &a2);

    printf("Digite o sinal da operacao: ");
    scanf("%s", &op);

    resultado = operacao(a1, a2, op);

    printf("%f", resultado);

    return 0;


}