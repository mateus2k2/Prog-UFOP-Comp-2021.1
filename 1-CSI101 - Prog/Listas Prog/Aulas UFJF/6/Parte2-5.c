
int main(){
    int vetor[100] = {0};
    int vetorPrimeiros[3] = {0};
    int contPreenchidos = 0;

    int i = 0;

    printf("\nDIGITE O VALOR ATE 100 NO VETOR\n");

    while(i < 100){
        printf("digite o valor do vetor: ");
        scanf("%i", &vetor[i]);

        if(vetor[i] < 0){
            vetor[i] = 0;
            break;
        }

        //Contar os vetores que forom preenchidos
        if(vetor[i] > 0)
            contPreenchidos = contPreenchidos + 1;

        i++;
    }    

    //Quardar quais os primeiros valores
    for (int i = 0; i < 3; i++){
        vetorPrimeiros[i] = vetor[i];
    }


    //Inverter
    for (int i = 0; i < 3; i++){
        vetor[i] = vetor[contPreenchidos - i];
    }

    for (int i = 0; i < 3; i++){
        vetor[contPreenchidos - i] = vetorPrimeiros[i];
    }



    for (int i = 0; i <= contPreenchidos; i++){
            printf("\nO vetor de indice %i e %i", i, vetor[i]);
    }
    
    

}