
float calculoArea(float comprimento, float largura){
    float area;
    area = comprimento * largura;
    return area;
}

calculoLatas(float area){
    int latas;

    latas = area / 3;

    // if (area%3!=0)
    // {
    //     latas = latas + 1;
    // }
    
    return latas;
}

int main(){

    float comprimento, largura, area;
    int latas;


    printf("Digite o comprimento do telhado: ");
    scanf("%f", &comprimento);

    printf("Digite a largura do telhado: ");
    scanf("%f", &largura);

    area = calculoArea(comprimento, largura);
    latas = calculoLatas(area);

    printf("%d", latas);


    return 0;
}