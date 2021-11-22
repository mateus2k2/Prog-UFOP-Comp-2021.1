/*
Faça uma função que converta uma quantidade de horas digitadas pelo usuário em minutos e retorne esta quantidade. Faça a leitura da quantidade de horas na função principal.
*/



int ClaculoHoras (int horas){
    
    int ClaculoHoras = horas * 60;

    return ClaculoHoras;
}

int main(){

    int quantidadeHoras, quantidadeMinutos;
    printf("Digite a quantidade de horas: ");
    scanf("%d", &quantidadeHoras);

    quantidadeMinutos = ClaculoHoras (quantidadeHoras);

    printf("A convercao de %d horas para minutos e: %d ", quantidadeHoras, quantidadeMinutos);

    return 0;
}
