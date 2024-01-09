#include <stdio.h>
#include <stdlib.h>


typedef struct Cliente {
    int tempoAtend;
    int id;
    struct Cliente * prox;
}TCliente;

typedef TCliente *PCliente;

typedef struct Caixa {
    int id;
    int tempoLivre;
    PCliente fila;
}TCaixa;

typedef TCaixa *PCaixa;

PCliente inicializarFila(){
    return NULL;
}

PCaixa preencherCaixas(int A){
    //PRENCHER AS CAIXAS
    int i;
    PCaixa caixas = (PCaixa)malloc(sizeof(TCaixa) * A);

    if(caixas == NULL){
        printf("[ERRO DE ALOCAÇÃO]");
        return caixas;
    }

    for(i = 0; i < A; i++){
        caixas[i].id = i + 1;
        caixas[i].fila = inicializarFila();
        caixas[i].tempoLivre = 0;
    }

    return caixas;
}

PCliente inserirCliente(PCliente fila, int id, int tempo){
    PCliente novo = (PCliente)malloc(sizeof(TCliente));
    PCliente aux;

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO]");
        return novo;
    }

    novo->id = id;
    novo->tempoAtend = tempo;
    novo->prox = NULL;

    if(fila == NULL){
        return novo;
    }

    aux = novo;

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novo; //ADICIONA UM NOVO CLIENTE AO FINAL DA FILA

    return fila; //RETORNA SEMPRE O PRIMEIRO CLIENTE DA FILA
}

PCliente removerCliente(PCliente fila){
    PCliente aux;

    if(fila == NULL){
        printf("[ERRO FILA VAZIA.]\n");
        return fila;
    }

    aux = fila;
    fila = fila->prox;
    free(aux);
    return fila;
}



void imprimir(PCaixa caixas, int A){
    int i;

    for(i = 0; i < A; i++){
        printf("%d: ", caixas[i].id);
        PCliente aux = caixas[i].fila;

        while(aux != NULL){
            printf("%d ", aux->id);
            aux = aux->prox;
        }

        printf("\n");
    }
}

void liberar(PCaixa caixas, int A){
    int i;

    for(i = 0; i < A; i++){
        PCliente aux = caixas[i].fila;

        while(aux != NULL){
            PCliente prox = aux->prox;
            free(aux);
            aux = prox;
        }
    }

    free(caixas);
}

int main(){
    int N, A, T, i, j, caixa_menor_tempo, menor_tempo_livre;
    PCaixa caixas, caixa_select;
    PCliente fila_clientes;

    //RECEBER O NUMERO DE CLIENTES E CAIXAS
    do {
        scanf("%d %d", &N, &A);
    } while(!(1 <= N && N <= 1023 && 1 <= A && A <= 25));

    //CRIAR AS CAIXAS
    caixas = preencherCaixas(A);

    //INICIALIZAR FILA DE CLIENTES
    fila_clientes = inicializarFila();

    //INSERIR OS CLIENTES NA FILA
    for(i = 0; i < N; i++){
        do {
            scanf("%d ", &T);
        } while(!(0 <= T && T <= 1000));

        fila_clientes = inserirCliente(fila_clientes, i + 1, T);
    }

    //ORGANIZAR OS CLIENTES NAS FILAS DE CAIXA

    

    imprimir(caixas, A);
    liberar(caixas, A);
}