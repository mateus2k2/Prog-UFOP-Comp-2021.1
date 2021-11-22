// Implemente uma função que receba um vetor de inteiros, seu tamanho e um valor x e retorne o índice da 
// primeira posição do vetor que contém o valor x. Se o valor x não estiver no vetor, a função deve retornar o valor -1.

int calcula(int n1[], int tamN1, int x){
    int indiceX = 0;

    for (int i = 0; i < tamN1; i++){
        if(n1[i] == x){
            indiceX = i;
            break;
        }

        if(i == tamN1 - 1)
            return -1;
    }
    
    return indiceX;

}

int main(){
    int n1[5], x, indiceX;

    printf("Digie o valor a procurar no vetor: ");
    scanf("%i", &x);

    for (int i = 0; i < 5; i++){
        printf("Digite um valor: ");
        scanf("%i", &n1[i]);
    }
    
    indiceX = calcula(n1, 5, x);

    printf("O indice do valor %i e %i", x, indiceX);

    return 0;
    
}