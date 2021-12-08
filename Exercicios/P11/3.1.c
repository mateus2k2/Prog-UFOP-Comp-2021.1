#include <stdio.h>
#include <stdlib.h>

void allocate_mem(double*** arr, int rows, int cols);
void deallocate_mem(double*** arr, int n);
void readMatrix(double ***a, int rows,int cols);
void printMatrix(double** a, int rows, int cols);
void multMatrixpp(double **A, double **B, double ***C,int ro1,int co1,int ro2,int co2);

//______________________________________________________________________________

int main(){
   int ro1, co1, ro2, co2;
   double **a1, **b1, **c1;    


    printf("Linha e Coluna A"); scanf("%d%d", &ro1, &co1);
    readMatrix(&a1,ro1,co1);
    printMatrix(a1,ro1,co1); 


    printf("Linha e Coluna B"); scanf("%d%d", &ro2, &co2);
    readMatrix(&b1,ro2,co2);
    printMatrix(b1,ro2,co2);

    //if
    printf("MatMult \n");
    multMatrixpp(a1, b1, &c1, ro1, co1, ro2, co2);  
    printMatrix(c1,ro1,co2); 

    //else printf

    deallocate_mem(&a1,ro1); 
    deallocate_mem(&b1,ro2);
    deallocate_mem(&c1,ro1);  


    return 0;
}

//______________________________________________________________________________
void allocate_mem(double*** arr, int rows, int cols){
  int i;
  *arr = (double**)malloc(rows*sizeof(double*));
  for( i=0; i<rows; i++)
    (*arr)[i] = (double*)malloc(cols*sizeof(double));
} 

//______________________________________________________________________________
void deallocate_mem(double*** arr, int rows){
 int i;
    for (i = 0; i < rows; i++)
        free((*arr)[i]);
    free(*arr); 
}


//______________________________________________________________________________

void readMatrix(double ***a, int rows,int cols){
   int i, j;

*a = (double**) malloc(rows*sizeof(double*));

for(i=0;i<rows;i++)
(*a)[i]=(double*)malloc(cols*sizeof(double));
    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            scanf("%lf",&(*a)[i][j]);
}

//______________________________________________________________________________
void printMatrix(double** a, int rows, int cols){
    int i, j;
   printf("Matrix[%d][%d]\n",rows,cols);    
   for(i=0;i<rows;i++){
      for(j=0;j<cols;j++)
      printf("%8.3lf ",a[i][j]);
      printf("\n");
   }
   printf("\n");   
}


//______________________________________________________________________________

void multMatrixpp(double **A, double **B, double ***C,int ro1,int co1,int ro2,int co2){

int i, j, k;
*C= (double**) malloc(ro1*sizeof(double*));
for(i=0;i<ro1;i++)
(*C)[i]=(double*)malloc(co2*sizeof(double));

    for(i = 0; i < ro1; i++) {
        for(j = 0; j < co2; j++) {
            (*C)[i][j] = 0.0;
            for(k = 0; k < co1; k++) {
                (*C)[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}