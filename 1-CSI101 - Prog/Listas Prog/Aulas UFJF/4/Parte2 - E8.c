//Como fazer lista melhor

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale ----- Encoding ISO 8859-1

int main(){

  setlocale(LC_ALL, "Portuguese");

  int cod;

  printf("\nForma de pagamento:"); 
  printf("  \n- À vista.");
  printf("  \n- Cheque para trinta dias.");
  printf("  \n- Em duas vezes.");
  printf("  \n- Em três vezes.");
  printf("  \n- Em quatro vezes.");
  printf("  \n- A partir de cinco vezes.");

  printf("\nEntre com sua opção: ");
  scanf("%d", &cod);

  switch (cod)
  {
  case 1: printf("\nDesconto de 20%");
  break;
  case 2: printf("\nMesmo preço a vista");
  break;
  case 3: printf("\nMesmo preço a vista");
  break;
  case 4: printf("\nMesmo preço a vista");
  break;
  case 5: printf("\nJuros de 3% ao mês");
  break;
  case 6: printf("\nJuros de 5% ao mês");
  break;

  default: printf("\nOpção inválida");
  }

//system("\npause\n");
  return 0;
}