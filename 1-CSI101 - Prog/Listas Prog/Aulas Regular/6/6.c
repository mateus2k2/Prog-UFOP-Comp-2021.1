#include <stdlib.h>
#include <stdio.h>

int main(){
    int i, numeroOperario, codOperario, codMaior; 
    int totalPecas, numeroPecas, sexo, sexoMaior;
    int numeroHomens=0, numeroMulher=0, pecasHomem=0, pecasMulher=0;
    float totalSalario = 0, salarioMinimo, salario, salarioMaior;
    float mediaHomem, mediaMulher;

    system("cls");
    
    printf("\n----------------------------------------------------\n");

//ENTRADAS 1

    printf("Digite o numero de operarios da empresa: ");
    scanf("%i", &numeroOperario);

    printf("Digite o salario minimo: ");
    scanf("%f", &salarioMinimo);
    
    printf("\n----------------------------------------------------\n");

    for(i=1; i<=numeroOperario; i++){

//ENTRADAS 2

        printf("\nDIGITE OS DADOS DE UM NOVO FUNCIONARIO\n");

        printf("Digite seu codigo: ");
        scanf("%i", &codOperario);

        printf("Digite o numero de pecas produzidas no mes: ");
        scanf("%i", &numeroPecas);

        printf("Digite seu sexo = 1 pra homem ou 2 pra mulher: ");
        scanf("%i", &sexo);

//VERIFICA SEXO

        if(sexo == 1 || sexo == 2){
            if (sexo==1){
                numeroHomens++;
                pecasHomem= pecasHomem + numeroPecas;
            }

            if (sexo==2){
                numeroMulher++;
                pecasMulher= pecasMulher + numeroPecas;            
            } 
        }
        else{
            printf("O codigo do sexo inserido foi invalido\n");
            return 0;   
        }

//CALCULO SALARIO

        if (numeroPecas>=0&&numeroPecas<=35){
            salario = salarioMinimo;
        }
        if (numeroPecas>=36&&numeroPecas<=59){
            salario = salarioMinimo + (0.05 *salarioMinimo) * (numeroPecas - 35);
        }
        if (numeroPecas>=60){
            salario = salarioMinimo + (0.10 *salarioMinimo) * (numeroPecas - 35);
        }

        totalPecas = pecasHomem+pecasMulher;

        totalSalario = totalSalario + salario;

//CODIGO MAIORES

        if(i == 1){
            codMaior = codOperario;
            salarioMaior = salario;
            sexoMaior = sexo;
        }
        else{
            if(salario > salarioMaior){
                codMaior = codOperario;
                salarioMaior = salario;
                sexoMaior = sexo;
                }
        }

//PRINF INFO AUTAL

        printf("\nFUNCIONARIO ATUAL\n");
        printf("\nSalario do funcionario atual: %0.2f", salario);
        printf("\nCodigo do funcionario atual: %i", codOperario);

        printf("\n----------------------------------------------------\n");
    }   

//MEDIA

    mediaMulher = pecasMulher/numeroMulher;
    mediaHomem = pecasHomem/numeroHomens;

//SAIDAS

    printf("\nTOTAL PESAS E SALARIOS\n");
    printf("O toal de pecas sao: %i\n", totalPecas);
    printf("O total da folha de pagamento da empresa e: %0.2f\n", totalSalario);

    printf("\nMEDIAS PEC AS HOMENS E MULHERES\n");
    printf("A media de pecas por mulher e: %.2f\n", mediaMulher);
    printf("A media de pecas por homens e: %.2f\n", mediaHomem);

    printf("\nMAIORES SALARIOS\n");
    printf("O maior salario e de: %0.2f\n", salarioMaior);
    printf("O codigo do maior e: %i\n", codMaior);
   
//DETERMINAR SEXO DA PESSOA COM MAIOR SALARIO

    if(sexoMaior == 1)
        printf("O funcionario com maior salario tem sexo masculino\n");
    else
        printf("O funcionario com maior salario tem sexo feminino\n");

    return 0;

}