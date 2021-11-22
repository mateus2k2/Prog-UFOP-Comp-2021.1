#include <stdio.h>

int main(){
   int i, j, r=2;

    while (r % 2 == 0){
        printf("Digite o valor de x: "); scanf("%i", &r);
        if(r % 2 == 0)
            printf("Erro: x deve ser impar.\n");
        printf("\n");
    }
   
   //primeira metade
    i = 0;
    while(i <= (r/2 + 1)){
        j = 1;
        while(j <= (r/2 + 1)-i){
            printf("  ");
            j++;
        }
    
        j = 1;
        while(j <= 2*i-1){
            printf("* ");
            j++;
        }
        printf("\n");
        i++;
    }

    //segunda metade
    i = (r/2 + 1)-1;
    while(i >= 1){
        j = 1;
        while(j <= (r/2 + 1)-i){
            printf("  ");
            j++;
        }
        j = 1;
        while(j <= 2*i-1){
            printf("* ");
            j++;
        }
        printf("\n");
        i--;
    }
 
    return 0;
}
