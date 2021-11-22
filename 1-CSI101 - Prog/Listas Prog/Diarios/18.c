/*
NOME: Mateus Filipe Moreira Silva
Matriculo: 20.2.8093
*/

/*
OBJETIVOS DO PROGRAMA
Recebe o valor de dois angulos de um triangulo (ang1, ang2) e calculo o terceiro pela formula (ang3 = 180 -(ang1 + ang2)) 
verifica se a soma dos dois angulos forem maiores que 180 ou se sao negativos, se isso acontecer entao os valores inputados sao invalidos, se nao entao mostra o valor do terceiro 3  
*/

int main(){

    float ang1, ang2, ang3;

    printf("Digite o valor do primerio angulo: ");
    scanf("%f", &ang1);

    printf("Digite o valor do segundo angulo: ");
    scanf("%f", &ang2);

    ang3 = 180 -(ang1 + ang2);

    if(ang1 + ang2 < 180 && ang1 > 0 && ang2 > 0){
        printf("O valor do terceiro angulo e %0.2f", ang3);            
    }
    else{
        printf("\n---------------------------------Valores invalidos------------------------------------");
        printf("\nO valor da soma do angulo 1 com o angulo 2 e maior que 180 ou um ou os dois e negativo");
    }

    return 0;

}