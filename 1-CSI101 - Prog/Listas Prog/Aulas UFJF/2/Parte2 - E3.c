int main(){

    float saldoInicial, salario, retirada1, retirada2, retirada3;

    printf("EXTRATO BANCARIO\n");

    printf("Saldo inicial: R$");
    scanf("%f", &saldoInicial);
    printf("Salario: R$");
    scanf("%f", &salario);
    
    printf("Saldo parcial: %f\n", saldoInicial + salario);

    printf("----------------------------\n");

    printf("1a Retirada: R$");
    scanf("%f", &retirada1);
    printf("Saldo Parcial: %f\n", (saldoInicial + salario) - retirada1);

    printf("----------------------------\n");

    printf("2a Retirada: R$");
    scanf("%f", &retirada2);
    printf("Saldo Parcial: %f\n", ((saldoInicial + salario) - retirada1) - retirada2);

    printf("----------------------------\n");

    printf("3a Retirada: R$");
    scanf("%f", &retirada3);
    printf("Saldo final: %f", (((saldoInicial + salario) - retirada1) - retirada2) - retirada3);

    return 0;

}