#include <stdio.h>

int calculo(int x){

    int xfixo;

    xfixo = x;

    while (x > 0){        
    
        if(xfixo%x==0){
           printf("%d ", x);
        }        
        x--;
    }

return 0;

}


int main(){

    float x;

    printf("Digite o numero: ");
    scanf("%f", &x);

    calculo(x);

    return 0;
}
