typedef struct{
    char palavra[100];
    int marcado;
    int tamanho;
    int limC, colC;
    int limF, colF;
}Palavra;

typedef struct{
    char caractere;
    int dificuldade;
    int fazPartePalavra;
    int marcadoUsuario;
}Item;

typedef struct{
    int numeroComando;
    char nomeArquivoSave[100];
    int limC, colC;
    int limF, colF;
}Comando;

typedef struct{
    int limC, colC;
    int limF, colF;
}Coordenada;