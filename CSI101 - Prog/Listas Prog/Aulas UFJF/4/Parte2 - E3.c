#include <stdio.h>

float calculaPesoIdeal(char sexo, float altura){

float pesoIdeal;

if (sexo=='M'){
    pesoIdeal = (72.7 * altura) - 58;
}
else{
    pesoIdeal = (62.1 * altura) - 44.7;
}

return pesoIdeal;

}

int main(){
    
    float altura, pesoIdeal, peso;
    char sexo;
    
    printf("Digite o seu sexo, 1 para M ou 2 para F: ");
    scanf("%s", &sexo);

    printf("Digite a seua altura: ");
    scanf("%f", &altura);

    printf("Digite seu peso atual: ");
    scanf("%f", &peso);

    pesoIdeal = calculaPesoIdeal(sexo, altura);

    printf("Seu peso ideal e de %f", pesoIdeal);

    if ('peso > 0') {
    if(peso > pesoIdeal)
        printf("\nVoce esta assima do peso ideal");
    if(peso == pesoIdeal)
        printf("\nVoce esta no peso ideal");
    if(peso < pesoIdeal)
        printf("\nVoce esta abaixo do peso ideal");
    }
    else{
        printf("Peso invalido");
    }
    

    return 0;
}