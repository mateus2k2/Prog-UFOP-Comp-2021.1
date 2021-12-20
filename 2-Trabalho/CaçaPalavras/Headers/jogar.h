
#include "Headers/structs.h"

void jogar(Palavra *palavras ,Item **tabuleiro, int tamLin, int tamCol, int quantidade);
Comando interpretaComando(char comandoCompleto[]);
int verificaEscolha(Comando comando, Palavra *palavras ,Item **tabuleiro, int *encontradas, int quantidade, int tamCol, int tamLin);