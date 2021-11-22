// Nomes de autores em referências bibliográficas geralmente aparecem grafados em formato específico.  
// Por exemplo, um autor chamado "João José Silva" pode ter seu nome citadocomo "João J.SILVA", "SILVA, João José" ou  "SILVA, J.J.".

// a) Faça três funções distintas que recebam duas strings, s1 e s2.  Cada uma das funções deve atribuira s2o nomecontidoem s1em um dos formatos citados acima. 
// b) Elabore um programa que leia um nome e imprima-o em cada um dos formatos citados, chamando as funções implementadasna letra a.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void formato1(char strA[], char strB[]){
    
    for (int i = 0; i < 0; i++){
        
    }
    
    printf("A nova string e: ");
    puts(strA);
}

void formato2(char strA[], char strB[]){
    
    for (int i = 0; i < 0; i++){
        
    }
    
    printf("A nova string e: ");
    puts(strA);
}

void formato3(char strA[], char strB[]){
    
    for (int i = 0; i < 0; i++){
        
    }
    
    printf("A nova string e: ");
    puts(strA);
}

int main(){
    char strA[6];
    char strB[6];

    printf("Digite a string A: ");
    fgets(strA, 6, stdin);

    formato1(strA, strB);
    formato2(strA, strB);
    formato3(strA, strB);

    return 0;
    
}