#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

int verifica(data datas[]){
    int final;

    final = (abs(datas[1].ano - datas[0].ano))*365 + (abs(datas[1].mes - datas[0].mes))*30 + abs(datas[1].dia - datas[0].dia);

    return final;
}

int main(){
    data datas[2];
    int separa;

    for (int i = 0; i < 2; i++){
        printf("\nDATA %i\n", i+1);

        printf("Dia: ");
        scanf("%i", &datas[i].dia);

        printf("Mes: ");
        scanf("%i", &datas[i].mes);

        printf("Ano: ");
        scanf("%i", &datas[i].ano);

    }

    separa = verifica(datas);

    printf("\nQUANTIDADE DE DIA QUE SEPARA AS DATAS: %i\n", separa);

    return 0;    

}