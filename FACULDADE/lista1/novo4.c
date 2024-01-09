#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente {
    int id;
    int tempoAtend;
    struct Cliente *prox;
}TCliente;

typedef TCliente *PCliente;

typedef struct Fila {
    PCliente ini;
    PCliente fim;
}TFila;

typedef TFila *PFila;

typedef struct Caixa{
    int id;
    int tempoAtend;
    PCliente fila;
}TCaixa;

typedef TCaixa *PCaixa;