#include <stdio.h>


float calculo(float x, float y, float z){

    if (x < y + z && y < x + z && z < x + y){
        printf("Os numero formam os lados de um triangulo");
        }
    else{
        printf("Os numero nao formam os lados de um triangulo");
    }

}


int main(){
    
    float x, y, z;
    
    printf("Digite primeiro numero: ");
    scanf("%f", &x);

    printf("Digite segundp numero: ");
    scanf("%f", &y);

    printf("Digite terceiro numero: ");
    scanf("%f", &z);

    calculo(x, y, z);

    return 0;
}