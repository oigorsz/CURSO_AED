#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente {
    int id;
    int tempoAtend;
    struct Cliente* prox;
} TCliente;

typedef TCliente* PCliente;

typedef struct Fila {
    PCliente ini;
    PCliente fim;
} TFila;

typedef TFila* PFila;

typedef struct Caixa {
    int id;
    int tempoAtend;
    PFila fila;
} TCaixa;

typedef TCaixa* PCaixa;

PFila inicializarFila() {
    PFila f = (PFila)malloc(sizeof(TFila));
    f->ini = f->fim = NULL;
    return f;
}

PCaixa inicializarCaixa(int A) {
    int i;
    PCaixa c = (PCaixa)malloc(sizeof(TCaixa) * A);

    if (c == NULL) {
        printf("[ERRO ALOC]");
        exit(1);
    }

    for (i = 0; i < A; i++) {
        c[i].id = i + 1;
        c[i].tempoAtend = 0;
        c[i].fila = inicializarFila(); // Inicializa a fila de cada caixa
    }

    return c;
}

PFila novoCliente(PFila fila, int id, int T) {
    PCliente novo = (PCliente)malloc(sizeof(TCliente));

    if (novo == NULL) {
        printf("[ERRO ALOC]");
        exit(1);
    }

    novo->id = id;
    novo->tempoAtend = T;
    novo->prox = NULL;

    if (fila->fim == NULL) {
        fila->ini = fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }

    return fila;
}

// A função removerCliente permanece a mesma

PFila removerCliente(PFila fila){
    PCliente aux;

    if(fila == NULL || fila->ini == NULL){
        printf("FILA VAZIA.\n");
        return fila;
    }

    aux = fila->ini;
    fila->ini = fila->ini->prox;
    free(aux);

    if(fila->ini == NULL){
        fila->fim = NULL;
    }

    return fila;
}

int caixaMenorTempo(PCaixa caixas, int A) {
    int caixa_escolhido = 0, j;

    for (j = 1; j < A; j++) {
        if (caixas[j].tempoAtend < caixas[caixa_escolhido].tempoAtend) {
            caixa_escolhido = j;
        }
    }

    return caixa_escolhido;
}

void imprimir(PCaixa caixas, int A) {
    int i;

    for (i = 0; i < A; i++) {
        printf("%d:", caixas[i].id);
        PCliente cliente = caixas[i].fila->ini;

        while (cliente != NULL) {
            printf(" %d", cliente->id);
            cliente = cliente->prox;
        }

        printf("\n");
    }
}

void liberarCaixas(PCaixa caixas, int A) {
    int i;

    for (i = 0; i < A; i++) {
        while (caixas[i].fila->ini != NULL) {
            caixas[i].fila = removerCliente(caixas[i].fila);
        }

        free(caixas[i].fila);
    }

    free(caixas);
}

void liberarFila(PFila fila) {
    while (fila->ini != NULL) {
        fila = removerCliente(fila);
    }

    free(fila);
}

int main() {
    int N, A, T, i;
    PCaixa lista_caixas;
    PFila fila_clientes;

    // Recebe a quantidade de clientes (N) e a quantidade de atendentes (A)
    do {
        scanf("%d %d", &N, &A);
    } while (!(1 <= N && N <= 1023 && 0 <= A && A <= 25));

    // Inicializar os caixas
    lista_caixas = inicializarCaixa(A);

    // Inicializar lista de clientes
    fila_clientes = inicializarFila();

    // Registrar os clientes
    for (i = 0; i < N; i++) {
        do {
            scanf("%d", &T);
        } while (!(0 <= T && T <= 1000));

        fila_clientes = novoCliente(fila_clientes, i + 1, T);
    }

    // Organizar os clientes nos caixas
    for (i = 0; i < N; i++) {
        // Encontrar o caixa com menor tempo de atendimento
        int caixa_vazio = caixaMenorTempo(lista_caixas, A);

        // Atribuir o cliente ao caixa e atualizar o tempo de atendimento do caixa
        PCliente proximo_cliente = fila_clientes->ini;

        if (proximo_cliente != NULL) {
            lista_caixas[caixa_vazio].fila = novoCliente(lista_caixas[caixa_vazio].fila, proximo_cliente->id, proximo_cliente->tempoAtend);
            lista_caixas[caixa_vazio].tempoAtend += proximo_cliente->tempoAtend;
            fila_clientes = removerCliente(fila_clientes);
        }
    }

    // Imprimir a saída de acordo com as filas de cada caixa
    imprimir(lista_caixas, A);

    // Liberar a memória alocada
    liberarCaixas(lista_caixas, A);
    liberarFila(fila_clientes);

    return 0;
}
