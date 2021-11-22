
#include <stdio.h>

int calculo(int segundo){

    int hora, minutos, restoSeg, restoMin;

    minutos = segundo / 60;
    hora = minutos / 60;
    restoSeg = segundo % 60;
    restoMin = minutos % 60;

    
    printf("\nCONVERSAO DE SEGUNDOS EM HORAS, MINUTOS E SEGUNDOS");
    printf("\nTempo total em segundos: %d", segundo);
    printf("\nEquivale a: %d horas, %d minutos e %d segundos", hora, restoMin, restoSeg);     
}

int main(){
    
    int segundo;

    printf("Digite o valor dos segundos: ");
    scanf("%d", &segundo);

    calculo(segundo);

    return 0;

}