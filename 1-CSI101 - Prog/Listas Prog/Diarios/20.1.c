/*
NOME: Mateus Filipe Moreira Silva
Matriculo: 20.2.8093
*/

#include <stdlib.h>
#include <stdio.h>

int main(){
    float conta, totalConta, totalSalario;
    int numeroContas;

    printf("\n");

    //Scan da quantidade de contas a serem lidas
    printf("Digite quantas contas voce tem: ");
    scanf("%i", &numeroContas);

    //Scan do salario
    printf("Digite o seu salario: ");
    scanf("%f", &totalSalario);

    printf("\n");


    for(int i = 0; i < numeroContas; i++){

        //Scan do valor das contas
        printf("Digite o valor da conta %i: ", i + 1);
        scanf("%f", &conta);

        //Aumenta a conta em 4%
        conta = conta * 1.04;
        //Acumula o calor das contas com o aumento
        totalConta = totalConta + conta;
    }

    //print do total das contas com o aumento
    printf("\nO valor total das contas com as multas e de %0.2f", totalConta);

    //Testa se o valor do total de salario e maior ou igual que o total da conta
    if(totalSalario >= totalConta){   
        //print oque resoltol do salario tirando as contas
        printf("\nO restante do seu salario e %0.2f", totalSalario - totalConta);   
    }
    else{
        //Se as contas forem maiores que o salario print o valor que flata para pagar as contas
        printf("\nFaltam %f para vc pagar as contas com seu salario atual", totalConta - totalSalario);
    }       

    return 0;      

}