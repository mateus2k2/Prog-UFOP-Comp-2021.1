//Faça um programa que receba três números, calcule e mostre a multiplicação desses números

//Matrícula 20.2.8093
//Nome: Mateus Filipe Moreira Silva

int main(){
    
    float n1, n2, n3, mult;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);

    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    printf("Digite o terceiro numero: ");
    scanf("%f", &n3);

    mult = n1 * n2 * n3;

    printf("A multiplicação de %0.2f por %0.2f por %0.2f e %0.2f", n1, n2, n3, mult);

    return 0;

}