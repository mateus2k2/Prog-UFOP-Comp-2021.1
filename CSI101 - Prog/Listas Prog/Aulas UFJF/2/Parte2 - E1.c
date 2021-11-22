
int main(){

    int x, y, ad, sub, div, mult, mod;

    printf("OPERACOES SOBRE INTEIROS\n");
    printf("Digite o primeiro valor: ");
    scanf("%i", &x);
    printf("Digite o segundo valor: ");
    scanf("%i", &y);

    ad = x + y;
    sub = x - y;
    div = x / y;
    mult = x * y;
    mod = x % y;

    printf("%i + %i = %i\n", x, y, ad);
    printf("%i + %i = %i\n", x, y, sub);
    printf("%i + %i = %i\n", x, y, div);
    printf("%i + %i = %i\n", x, y, mult);
    printf("%i + %i = %i\n", x, y, mod);

    return 0;

}