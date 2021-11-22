#include <stdio.h>

int calculaPontos(int time[], int tamanhoTime, int ponto[], int tamanhoPonto, int identificador){
    int resultadoTime1 = 0, resultadoTime2 = 0;
    
    for (int i = 0; i < 20; i++){
        if(time[i] == 1){
            resultadoTime1 = resultadoTime1 + ponto[i];                    
        }
        else{
            resultadoTime2 = resultadoTime2 + ponto[i];
        }
    }
    
    if(identificador == 1){
        return resultadoTime1;
    }
    else{
        return resultadoTime2;
    }
}


int main(){
    int time[20] = {0}; 
    int ponto[20] = {0};
    int resultadoCasa, resultadoVisitante;

    for (int i = 0; i < 20; i++){
        printf("digite o time que pontuol: ");
        scanf("%i", &time[i]);

        printf("Digite a quantidade de porntos");
        scanf("%i", &ponto[i]);
    }

    resultadoCasa = calculaPontos(time, 200, ponto, 200, 1);
    resultadoVisitante = calculaPontos(time, 200, ponto, 200, 2);

    printf("\nO total de ponto do time da casa e %i", resultadoCasa);
    printf("\nO total de ponto do time visitante e %i", resultadoVisitante);

    
    return 0;    
}