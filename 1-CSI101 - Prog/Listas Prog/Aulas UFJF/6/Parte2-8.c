#include <stdio.h>
#define TAMANHO 10

void scanNotas(int P1[], int tamP1, int P2[], int tamP2, int P3[], int tamP3, int notaFinal[], int tamNotaFinal){

    int i = 0, j = 0;

    for (i = 0; i < TAMANHO; i++){
        printf("\n------------------------------------\n");
        printf("\nVEZ DO ALUNO %i DIGITAR SUAS NOTAS: \n", i);
        
        printf("Digite a nota da prova 1: ");
        scanf("%i", &P1[i]);

        printf("Digite a nota da prova 2: ", P2[i]);
        scanf("%i", &P2[i]);
        
        printf("Digite a nota da prova 3: ", P3[i]);
        scanf("%i", &P3[i]);
    }
}

//-------------------------------------------------------------------------------------------------------
void calculaNotaFinal(int P1[], int tamP1, int P2[], int tamP2, int P3[], int tamP3, int notaFinal[], int tamNotaFinal){
   
    for (int i = 0; i < TAMANHO; i++){
        notaFinal[i] = (P1[i] + P2[i] + 2*(P3[i]) ) / 4 ;
    }
    
}

//-------------------------------------------------------------------------------------------------------
void printNotaFinal(int P1[], int tamP1, int P2[], int tamP2, int P3[], int tamP3, int notaFinal[], int tamNotaFinal){

    printf("\nAS NOTAS FINAIS ESTAO A SEGUIR");
    for (int i = 0; i < TAMANHO; i++){
        printf("\nO aluno %i teve nota final %i", i, notaFinal[i]);
    }
    menu(P1, TAMANHO, P2, TAMANHO, P3, TAMANHO, notaFinal, TAMANHO);

}

//-------------------------------------------------------------------------------------------------------
void verificaNotaFinalAcima(int P1[], int tamP1, int P2[], int tamP2, int P3[], int tamP3, int notaFinal[], int tamNotaFinal){

    printf("\nNOTAS ACIMA OU IGUAL A 60");
    for (int i = 0; i < TAMANHO; i++){
        if(notaFinal[i] >= 60){
            printf("\nO aluno %i teve nota iqual ou acima de 60 = %i", i, notaFinal[i]);
        }
    }
    menu(P1, TAMANHO, P2, TAMANHO, P3, TAMANHO, notaFinal, TAMANHO);
}

//-------------------------------------------------------------------------------------------------------
void verificaNotaFinalAbaixo(int P1[], int tamP1, int P2[], int tamP2, int P3[], int tamP3, int notaFinal[], int tamNotaFinal){

    printf("\nNOTAS ABAIXO DE 60");
    for (int i = 0; i < TAMANHO; i++){
        if(notaFinal[i] < 60){
            printf("\nO aluno %i teve nota abaixo de 60 = %i", i, notaFinal[i]);
        }
    }
    menu(P1, TAMANHO, P2, TAMANHO, P3, TAMANHO, notaFinal, TAMANHO);
   
}

//-------------------------------------------------------------------------------------------------------
void imprimirvetores(int P1[], int tamP1, int P2[], int tamP2, int P3[], int tamP3, int notaFinal[], int tamNotaFinal){
    
    printf("\nNOTAS DA PROVA 1");
    for (int i = 0; i < TAMANHO; i++){
        printf("\nO aluno de indice %i tem nota %i na prova 1", i, P1[i]);
    }

    printf("\n");

    printf("\nNOTAS DA PROVA 2");
    for (int i = 0; i < TAMANHO; i++){
        printf("\nO aluno de indice %i tem nota %i na prova 2", i, P2[i]);
    }

    printf("\n");

    printf("\nNOTAS DA PROVA 3");
    for (int i = 0; i < TAMANHO; i++){
        printf("\nO aluno de indice %i tem nota %i na prova 3", i, P3[i]);
    }

    menu(P1, TAMANHO, P2, TAMANHO, P3, TAMANHO, notaFinal, TAMANHO);
    
}


//-------------------------------------------------------------------------------------------------------
void menu(int P1[], int tamP1, int P2[], int tamP2, int P3[], int tamP3, int notaFinal[], int tamNotaFinal){

    int escolha;

    printf("\n------------------------------------\n");

    printf("\nOQUE DESEJA FAZER?");
    printf("\n1 Para Imprimir um dos vetores de notas");
    printf("\n2 Para imprimir a nota final dos alunos");
    printf("\n3 para imprimir os alunos com notas abaixo de 60");
    printf("\n4 para imprimir os alunos com notas acima de 60");
    printf("\n5 para sair"); 
    
    printf("\nDigite a opsao: ");
    scanf("%i", &escolha);

    if(escolha == 1)
        imprimirvetores(P1, TAMANHO, P2, TAMANHO, P3, TAMANHO, notaFinal, TAMANHO);
    if(escolha == 2) 
        printNotaFinal(P1, TAMANHO, P2, TAMANHO, P3, TAMANHO, notaFinal, TAMANHO);
    if(escolha == 3)
        verificaNotaFinalAbaixo(P1, TAMANHO, P2, TAMANHO, P3, TAMANHO, notaFinal, TAMANHO);
    if(escolha == 4)
        verificaNotaFinalAcima(P1, TAMANHO, P2, TAMANHO, P3, TAMANHO, notaFinal, TAMANHO);
    if(escolha == 5)
        printf("\nSaindo...");
}


int main(){
    int P1[TAMANHO] = {0}, P2[TAMANHO] = {0}, P3[TAMANHO] = {0};
    int notaFinal[TAMANHO];

    scanNotas(P1, TAMANHO, P2, TAMANHO, P3, TAMANHO, notaFinal, TAMANHO); 
    calculaNotaFinal(P1, TAMANHO, P2, TAMANHO, P3, TAMANHO, notaFinal, TAMANHO);

    menu(P1, TAMANHO, P2, TAMANHO, P3, TAMANHO, notaFinal, TAMANHO);

    return 0;
}