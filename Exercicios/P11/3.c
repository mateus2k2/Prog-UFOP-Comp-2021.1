//Nome: Mateus Filipe Moreira Silva
//Matrícula: 2114156
//Turma  41

#include <stdio.h>
#include <stdlib.h>

void alocaMat(double*** mat, int lin, int col);
void liberaMat(double*** mat, int n);
void leMat(double ***a, int lin,int col);
void printMat(double** a, int lin, int col);
int multiplicaMat(double **matA, double **matB, double ***matC,int linA,int colA,int linB,int colB);

int main(){
   int linA, colA, linB, colB;
   double **matA, **matB, **mult;    


    printf("Linha e Coluna A: "); scanf("%d%d", &linA, &colA);
    printf("\nLendo Matriz A\n");    
    leMat(&matA,linA,colA);
    printf("\nPrint Matriz A\n");    
    printMat(matA,linA,colA); 

    printf("------------------------------------------\n");


    printf("Linha e Coluna B: "); scanf("%d%d", &linB, &colB);
    printf("\nLendo Matriz B\n");    
    leMat(&matB,linB,colB);
    printf("\nPrint Matriz B\n");    
    printMat(matB,linB,colB);

    printf("------------------------------------------\n");

    if(multiplicaMat(matA, matB, &mult, linA, colA, linB, colB) == 1){
        printf("Multiplicada \n"); 
        printMat(mult,linA,colB); 
    }
    else
        printf("\nNao e possivel multiplicar matrizes");

    liberaMat(&matA,linA); 
    liberaMat(&matB,linB);
    liberaMat(&mult,linA);  

    return 0;
}

void alocaMat(double*** mat, int lin, int col){
    int i;
    *mat = (double**)malloc(lin*sizeof(double*));
    for( i=0; i<lin; i++)
        (*mat)[i] = (double*)malloc(col*sizeof(double));
} 

void liberaMat(double*** mat, int lin){
    int i;
    for (i = 0; i < lin; i++)
        free((*mat)[i]);
    free(*mat); 
}

void leMat(double ***a, int lin,int col){
   int i, j;

    *a = (double**) malloc(lin*sizeof(double*));

    for(i=0;i<lin;i++)
    (*a)[i]=(double*)malloc(col*sizeof(double)); 
        for(i=0;i<lin;i++){
            printf("Linha %i: ", 1+i);
            for(j=0;j<col;j++){
                scanf("%lf", &(*a)[i][j]);
            }
        }
}

void printMat(double** a, int lin, int col){
    int i, j;
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++)
        printf("%.0lf ",a[i][j]);
        printf("\n");
   }
   printf("\n");   
}

int multiplicaMat(double **matA, double **matB, double ***matC,int linA,int colA,int linB,int colB){

    int i, j, k;

    if(colA == linB){

        *matC= (double**) malloc(linA*sizeof(double*));
        for(i=0;i<linA;i++)
            (*matC)[i]=(double*)malloc(colB*sizeof(double));
                for(i = 0; i < linA; i++) {
                    for(j = 0; j < colB; j++) {
                        (*matC)[i][j] = 0.0;
                        for(k = 0; k < colA; k++) {
                            (*matC)[i][j] += matA[i][k] * matB[k][j];
                        }
                    }
                }

        return 1;
    }
    return 0;
}