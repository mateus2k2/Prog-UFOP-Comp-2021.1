//Faça uma função que receba um número inteiro e imprima o número lido é par ou impar.


void verificador(int N){
    
    if(N%2==0){
        printf("Numero e par");
    }
    else{
        printf("Numero e impar");         
    }

}

int main(){
    
    int N;

    printf("Digite N: ");
    scanf("%d", &N);

    verificador(N);

    return 0;
}