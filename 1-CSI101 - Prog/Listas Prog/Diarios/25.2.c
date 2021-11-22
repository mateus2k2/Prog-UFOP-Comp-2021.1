// Você trabalha em um grande empresa de construção de software para bancos, então solicitaram a você que fizesse um módulo de um software bancário. 
// Para isto, você deverá ler os códigos de no máximo 1000 contas e seus saldos. Os códigos e os saldos deverão ser armazenados em vetores diferentes
// (não pode haver mais do que uma conta com o mesmo código). O saldo poderá ser armazenado em posição equivalente à do código. Por exemplo, 
// se a conta 203 está armazenada na posição 10 do vetor de códigos, seu saldo deverá ficar na décima posição de saldos. Depois de fazer a leitura dos valores, deverá aparecer o seguinte menu na tela:

// 1 - Efetuar depósito
// 2 - Efetuar Saque
// 3 - Consultar saldo.
// 4 - Finaliza o programa

// a) para efetuar depósito deve-se solicitar o código da conta e o valor a ser depositado. Se a conta não estiver cadastrada, 
//    deverá aparecer a mensagem informando isto e perguntar ao usuário se quer realizar o cadastro da conta. Para isto deverá ser solicitado o saldo inicial.  Se a conta existir deverá ser atualizado o saldo.

// b) para efetuar saque, deve-se solicitar o código da conta e o valor a ser sacado. Se a conta não estiver cadastrada, deverá ser mostrada a mensagem "Conta não cadastrada" 
//    e voltar ao menu principal. Se a conta existir, deverá ser verificado se o saldo é suficiente para cobrir o saque. Se o saldo for suficiente, realiza o saque e volta ao menu. 
//    Caso contrário mostrar a mensagem saldo insuficiente e volta ao menu.

// c) para consultar o ativo bancário, deve-se somar o saldo de todas as contas do banco. Depois mostrar este valor e volta ao menu principal.

// d) o programa só pode terminar após digitar a opção 4.

//Morri


#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void fazSaque (int cod[], int tamCod, float saldo[], int tamSaldo){
    int possivelCod;
    float possivelSaque;
    int i = 0;

    printf("\nSAQUE");
    printf("\n");

    printf("\n");
    printf("Digite o codigo da conta: ");
    scanf("%i", &possivelCod);

    for (i = 0; i < 1000; i++){
        if(possivelCod == cod[i]){

            printf("Digite o valor do saque: ");
            scanf("%f", &possivelSaque);

            if(possivelSaque <= saldo[i]){

                printf("O seu saldo antigo era %f", saldo[i]);
                printf("O seu novo saldo e %f", saldo[i]-possivelSaque);
                printf("\n");
                saldo[i] = saldo[i]-possivelSaque;
                menu(cod, 1000, saldo, 1000);
            }

            else{
                printf("\nSaldo insuficiente para fazer esse saque");
                printf("\nSeu saldo e de %f", saldo[i]);
                printf("\nSao necessario mais %f para fazer o saque de %f", possivelSaque-saldo[i], possivelSaque);
                printf("\n");
                menu(cod, 1000, saldo, 1000);

            }
        }

        if(i==999){
            printf("Codigo de conta não cadastrado: ");
            printf("\n");
            menu(cod, 1000, saldo, 1000);
        }
    }
}

void fazDeposito(int cod[], int tamCod, float saldo[], int tamSaldo){
    int possivelCod; 
    float possivelDeposito;
    int escolha;
    int i = 0, j = 0, k = 0;

    printf("\nDEPOSITO");
    printf("\n");

    printf("\n");
    printf("Digite o codgo da conta: ");
    scanf("%i", &possivelCod);

    for (i = 0; i < 1000; i++){
        if(possivelCod == cod[i]){

            printf("Digite o valor do deposito: ");
            scanf("%f", &possivelDeposito);

            printf("O seu saldo antigo era %f", saldo[i]);
            printf("O seu novo saldo e %f", saldo[i]+possivelDeposito);
           
            printf("\n");
           
            saldo[i] = saldo[i]+possivelDeposito;
            menu(cod, 1000, saldo, 1000);
        }

        if(i==999)
            printf("Codigo de conta não cadastrado: ");
    }

        printf("Deseja cadastrar um nova conta? sim (Digite Numero 1) ou nao (Digite Qualquer Numero): ");
        scanf("%i", &escolha);

        for (k = 0; k < 1000; k++){
            
            if(cod[k] == -1){
                break;
            }

            if(k == 999){
                printf("Banco de dados de contas esta cheio");
                menu(cod, 1000, saldo, 1000);
            }
        }

        if(escolha == 1){

            printf("\nNova conta criada.");
            cod[k] = possivelCod; 

            printf("\nDigite o saldo dessa conta: ");
            scanf("%f", &saldo[k]);

            printf("\nDigite o valor do depostio: ");
            scanf("%f", &possivelDeposito);

            printf("O seu saldo antigo era %f", saldo[k]);
            printf("O seu novo saldo e %f", saldo[k]+possivelDeposito); 
            printf("\n");
            saldo[k] = saldo[k]+possivelDeposito;
            menu(cod, 1000, saldo, 1000);
    }

        else{
            printf("Conta nao criada - Voltando para o menu");
            printf("\n");
            menu(cod, 1000, saldo, 1000);
        }
}

void verificaSaldo(int cod[], int tamCod, float saldo[], int tamSaldo){
    int i, j, possivelCod;

    printf("\nSALDO DE UMA CONTA");
    printf("\n");

    printf("\n");
    printf("Digite a conta para verificar o saldo: ");
    scanf("%i", &possivelCod);

    for (i = 0; i < 1000; i++){
        if(possivelCod == cod[i]){
            printf("O saldo da conta %i e %f", cod[i], saldo[i]);
            printf("\n");
            menu(cod, 1000, saldo, 1000);
        }

        if(i==999){
            printf("Codigo de conta não cadastrado - Voltando para o menu");
            printf("\n");
            menu(cod, 1000, saldo, 1000);
        }
    }
}

void verificaAtivos(int cod[], int tamCod, float saldo[], int tamSaldo){
    int i;
    float saldoTotal = 0;

    printf("\nATIVOS DO BANCO");
    printf("\n");

    for (i = 0; i < 1000; i++){
        if(cod[i] == -1)
            break;
     
        printf("\nA conta codigo %i tem saldo %f", cod[i], saldo[i]);
        saldoTotal = saldoTotal + saldo[i];
    }

    printf("\n");
    printf("\nO saldo total do banco e %f", saldoTotal);
    printf("\n");
    menu(cod, 1000, saldo, 1000);
}

void adicionarContas (int cod[], int tamCod, float saldo[], int tamSaldo){

    int i = 0, j = 0, k = 0;     

    printf("\nDIGITE OS CODIGOS E AS CONTA - DIGITE UM CODIGO NEGATIVO PARA SAIR\n");
    printf("\n");

    for (k = 0; k < 1000; k++){
        if(cod[k] == -1)
            break;
        if(k == 999){
            printf("Banco de dados de contas esta cheio");
            menu(cod, 1000, saldo, 1000);
        }
    }

    for (i = k; i < 1000; i++){
        printf("Digite o codigo da conta: ");
        scanf("%i", &cod[i]);

        if(cod[i] < 0)
            menu(cod, 1000, saldo, 1000);
        

        while (1){
        
        for (j = 0; j < 1000; j++){

            if(j == i || i == 0)
                j++;

            if(cod[i] == cod[j]){
                printf("codigo repetido, digite outro: ");
                scanf("%i", &cod[i]);

                if(cod[i] < 0)  
                    menu(cod, 1000, saldo, 1000);

                j = 0;
                break;
            }

            if(j == 999)
                break;
        }

        if(j==999){
            j = 0;
            break;
        }   
    }

        printf("Digite o saldo dessa conta: ");
        scanf("%f", &saldo[i]);
        printf("\n");

          if(saldo[i] < 0){
            break;
        }

    }
    menu(cod, 1000, saldo, 1000);
}

int menu(int cod[], int tamCod, float saldo[], int tamSaldo){

    int escolha;

    while (1){

        printf("\n------------------------------------------------------------------------------------------");
        printf("\n");
        printf("\nMENU");
        printf("\n");

        printf("\n1 - Efetuar deposito");
        printf("\n2 - Efetuar Saque");
        printf("\n3 - Consultar saldo.");
        printf("\n4 - Consultar ativos do banco.");
        printf("\n5 - Adicionar mais contas");
        printf("\n6 - Finaliza o programa");
        printf("\nESCOLHA UMA OPCAO: ");
        scanf("%i", &escolha);

        printf("\n------------------------------------------------------------------------------------------");
        printf("\n");

        switch (escolha){
        case 1: fazDeposito(cod, 1000, saldo, 1000);
            break;
        case 2: fazSaque(cod, 1000, saldo, 1000);
            break;
        case 3: verificaSaldo(cod, 1000, saldo, 1000);
            break;
        case 4: verificaAtivos(cod, 1000, saldo, 1000);
            break;
        case 5: adicionarContas(cod, 1000, saldo, 1000);
            break;
        case 6: return 0;
            break;
        
        default: printf("\n"); 
                 printf("Escolha nao definida. Tente novamente");
                 printf("\n");
            break;
        }
    }
}

int main(){
    int cod[1000]; 
    float saldo[1000];
    int i = 0, j = 0; 

    for (int i = 0; i < 1000; i++){
        cod[i] = -1;
    }    

    printf("\n------------------------------------------------------------------------------------------");
    printf("\n");


    printf("\nDIGITE OS CODIGOS E AS CONTA - DIGITE UM CODIGO NEGATIVO PARA SAIR\n");
    printf("\n");

    for (i = 0; i < 1000; i++){
        printf("Digite o codigo da conta: ");
        scanf("%i", &cod[i]);

        if(cod[i] < 0)
            menu(cod, 1000, saldo, 1000);

        while (1){
        
        for (j = 0; j < 1000; j++){

            if(j == i)
                j++;
                

            if(cod[i] == cod[j]){
                printf("codigo repetido, digite outro: ");
                scanf("%i", &cod[i]);

                if(cod[i] < 0)  
                    menu(cod, 1000, saldo, 1000);

                j = 0;
                break;
            }

            if(j == 999)
                break;
            
        }

        if(j==999){
            j = 0;
            break;
        }   
    }

        printf("Digite o saldo dessa conta: ");
        scanf("%f", &saldo[i]);
        printf("\n");

          if(saldo[i] < 0){
            break;
        }
    }
    
    menu(cod, 1000, saldo, 1000);

    return 0;
}