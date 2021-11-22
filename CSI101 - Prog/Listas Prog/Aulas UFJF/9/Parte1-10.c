// Considerando a estrutura para representar um vetor no R3.

// typedef struct{
//     float x; 
//     float y; 
//     float z;
// }Vetor; 

// Implemente uma função para calcular e retornar o resultado das operações de soma, subtração e produto vetorial entre dois vetores. 
// Deverá ser desenvolvido uma função para cada uma das operações. Faça um programa para ler 2 vetores calcular a soma, subtração e produto vetorial deles e imprimir na tela. 

// Dica produto vetorial: 
// x = y1*z2 - z1*x2; 
// y =  z1*x2 - x1*z2; 
// z =  x1*y2 - y1*x2;

typedef struct{
    float x; 
    float y; 
    float z;
}Vetor; 


Vetor calculaSoma(Vetor vet[]){
    Vetor soma;

    soma.x = (vet[0].x + vet[1].x);
    soma.y = (vet[0].y + vet[1].y); 
    soma.z = (vet[0].z + vet[1].z);
    
    return soma;
}

Vetor calculaSubtracao(Vetor vet[]){
    Vetor sub;

    sub.x = (vet[0].x - vet[1].x);
    sub.y = (vet[0].y - vet[1].y); 
    sub.z = (vet[0].z - vet[1].z); 
    
    return sub;
}

Vetor calculaProduto(Vetor vet[]){
    Vetor mult;

    mult.x = (vet[0].y * vet[1].z) - (vet[0].z*vet[1].x);
    mult.y = (vet[0].z * vet[1].x) - (vet[0].x*vet[1].z); 
    mult.z = (vet[0].z * vet[1].y) - (vet[0].y*vet[1].x); 
    
    return mult;
}

int main(){
    Vetor vet[2];
    Vetor soma, subtracao, mult;

    for (int i = 0; i < 2; i++){
        printf("Digite o valor de x do vetor %i: ", i+1);
        scanf("%f", &vet[i].x);
        printf("Digite o valor de y do vetor %i: ", i+1);
        scanf("%f", &vet[i].y);
        printf("Digite o valor de z do vetor %i: ", i+1);
        scanf("%f", &vet[i].z);
    }

    soma = calculaSoma(vet);
    subtracao = calculaSubtracao(vet);
    mult = calculaProduto(vet);

    printf("\nSOMA");
    printf("\nx = %.2f", soma.x);
    printf("\ny = %.2f", soma.y);
    printf("\nz = %.2f", soma.z);

    printf("\n");

    printf("\nSUBTRACAO");
    printf("\nx = %.2f", subtracao.x);
    printf("\ny = %.2f", subtracao.y);
    printf("\nz = %.2f", subtracao.z);

    printf("\n");

    printf("\nMULTIPLICACAO");
    printf("\nx = %.2f", mult.x);
    printf("\ny = %.2f", mult.y);
    printf("\nz = %.2f", mult.z);
    

}