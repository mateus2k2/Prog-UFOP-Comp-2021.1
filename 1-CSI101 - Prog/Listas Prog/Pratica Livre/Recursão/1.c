//Write a program in C to print first 50 natural numbers using recursion

int printNat(int n){
    int i = 0;

    if(n == 0)
        return 1;
    else{
        printf("%i", printNat(n-1) + (n-1));
    }

}

int main(){
    int n = 5;

    printf("\nOs numeros naturais sao: \n");
    printNat(n);

}