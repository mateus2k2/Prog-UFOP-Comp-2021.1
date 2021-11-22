/*
Faça um programa para controlar as vendas de
uma loja com no máximo 1000 produtos. O programa
deve conter o valor das vendas dos produtos entre os
meses de junho e agosto.

Faça funções para:

a) preencher um vetor com dados do teclado;
b) imprimir o total vendido de cada produto no período;
c) retornar o total vendido na loja durante o trimestre;
d) reajustar o preço de todos os produtos em 10%.
Organize a função principal de modo que os valores
das vendas sejam lidos e as funções acima sejam
chamadas.
*/

void calculaVenda(int precoProdutos[], int tamPrecoProdutos, int quantidadeProdutosLoja){

    int quantidadeProdutosVendidos[1000] = {0};
    int valorDinheiroProdutos[1000] = {0};
    int totalVendido = 0;

    //Ler do teclado a quantidade vendida de cada produto
    printf("\nQUANTIDADE VENDIDA DE CADA PRODUTO\n");
    for (int i = 0; i < quantidadeProdutosLoja; i++){
        printf("Digite a quantidade vendida do produto %i: ", i);
        scanf("%i", &quantidadeProdutosVendidos[i]);
    }

    //Calculo do valor em dinheito vendido de cada produto
    printf("\nVALOR DE DINHEITO VENTIDO DE CADA PRODUTO\n");

    for (int i = 0; i < quantidadeProdutosLoja; i++){
        valorDinheiroProdutos[i] = quantidadeProdutosVendidos[i] * precoProdutos[i]; 
        printf("Valor do produto %i e %i\n", i, valorDinheiroProdutos[i]);
    }

    //Soma dos elementos do vetor valorDinheiroProdutos para saber o total vendido pela loja
    printf("\nVALOR DE DINHEITO VENTIDO PELA LOJA\n");

    for (int i = 0; i < quantidadeProdutosLoja; i++){
        totalVendido = totalVendido + valorDinheiroProdutos[i]; 
    }

    printf("O total vendido pela loja e de %i", totalVendido);

}



int main(){
    int precoProdutos[1000] = {0}; 
    int quantidadeProdutosLoja;

    printf("Digite a quantidade de produtos na loja: ");
    scanf("%i", &quantidadeProdutosLoja);

    for (int i = 0; i < quantidadeProdutosLoja; i++){
        printf("Digite o preco do produto %i: ", i);
        scanf("%i", &precoProdutos[i]);
    }

    for (int i = 0; i < quantidadeProdutosLoja; i++){
        precoProdutos[i] = precoProdutos[i] * 0.9;  
    }

    calculaVenda(precoProdutos, 1000, quantidadeProdutosLoja);

    return 0;

}