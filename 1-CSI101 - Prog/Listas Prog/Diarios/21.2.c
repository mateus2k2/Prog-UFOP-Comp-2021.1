/*
NOME: Mateus Filipe Moreira Silva
Matriculo: 20.2.8093
*/

#include <stdio.h>
#include <string.h>

int main(){
    int numeroProdutos;
    float precoUnitario, custoArmazenagem; 
    char tipoArmazenagem, categoria;

    //Pega do teclado o numero de produtos que o usuario queira checar
    printf("Digite o numero de pordutos: ");
    scanf("%i", &numeroProdutos);

    //loop que vai de 0 ate o numero de produtos que o usuario queira checar - 1 
    for (int i = 0; i < numeroProdutos; i++){

        printf("\n");

        //Scan de cada parametro para determinar o custo de armazenagem
        printf("Digite o preco unitario de cada produto: ");
        scanf("%f", &precoUnitario);
    
        printf("Digite o tipo de armazenamento, se refrigerado ou nao sendo S sim e N para nao: ");
        scanf("%s", &tipoArmazenagem);

        printf("Digite a categoria do produto, A - alimentacao; L - Limpeza; e V - vestuario: ");
        scanf("%s", &categoria);


        //A tabela  no moodle estava mau formatada e de dificil interpretação
        //Essa e a minha interpretação da tabela 
        //Segue o link da tabela refeita por mim e usada como referencia
        //https://imgur.com/a/BNZb4qc
        if(precoUnitario <= 20){
            if(categoria == 'A')
                custoArmazenagem = 0.2;
            if(categoria == 'L')
                custoArmazenagem = 0.3 ;
            if(categoria == 'V')
                custoArmazenagem = 0.4;                          
        }

        if(precoUnitario > 20 && precoUnitario <= 50){
            if(tipoArmazenagem == 'S')
                custoArmazenagem = 0.6;
            if(categoria == 'N')
                custoArmazenagem = 0.0;
            if(categoria == 'A') 
                custoArmazenagem = 0.5;
            if(tipoArmazenagem == 'S' && custoArmazenagem == 'L')
                custoArmazenagem = 0.2;
        }

        if(precoUnitario > 50){
            if(categoria == 'V')
                custoArmazenagem = 0.4;
            if(tipoArmazenagem == 'N' && (categoria == 'A' || categoria == 'V'))
                custoArmazenagem = 0;
            if(categoria == 'L')
                custoArmazenagem = 0.1;        
            }

    //Print do curso de armazenagem do produto atual 
    printf("O cursto de armazenagem desse produto e: %0.2f", custoArmazenagem);

    printf("\n");
 
}

   return 0;

}