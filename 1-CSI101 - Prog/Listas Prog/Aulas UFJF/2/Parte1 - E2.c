
int main(){

    int dias, horas, minutos, segundos, restoSeg;

    segundos = 200000;

    minutos = segundos / 60;
    horas = minutos / 60;
    dias = horas / 24;
    minutos = minutos % 60;
    restoSeg = segundos % 60;

    printf("%i segundos equivalem a %i dias, %i horas, %i minutos e %i segundos", segundos, dias, horas, minutos, restoSeg);

    return 0;

}