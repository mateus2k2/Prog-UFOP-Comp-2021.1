#include <stdio.h>

int main(){
   int numeroMeio = 2;

    for (numeroMeio = 2; numeroMeio % 2 == 0; numeroMeio){
        printf("Digite o valor de x: "); scanf("%i", &numeroMeio);
        if(numeroMeio % 2 == 0)
            printf("Erro: x deve ser impar.\n");
        printf("\n");
    }


    for (numeroMeio; numeroMeio > 0; numeroMeio = numeroMeio - 2){
       
        //primeira metade
        for (int i = 0; i <= numeroMeio/2 + 1; i++){
            
            for (int j = 1; j <= (numeroMeio/2 + 1)-i; j++){
                printf("  ");
            }

            for (int j = 1; j <= 2*i - 1; j++){
                printf("* ");
            }
            printf("\n");
        }

        //segunda metade
        for (int i = (numeroMeio/2 + 1)-1; i >= 1; i--){
                    
            for (int j = 1; j <= (numeroMeio/2 + 1)-i; j++){
                printf("  ");
            }

            for (int j = 1; j <= 2*i-1; j++){
                printf("* ");
            }
            printf("\n");
        }

        printf("\n");
    }
   

 
    return 0;
}
