//Faça um programa que receba dois números, calcule e mostre a subtração do primeiro número pelo segundo.

//Matrícula 20.2.8093
//Nome: Mateus Filipe Moreira Silva

int main(){
    
    float n1, n2, sub;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);

    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    sub = n1 - n2;

    printf("A subtração de %0.2f por %0.2f e %0.2f", n1, n2, sub);

    return 0;

}