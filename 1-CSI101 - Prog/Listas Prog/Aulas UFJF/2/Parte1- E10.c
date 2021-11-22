
int main(){

    int horas, minutos, segundos, restoSeg, restoMin;

    printf("Digite um valor em segundos: ");
    scanf("%i", &segundos);

    minutos = segundos / 60;
    horas = minutos / 60;
    restoMin = minutos % 60;
    restoSeg = segundos % 60;

    printf("%i segundos equivalem a %i horas, %i minutos e %i segundos", segundos, horas, restoMin, restoSeg);

    return 0;

}