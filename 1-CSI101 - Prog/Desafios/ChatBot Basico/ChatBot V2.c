
#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    char pergunta[1000], resposta[1000];
    char escolha[10], Bufferarquivo[10000];
    int t = 1;


    while(1){

        FILE *LeituraPerguntasRespostas = fopen("PerguntasRespostas.txt", "r");
        FILE *EscritaPerguntasRespostas = fopen("PerguntasRespostas.txt", "a");

        printf("\n--------------------------------------------------------------------------------------------------------------------------------");

        printf("\nFaca sua pergunta: ");
        fgets(pergunta, 1000, stdin);

        pergunta[strcspn(pergunta, "\n")] = '\0';

        t = 1;

        while(fgets(Bufferarquivo, sizeof(Bufferarquivo), LeituraPerguntasRespostas)){
           Bufferarquivo[strcspn(Bufferarquivo, "\n")] = '\0';
           if(strcmp(Bufferarquivo, pergunta) == 0){
                fgets(Bufferarquivo, 10000, LeituraPerguntasRespostas);
                fputs(Bufferarquivo, stdout);
                fclose(LeituraPerguntasRespostas);
                t = 0;
           }
        }

        if(strcmp("Sair", pergunta) == 0)
            break;

        else if(strcmp("Qual sua idade", pergunta) == 0){
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            
            printf("Eu tenho: %d anos, %02d meses, %02d dias, %02d horas, %02d minutos e %02d segundos de vida\n", 
            (tm.tm_year + 1900) - 2021, abs((tm.tm_mon + 1) - 6), abs((tm.tm_mday) - 12), abs(tm.tm_hour-12), abs(tm.tm_min-30), abs(tm.tm_sec-45));            
        }

        else if(strcmp(pergunta, "Abra o Chrome")==0){
            printf("\nAbrindo");
            system("start chrome");
        }

        else if(t==1){
            printf("\nAinda nao aprendi esta resposta. Deseja me ensinar essa resposta? (Sim ou qualquer outras coisa para nao): ");
            fgets(escolha, 10, stdin);
            escolha[strlen(escolha) - 1] = '\0';
            
            if(strcmp("Sim", escolha) == 0){

                printf("Digite a Resposnta: ");
                fgets(resposta, 1000, stdin);

                fprintf(EscritaPerguntasRespostas, "%s", pergunta);
                fprintf(EscritaPerguntasRespostas, "\n");
                fprintf(EscritaPerguntasRespostas, "%s", resposta);
                fprintf(EscritaPerguntasRespostas, "\n");
                fclose(EscritaPerguntasRespostas);
            }   
        }
    }
    return 0;
}
