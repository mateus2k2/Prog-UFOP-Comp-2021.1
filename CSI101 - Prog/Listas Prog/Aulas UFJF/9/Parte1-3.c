// Considerando a estrutura do exercício (2) e a declaração: medidas joao, maria;    
// → Escreva instruções para atribuir: 1.78 à altura de joao; 1.64 à altura demaria; 75 ao peso de joao; 59 ao peso de maria.    
// → Escreva um conjunto de instruções para imprimir a  média das alturas e a média dos pesos de joao e maria

typedef struct{
    float peso;
    float altura;
}medida;

int main(){
    medida joao, maria;

    joao.peso = 75;
    joao.altura = 1.78;

    maria.peso = 59;
    maria.altura = 1.64;

    printf("\nA altura de maria e %.2f || O peso de maria e %.2f", maria.altura, maria.peso);
    printf("\nA altura de joao e %.2f || O peso de joao e %.2f", joao.altura, joao.peso);


}


