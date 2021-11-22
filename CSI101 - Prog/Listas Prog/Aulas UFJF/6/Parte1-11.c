/*
Faça um programa que contenha: (1) um vetor
com N inteiros, representando códigos de produtos; (2)
um vetor com N inteiros, representando a quantidade
de cada produto em estoque; (3) um vetor com N
reais, representando o valor de cada produto; (4) um
vetor com M inteiros, com os códigos dos produtos
vendidos no dia (pode haver repetição).
Elabore funções para:
a) calcular o valor total dos produtos em estoque;
b) calcular o valor total vendido no dia;
c) atualizar o estoque, descontando as unidades
vendidas de cada produto
*/

int main(){
    int codProdutos[3] = {111, 222, 333}; 
    int quantidadeEstoque[3] = {10, 20, 30};
    int estoqueAtualizado[3] = {10, 20, 30};
    int vendidosDia[1000] = {0};

    float valorProduto[3] = {100, 200, 300};
    float valorEstoque = 0;
    float vendatotal = 0;
    
    int codVenda = 0;
    int quantidade = 0;
    int ii=1;
    
    printf("\n----------------------------------------\n");

    //Pegar codigo dos produtos
    printf("\nCODIGOS\n");    
    for (int i = 0; i < 3; i++){
        printf("Digite o codigo do produto: ");
        scanf("%i", &codProdutos[i]);
    }

    printf("\n----------------------------------------\n");

    //Pegar a quantidade de cada produto em estoque
    printf("\nQUANTIDADE\n");
    for (int i = 0; i < 3; i++){
        printf("Digite a quantidade do produto de codigo %i na estoque: ", codProdutos[i]);
        scanf("%i", &quantidadeEstoque[i]);
    }

    //Copiar o estoque atual para um novo vetor para modificar ele depois
    for (int i = 0; i < 3; i++){
        estoqueAtualizado[i] = quantidadeEstoque[i];
    }
    
    printf("\n----------------------------------------\n");

    //Pegar o valor de cada produto
    printf("\nVALOR\n");
    for (int i = 0; i < 3; i++){
        printf("Digite o valor do produto de cod %i: ", codProdutos[i]);
        scanf("%f", &valorProduto[i]);
    }

    //Calcular o valor do estoque
    for (int i = 0; i < 3; i++){
        valorEstoque = valorEstoque + (quantidadeEstoque[i] * valorProduto[i]);
    }

    printf("\n----------------------------------------\n");

   
    //Sistrma para caluclar a comprar
    //Calcular a total da venda e atualizar o estoque
    printf("\nVENDA\n");
    while(ii==1){
        printf("\nDigitar nova venda? 1 para sim || 0 para nao: ");
        scanf("%i", &ii);

        if(ii==0)
            break;

        printf("Digite o codigo do produto vendido e a quantidade (x y): ");
        scanf("%i %i", &codVenda, &quantidade);

        for (int i = 0; i < 3; i++){
            if(codVenda == codProdutos[i]){
                vendatotal = vendatotal + (valorProduto[i] * quantidade);
                estoqueAtualizado[i] = estoqueAtualizado[i] - quantidade;
            }
        }
    }

    printf("\n----------------------------------------\n");
    
    printf("TOTAL VENDA E ESTOQUE\n");
    printf("A venda totoal desse dia e de %0.2f\n", vendatotal);
    printf("O valor total de produtos em estoque e %0.2f\n", valorEstoque);

    printf("\n");

    printf("O ESTOQUE ATUALIZADO\n");
    for (int i = 0; i < 3; i++){
        printf("O novo estoque do produto de codigo %i e de %i\n", codProdutos[i], estoqueAtualizado[i]);
    }
    
    return 0;
}