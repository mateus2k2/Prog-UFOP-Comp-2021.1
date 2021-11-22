// Você deverá fazer um programa que receberá vinte valores e os armazenará em um vetor. Este vetor então, deve ser separado em doi vetores de 5 posições chamados P e I.
// O vetor P deverá conter os número pares e o vetor I os número ímpares. Como o tamanho dos vetores não será suficiente para armazenar todos os números,
// deve-se sempre verificar se já estão cheios. Se P ou I estiverem cheios, você deverá mostrá-los e então recomeçar o preenchimento da primeira posição. 
// Quando terminar o processamento dos dados, você deverá mostrar o conteúdo dos vetores P e I.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int main(){
    int vet[20] = {123, 455, 455, 234, 5848, 8, 57, 48, 49, 29458, 768, 94, 427, 4659, 69, 708536, 45, 643, 4325, 345};
    int P[5] = {0}, I[5] = {0};

    int contI = 0, contP = 0;
    int j = 0, k = 0, t = 0, l = 0;

    for (int i = 0; i < 20; i++){
        //Preenche o vetor vet[]
        printf("Digite o numero: ");
        scanf("%i", &vet[i]);

        //Conta os numero de numeros pares e o numero de impares
        if(vet[i]%2 == 0)
            contP++;
        else    
            contI++;
    }

    printf("\n");
    printf("\n******************************************************************************************************************");

    for (int i = 0; i < 5; i++){
        
        for (l; l < 20;){
            if(vet[l]%2 == 0){
                //Preenche o vetor P[] com os pares
                P[j] = vet[l];
                //Conta os indices do vetor P[]
                j++;
                //Conta a quantidade de pares = quantidade de vezes que entrou nesse if
                t++;
        }            
        //Conta os indice do vetor vet[]
        l++;
            //Checa de encheu o vetor P
            if(j == 5){
                //Reseta o j (cont do indice de P[])
                j = 0;
                //Se encher sai do loop
                break;
        }
}
    //Se t contou todos os pares então sai do loop por completo 
    if(t == contP){
        break;
    }
    
    //Toda vez que encher o vetor P ele é printado
    printf("\n");
    printf("\nO VETOR P ESTA CHEIO");
    for (int i = 0; i < 5; i++){
            printf("\nO valor %i e par e esta no vetor P", P[i]);
    }    
}

    //Print do vetor p[] onde ele terá elementos repetidos ate o indice igual ao resto da divisão de t(numero de pares) com 5(Tamanho do vetor P) 
    printf("\n");
    printf("\nO VALOR FINAL DO VETOR P: (OS %i PRIMEIRO SAO OS ULTIMOS PARES NAO REPETIDOS DO VETOR P)", t%5);
    for (int i = 0; i < 5; i++){
        printf("\nO valor %i e par", P[i]);
        
        //Coloca os uma linha entre os repetidos e os novos
        if(i == (t%5)-1)
            printf("\n-------------------");
}

    printf("\n");
    printf("\n******************************************************************************************************************");

    j = 0;
    t = 0;
    l = 0;


    for (int i = 0; i < 5; i++){
        
        for (l; l < 20;){
            if(vet[l]%2 != 0){
                //Preenche o vetor I[] com os impares
                I[j] = vet[l];
                //Conta os indices do vetor I[]
                j++;
                //Conta a quantidade de impares = quantidade de vezes que entrou nesse if
                t++;
        }    
        //Conta os indice do vetor vet[]
        l++;
            //Checa de encheu o vetor I
            if(j == 5){
                //Reseta o j (cont do indice de I[])
                j = 0;
                //Se encher sai do loop
                break;
        }
}

    //Se t contou todos os impareres então sai do loop por completo 
    if(t == contI){
        break;
    }
    
    //Toda vez que encher o vetor I ele é printado
    printf("\n");
    printf("\nO VETOR I ESTA CHEIO");
    for (int i = 0; i < 5; i++){
            //Se O elemento nao for zero imprime o vetor
            if(I[i] != 0){
                printf("\nO valor %i e impar e esta no vetor I", I[i]);
        }
    }    
}

    //Print do vetor p[] onde ele terá elementos repetidos ate o indice igual ao resto da divisão de t(numero de impares) com 5(Tamanho do vetor I) 
    printf("\n");
    printf("\nO VALOR FINAL DO VETOR I: (OS %i PRIMEIRO SAO OS ULTIMOS IMPARES NAO REPETIDOS DO VETOR I)", t%5 );
    for (int i = 0; i < 5; i++){
        //Se O elemento nao for zero imprime o vetor I
        if(I[i] != 0){
            printf("\nO valor %i e Impar", I[i]);
            //Coloca os uma linha entre os repetidos e os novos
            if(i == (t%5)-1)
                printf("\n-------------------");
    }
}
    return 0;
}