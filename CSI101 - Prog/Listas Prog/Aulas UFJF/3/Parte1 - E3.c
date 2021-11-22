#include <stdio.h>

void calculo(int NN1, int NN2){

int soma, produto, diferenca, quociente, resto;

soma = NN1 + NN2;
produto = NN1 * NN2;
diferenca = NN1 - NN2;
quociente = NN1 / NN2;
resto = NN1 % NN2;

printf("A soma entre N1 e N2 e %d, o produto e %d, a diferenca e %d o quociente e %d e o resto e %d ", soma, produto, diferenca, quociente, resto);

}


int main (){

int N1, N2;

printf("Digite o primeiro numero: ");
scanf("%d", &N1);

printf("Digite o segundo numero: ");
scanf("%d", &N2);

calculo(N1, N2);

return 0;

}