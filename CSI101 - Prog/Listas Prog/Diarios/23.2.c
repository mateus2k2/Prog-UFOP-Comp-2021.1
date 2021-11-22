// Criar uma função elimina_espacos que elimine os espaços em branco de uma cadeia de caracteres. A função deverá receber dois arrays de caracteres, 
// sendo que o primeiro será o array de destino e o segundo o array de origem. Para o texto de entrada “Joaquim Silva Pereira”, deve-se salvar o seguinte texto no array de destino: “JoaquimSilvaPereira”.


#include <stdio.h>
#include <string.h>

void elimina_espacos(char frase[], char fraseSemEspaco[]){

    int i = 0, k = 0;     

    strcpy(fraseSemEspaco, frase);

    for(i = 0; frase[i]; i++){
     	
        fraseSemEspaco[i] = fraseSemEspaco[i+k];
 
     	if(fraseSemEspaco[i]==' '|| fraseSemEspaco[i]=='\t'){
		    k++;
		    i--;

	    }
    }

    printf("Frase sem espacos: "); 
 	puts(fraseSemEspaco); 

} 
 
int main(){
    char frase[1000]; 
    char fraseSemEspaco[1000];
    
    printf("Entre com a frase: ");
    gets(frase);
 
    elimina_espacos(frase, fraseSemEspaco);
     
    return 0;
}