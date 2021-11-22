// Fazer uma função para imprimir uma string recebida como
// parâmetro sem os espaços em branco. Para isso, a string
// não deve ser modificada.

#include <stdio.h>
#include <string.h>

void retiraEspacos(char frase[]){

    int i = 0, k = 0; 
    int tamFrase, tamfraseSemEspaco, numeroEspacos;
    char fraseSemEspaco[1000]; 

    // for (int i = 0; frase[i] != '\0'; i++){
    //     if(frase[i] == ' ')
    //         numeroEspacos++;
    // }

    //tamFrase = strlen(frase);
    //tamfraseSemEspaco = tamFrase - numeroEspacos;
    

    for(i=0; frase[i]; i++){
     	
        frase[i] = frase[i+k];
 
     	if(frase[i]==' '|| frase[i]=='\t'){
		    k++;
		    i--;
	    }
    }

    //fraseSemEspaco[tamfraseSemEspaco] = '\0';

    printf("Frase sem espacos: "); 
 	printf("%s", frase); 

} 
 
int main(){
    char frase[1000]; 
    
    printf("Entre com a frase: ");
    gets(frase);
 
    retiraEspacos(frase);
     
    return 0;
}
