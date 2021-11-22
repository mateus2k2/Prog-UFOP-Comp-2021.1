//Faça um programa que receba dois números, calcule e mostre a divisão do primeiro número pelo segundo. Sabe-se que o segundo número não pode ser zero, portanto, será necessário fazer a validações.

//Matrícula 20.2.8093
//Nome: Mateus Filipe Moreira Silva

int main(){
    
    float n1, n2, div;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);

    printf("Digite o segundo numero diferente de zero: ");
    scanf("%f", &n2);

    if(n2 < 0){
        printf("O segundo numero deve ser maior que zero");
        printf("Digite novamente o segundo numero diferente de zero: ");
        scanf("%f", &n2);
    }
    
    else{
        div = n1 / n2;
        printf("A divisao de %0.2f por %0.2f e %0.2f", n1, n2, div);
    }

    
    return 0;

}