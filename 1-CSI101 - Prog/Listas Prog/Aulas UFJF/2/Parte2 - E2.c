

int main(){

    float peso, altura, imc;

    printf("INDICE DE MASSA CORPORAL\n");
    printf("Digite seu peso: ");
    scanf("%f", &peso);
    printf("Digite a sua altura: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("Valor do IMC: %f\n", imc);
    return 0;

}