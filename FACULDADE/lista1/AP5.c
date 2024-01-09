//IGOR DE SOUZA MONTEIRO- REVISÃO FILAS

#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente {
    int id, tempoAtend;
    struct Cliente *prox;
}TCLiente;

typedef TCLiente *PCliente;

typedef struct Fila {
    PCliente ini;
    PCliente fim;
}TFila;

typedef TFila *PFila;

typedef struct Caixa {
    int id, tempo;
    PFila fila;
}TCaixa;

typedef TCaixa *PCaixa;

PFila inicializarFila(){
    PFila f = (PFila)malloc(sizeof(TFila));

    if(f == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    f->ini = f->fim = NULL;
}

PCaixa inicializarCaixa(int A){
    int i;
    PCaixa c = (PCaixa)malloc(sizeof(TCaixa) * A);

    if(c == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    for(i = 0; i < A; i++){
        c[i].id = i + 1;
        c[i].tempo = 0;
        c[i].fila = inicializarFila();
    }

    return c;
}

PFila novoCliente(PFila f, int id, int tempo){
    PCliente novo = (PCliente)malloc(sizeof(TCLiente));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO]");
        exit(1);
    }

    novo->id = id;
    novo->tempoAtend = tempo;
    novo->prox = NULL;

    if(f->ini == NULL){
        f->ini = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    return f;
}

PFila removerCliente(PFila f){
    PCliente aux;

    if(f == NULL){
        printf("[FILA VAZIA.]\n");
        return f;
    }

    aux = f->ini;
    f->ini = f->ini->prox;
    free(aux);

    if(f->ini == NULL){
        f->fim = NULL;
    }

    return f;
}

int caixaMenorTempo (PCaixa c, int A){
    int caixa_escolhido = 0, j;

    for(j = 1; j < A; j++){
        if(c[j].tempo < c[caixa_escolhido].tempo){
            caixa_escolhido = j;
        }
    }

    return caixa_escolhido;
}

void imprimir(PCaixa c, int A){
    int i;
    PCliente aux;

    for(i = 0; i < A; i++){
        printf("%d: ", c[i].id);

        for(aux = c[i].fila->ini; aux != NULL; aux = aux->prox){
            printf("%d ", aux->id);
        }

        printf("\n");
        
    }
}

void liberar(PCaixa c, int A){
    int i;
    PCliente aux, temp;

    for(i = 0; i < A; i++){

        for(aux = c[i].fila->ini; aux != NULL; aux = c[i].fila->ini){
            c[i].fila->ini = c[i].fila->ini->prox;
            free(aux);
        }

        free(c[i].fila);
    }

    free(c);
}


int main(){
    int N, A, T, i, caixa_disponivel;
    PCaixa lista_caixas;
    PFila fila_clientes;
    PCliente proximo_cliente;

    system("cls");

    //RECEBE A QUANTIDADE DE CLIENTES E CAIXAS

    do {
        scanf("%d %d", &N, &A);
    } while(!(1 <= N && N <= 1023 && 1 <= A && A <= 25));

    //CRIAR OS CAIXAS COM "A" ATENDENTES

    lista_caixas = inicializarCaixa(A);

    //CRIAR A FILA INICIAL DE CLIENTES

    fila_clientes = inicializarFila();

    //REGISTRANDO OS CLIENTES

    for(i = 0; i < N; i++){
        do {
            scanf("%d", &T);
        } while (!(0 <= T && T <= 1000));

        fila_clientes = novoCliente(fila_clientes, i + 1, T);
    }


    //ORGANIZAR CAIXAS

    for(i = 0; i < N; i++){
        //ENCONTRAR O CAIXA DE MENOR TEMPO QUE SERÁ O CAIXA DISPONIVEL PARA DETERMINADO CLIENTE
        caixa_disponivel = caixaMenorTempo(lista_caixas, A);

        proximo_cliente = fila_clientes->ini;

        if(proximo_cliente != NULL){
            lista_caixas[caixa_disponivel].fila = novoCliente(lista_caixas[caixa_disponivel].fila, proximo_cliente->id, proximo_cliente->tempoAtend);
            lista_caixas[caixa_disponivel].tempo += proximo_cliente->tempoAtend;
            fila_clientes = removerCliente(fila_clientes);
        }
    }

    imprimir(lista_caixas, A);
    liberar(lista_caixas, A);

    return 0;
}