#include <stdio.h>
#include <string.h>

void quebrar(char frase[]){
    char vogais[20], consoantes[20];
    int v = 0, c = 0; 

    for (int i = 0; frase[i] != '\0'; i++){
       
        if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u' || frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U'){
            vogais[v] = frase[i];
            v++;                 
        }
        if(frase[i] != 'a' && frase[i] != 'e' && frase[i] != 'i' && frase[i] != 'o' && frase[i] != 'u' && frase[i] != 'A' && frase[i] != 'E' && frase[i] != 'I' && frase[i] != 'O' && frase[i] != 'U'){
            consoantes[c] = frase[i];
            c++;        
        }
        
    }
    vogais[v] = '\0';
    consoantes[c] = '\0';
    
    printf("Vogais: ");
    puts(vogais);
    
    printf("Consoantes: ");
    puts(consoantes);


}

int main(){
    int frase[50];

    printf("Digite a frase: ");
    fgets(frase, 50, stdin);

    quebrar(frase);

    return 0;
}