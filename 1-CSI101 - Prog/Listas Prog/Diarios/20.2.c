/*
NOME: Mateus Filipe Moreira Silva
Matriculo: 20.2.8093
*/

#include <stdlib.h>
#include <stdio.h>

int main(){
    int numero;
    int mult = 1, primo = 0;

    printf("\n");

    for (int i = 0; i < 15; i++){
        
        printf("\nDigite um numero: ");
        scanf("%i", &numero);
        
        //Se o resto da divisao do numero por 2 for 0 entao ele entra na multiplicacao 
        if(numero%2 == 0){      
            mult = numero * mult;
            printf("\n%i e par\n", numero);
        }
        //Se numero for 2 soma aos primos 
        //O for chegar para checar os outros numero nao funciona para o 2
        if(numero == 2){
            primo = primo + 2;
            printf("\n%i e primo", numero);    
         }
        for (int j = 2; j < numero; j++){
            
            //se o numero tiver algum divisor entao sai so loop 
            //ou seja se a sua divisao por algum valor menor que ele (j) der 0 sai do loop
            if(numero%j == 0)
                break;

            //se o valor consegui chegar no ultimo valor de j (um a menos do que numero[]) sem sair do loop
            //entao ele e primo = nao tem nenhum divisor que nao seja ele mesmo e 1
            //Veja que nem testo o a divisao do numero por 1 (j começa em 2) e nem por ele mesmo j termina em numero[] - 1  
            if(j == numero - 1){
                primo = primo + numero;
                printf("\n%i e primo", numero);
            }
        }
    }
    
    printf("\n------------------------------------\n");

    //Print dos valores
    printf("\nA multiplicacao dos pares e %i", mult);
    printf("\nA soma dos primos e %i", primo);

}