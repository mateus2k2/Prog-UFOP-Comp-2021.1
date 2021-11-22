
#include <stdio.h>

int saoPositivos(int N1, int N2){
    
    int check;
    
    if(N1 > 0 && N2 > 0){
        check = 1;
    }
    else{
        check = 0;
    }

    return check;
    
}

int main(){

    int N1, N2, resultado;
    printf("Digite o primerio numero: ");
    scanf("%d", &N1);
    
    printf("Digite o segundo numero: ");
    scanf("%d", &N2);
    
    resultado = saoPositivos(N1, N2);  

   if (resultado > 0){
       printf("Ambos os valores sao positivos");
   }
   else{
       printf("Ao menos um dos valores eh negativo");
   }
    
    return 0;
}