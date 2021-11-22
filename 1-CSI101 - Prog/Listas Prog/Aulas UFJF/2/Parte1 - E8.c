

int main() {
    float lado1,lado2,lado3;
    float perimetro;
    
    printf("TRIANGULO\n");
    printf("Digite os lados:");
    scanf("%f%f%f",&lado1,&lado2,&lado3);
    
    perimetro=lado1+lado2+lado3;
    
    printf("Perimetro:%f",perimetro);
    
    return 0;
}