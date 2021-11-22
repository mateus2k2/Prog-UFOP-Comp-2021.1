// Faça uma função que receba como parâmetros um vetor
// de tamanho 5 e um número inteiro entre 0 e 99999, faça
// uma função que inicialize o vetor com cada dígito do
// número. Por exemplo, se o número for 4723, o vetor deverá,
// ao final, conter os valores {0,4,7,2,3}.

int main(){
    int vet[5];
    int numero;
    int div = 10;

    printf("Digite o numero inteiro entre 0 e 99999: ");
    scanf("%i", &numero);

    for (int i = 0; i < 5; i++){
        vet[i] = (numero / (100000/div)) % 10;
        div = div * 10;
    } 

    for (int i = 0; i < 5; i++){
        printf("\nO numero decomposto e %i", vet[i]);
    }
    
    return 0;

}