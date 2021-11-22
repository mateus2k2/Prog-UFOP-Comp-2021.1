
#include <stdio.h>


int calculo(int codigoo){

    switch (codigoo) {
    case 101: printf("Voce e um vendedor");
    break;
    case 102: printf("Voce e um atendente");
    break;
    case 103: printf("Voce e um Auxiliar tecnico");
    break;
    case 104: printf("Voce e um assistente");
    break;
    case 105: printf("Voce e um Coordenador de Grupo");
    break;
    case 106: printf("Voce e um Gerente");
    break;

    default: printf("Codigo invalido");
}

return 0;

}

int main(){

    int codigo;

    printf("Digite o seu codigo: ");
    scanf("%d", &codigo);

    calculo(codigo);

    return 0 ;
} 