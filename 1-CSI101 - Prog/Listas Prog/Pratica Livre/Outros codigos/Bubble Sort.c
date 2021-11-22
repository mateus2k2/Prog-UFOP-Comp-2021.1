

void ordena(float vet[], int tam){
    int i, j;
    float aux;
    
    for(i = 0; i <= (tam-2); i++){
        
        for(j = tam-1; j > i; j--){
        
            if ( vet[j] < vet[j-1] ){
                aux =vet[j];
                vet [j]= vet[j-1];
                vet [j-1]=aux;
                }
            }
        }
    }

int main(){
    int i;
    float vet[5]={11.0,22.0,3.0,44.0,5.0};
    
    ordena(vet, 5);
    
    for (i=0; i < 5; i++)
    printf("%.2f\n",vet[i]);
    
    return 0;
}