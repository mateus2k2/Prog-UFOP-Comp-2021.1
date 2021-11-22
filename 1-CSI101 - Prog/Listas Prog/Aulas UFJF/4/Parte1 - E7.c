

void calculo(int valor){

    switch (valor) {
    case 1: printf("Domingo");
    break;
    case 2: printf("Segunda");
    break;
    case 3: printf("Terca");
    break;
    case 4: printf("Quarta");
    break;
    case 5: printf("Quinta");
    break;
    case 6: printf("Sexta");
    break;
    case 7: printf("Sabado");
    break;
    default: printf("Codigo invalido");
}
}

int main(){

    int valor;
    
    printf("Digite o valor: ");
    scanf("%d", &valor);

    calculo(valor);

    return 0; 

}