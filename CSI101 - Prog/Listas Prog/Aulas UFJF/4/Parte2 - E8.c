//Como fazer lista melhor

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necess�rio para usar setlocale ----- Encoding ISO 8859-1

int main(){

  setlocale(LC_ALL, "Portuguese");

  int cod;

  printf("\nForma de pagamento:"); 
  printf("  \n- � vista.");
  printf("  \n- Cheque para trinta dias.");
  printf("  \n- Em duas vezes.");
  printf("  \n- Em tr�s vezes.");
  printf("  \n- Em quatro vezes.");
  printf("  \n- A partir de cinco vezes.");

  printf("\nEntre com sua op��o: ");
  scanf("%d", &cod);

  switch (cod)
  {
  case 1: printf("\nDesconto de 20%");
  break;
  case 2: printf("\nMesmo pre�o a vista");
  break;
  case 3: printf("\nMesmo pre�o a vista");
  break;
  case 4: printf("\nMesmo pre�o a vista");
  break;
  case 5: printf("\nJuros de 3% ao m�s");
  break;
  case 6: printf("\nJuros de 5% ao m�s");
  break;

  default: printf("\nOp��o inv�lida");
  }

//system("\npause\n");
  return 0;
}