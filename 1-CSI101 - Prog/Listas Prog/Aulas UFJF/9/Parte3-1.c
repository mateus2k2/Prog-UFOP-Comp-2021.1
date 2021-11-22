// Um teatro precisa armazenar, para cada evento, as informações sobre os ingressos disponíveis em cada categoria de preço. 
// Assim, defina uma estrutura que contém os dados de uma categoria: o número total de ingressos, o número de ingressos já vendidos e o preço do ingresso.       

// Faça um programa que declare três categorias distintas (estrutura definida acima): plateia, lateral e balcão. Inicialmente, 
// o programa deve ler o preço e o total de ingressos de cada categoria. Assuma que neste momento, nenhum ingresso foi vendido. 
// Depois, o programa deve registrar cada venda de ingressos lendo categoria (P, L ou B) e número de ingressos e imprimindo quanto deve ser pago pelo comprador. 
// A leitura de vendas será encerrada quando uma categoria inválida for digitada. No final, o programa deve imprimir quantos ingressos ainda estão disponíveis 
// em cada categoria e o total arrecadado com as vendas.

typedef struct{
    int totalIngresos;
    int ingresosVendidos;
    float preco;
}categoria;

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    categoria P, L, B;
    int quantidade;
    char EscolhaCategoria;

    printf("\nCATEGORIA PLATEIA\n");

    printf("Digite o total de ingresos disponivel: ");
    scanf("%i", &P.totalIngresos);
    printf("Digite o preco do ingresos: ");
    scanf("%f", &P.preco);
    P.ingresosVendidos = 0;

    printf("\nCATEGORIA LATERAL\n");

    printf("Digite o total de ingresos disponivel: ");
    scanf("%i", &L.totalIngresos);
    printf("Digite o preco do ingresos: ");
    scanf("%f", &L.preco);
    L.ingresosVendidos = 0;

    printf("\nCATEGORIA BALCAO\n");

    printf("Digite o total de ingresos disponivel: ");
    scanf("%i", &B.totalIngresos);
    printf("Digite o preco do ingresos: ");
    scanf("%f", &B.preco);
    B.ingresosVendidos = 0;

    while(1){
        printf("\n");
        printf("\nCOMPRA DE INGRESO\n");

        printf("Digite a categoria (Plateia = P || Lateral = (L) || Balcão = (B): ");
        scanf("%s", &EscolhaCategoria);

        printf("Digite a quantidade de ingressos a serem compradas: ");
        scanf("%i", &quantidade);

        //verificar quando o ingreso esta acabando

        if(EscolhaCategoria == 'P' || EscolhaCategoria == 'L' || EscolhaCategoria == 'B'){

        if(EscolhaCategoria == 'P'){
            P.ingresosVendidos = P.ingresosVendidos + quantidade;
            P.totalIngresos = P.totalIngresos - quantidade;
            printf("O valor a pagar e de %f", quantidade*P.preco);
        }
        else if(EscolhaCategoria == 'L'){
                L.ingresosVendidos = L.ingresosVendidos + quantidade;
                L.totalIngresos = L.totalIngresos - quantidade;
                printf("O valor a pagar e de %f", quantidade*L.preco);
                
        }
        else if(EscolhaCategoria == 'B'){
                B.ingresosVendidos = B.ingresosVendidos + quantidade;
                B.totalIngresos = B.totalIngresos - quantidade;
                printf("O valor a pagar e de %f", quantidade*B.preco);
        }    
    }
        else
            break;
    }    
    printf("\nRestao %i ingresos na categoria de plateia", P.totalIngresos);
    printf("\nRestao %i ingresos na categoria de lateral", L.totalIngresos);
    printf("\nRestao %i ingresos na categoria de balcao", B.totalIngresos);

    printf("\nO total arecadado foi de %.2f", (P.ingresosVendidos*P.preco) + (L.ingresosVendidos*L.preco) + (B.ingresosVendidos*B.preco));

    return 0;

}
