#include <stdio.h>

int calculo(int n1, int n2){

    int numeroInteirosIpares;

    numeroInteirosIpares = 0;

    if(n1%2!=0)
    numeroInteirosIpares = numeroInteirosIpares + 1;
    if(n2%2!=0)
    numeroInteirosIpares = numeroInteirosIpares + 1;
    
    while (n1 < n2){        
    if(n1%2!=0){
    numeroInteirosIpares = numeroInteirosIpares + 1;;
    }        
    n1++;
}

printf("%d", numeroInteirosIpares);

return 0;

}


int main(){

    float n1, n2;

    printf("Digite o numero 1 menor: ");
    scanf("%f", &n1 );

    printf("Digite o numero 2 maior: ");
    scanf("%f", &n2 );

    calculo(n1, n2);

    return 0;
}
