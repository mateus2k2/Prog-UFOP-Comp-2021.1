// Uma pizzariatem em seu cardápio 27 sabores de pizzas e aceita pedidos para entrega via mensagens de texto para usuários já cadastrados. 
// Uma mensagem com um pedido deve informar o número de pizzas desejado e, para cada pizza, um inteiro de 1 a 27 indicando o respectivo sabor.Faça um programa que:

// a)Leia e armazeneo preço de cada pizza do cardápio;
// b)leia o pedido de cada cliente e imprima quanto cada um deverá pagar(este passo deve se repetiraté que haja um pedido com nenhuma pizza);
// c)imprima a quantia total obtida com as vendas do dia;
// d)imprima quantas pizzas de cada sabor foram vendidas no dia.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


int main(){
    
    int precoPizza[3] = {0}, pizza[3] = {0};
    int escolha, quantidade, valorApagar, vendatotal = 0;
    
    printf("\nIMPUT PRECO DAS PIZZA");
    for (int i = 0; i < 3; i++){
        
        printf("\nDigite o preco da prizza numero %i: ", i+1);
        scanf("%i", &precoPizza[i]);
    }

    while (quantidade > 0){
        printf("\n");
        printf("\nNOVO CLIENTE");

        printf("\nDigite a quantidade de pizza: ");
        scanf("%i", &quantidade);

        if(quantidade < 0)
            break;

        printf("\nDigite qual pizza vc quer (1-27): ");
        scanf("%i", &escolha);

        pizza[escolha - 1] = pizza[escolha - 1] + quantidade;
        valorApagar = precoPizza[escolha - 1] * quantidade;

        printf("\nO valor a pagar e %i", valorApagar);

        vendatotal = vendatotal + valorApagar;
    }
    
    printf("\n");
    printf("O valor total vendido no dia foi %i", vendatotal);
    printf("\n");

    for (int i = 0; i < 3; i++){
        printf("\nA quantidade de pizza %i vendidade foi de %i", i, pizza[i]);
    }
    

    
}