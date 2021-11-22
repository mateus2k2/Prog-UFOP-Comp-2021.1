//Você deve fazer um programa que irá preencher um vetor com dez números inteiros, calcular e mostrar os números pares.

/*
NOME: Mateus Filipe Moreira Silva
Matriculo: 20.2.8093
*/

#include <stdio.h>
#include <string.h>

int main(){
    int numeros[10], pares[10];
    int j = 0;

    for (int i = 0; i < 10; i++){
        pares[i]=-1;
    }
    

    //loop com 10 etapas
    for (int i = 0; i < 10; i++)    {
        //Pega oo números do traclado e armazena no vetor numeros[]
        printf("Digite um numero: ");
        scanf("%i", &numeros[i]);

        //Verifica se o numero imputado e par se for coloca ele no vetor pares[]
        if(numeros[i]%2==0){
            pares[j] = numeros[i];
            j++;
        }
    }
    
    printf("\n");

    for (int i = 0; i < 10; i++){
        //Como o vetor pares foi iniciado com -1
        //Se o vetor pares[i] for diferente de -1 ele e printado
        //Quanto o primeiro -1 aparece dentro do vetor pares[i] sai do loop 
        if(pares[i]!=-1)
            printf("\nO numero %i e par", pares[i]);
        else
            break;
    }

    return 0;   

}