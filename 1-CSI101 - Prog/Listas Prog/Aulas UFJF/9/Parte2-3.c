// Faça uma estrutura que represente um número complexo, onde um número complexo c é escrito da forma c = a+bi. Portanto é necessário armazenar os números reais a e b. 

// a)Implemente uma função para fazer adição de números complexos, recebendo 2 números complexos e retornando o número complexo resultante. 
//   Dica  Adição: c1 + c2 = (a1 + b1i) + (a2 + b2i)= (a1 + a2) + (b1 + b2)i

// b)Implemente uma função para fazer subtração de números complexos, recebendo 2 números complexos e retornando o número complexo resultante. 
//   Dica  Subtração: c1 - c2 = (a1 + b1i) - (a2 + b2i)= (a1 - a2) + (b1 - b2)i

// c)Implemente uma função para fazer multiplicação de números complexos, recebendo 2 números complexos e retornando o número complexo resultante. 
//   Dica  Multiplicação: c1 * c2 = (a1 + b1i) * (a2 + b2i) = (a1*a2 -b1*b2 ) + (a1*b2 - b1*a2)i

// d)Faça um programa para ler números complexos e testar as funções implementadas

typedef struct{
    float a;
    float b;
}complexo;

complexo calculaAdicao(complexo c1, complexo c2){
    complexo ad;

    ad.a = (c1.a + c2.a);
    ad.b = (c1.b + c2.b);

    return ad;
}

complexo calculaSubtracao(complexo c1, complexo c2){
    complexo sub;

    sub.a = (c1.a - c2.a);
    sub.b = (c1.b - c2.b);

    return sub;
}

complexo calculaMultiplicacao(complexo c1, complexo c2){
    complexo mult;

    mult.a = (c1.a * c2.a) - (c1.b * c2.b);
    mult.b = (c1.a * c2.b) - (c1.b * c2.a);

    return mult;
}

int main(){
    complexo c1, c2;
    complexo ad, sub, mult; 

    printf("Digite o numero real 'a' e 'b' do numero complexo 1: ");
    scanf("%f %f", &c1.a, &c1. b);

    printf("Digite o numero real 'a' e 'b' do numero complexo 2: ");
    scanf("%f %f", &c2.a, &c2. b);

    ad = calculaAdicao(c1, c2);
    sub = calculaSubtracao(c1, c2);
    mult = calculaMultiplicacao(c1, c2);
    
    printf("\nADICAO: (%.2f) + (%.2f)i", ad.a, ad.b);
    printf("\nSUBTRACAO: (%.2f) + (%.2f)i", sub.a, sub.b);
    printf("\nMULTIPLICACAO: (%.2f) + (%.2f)i", mult.a, mult.b);

    return 0;
}
