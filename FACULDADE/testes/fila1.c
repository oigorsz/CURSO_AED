#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo * prox;
}TNodo;

typedef TNodo *PNodo;

typedef struct Fila {
    PNodo ini;
    PNodo fim;
}TFila;

typedef TFila *PFila;

PFila inicializarFila(){
    PFila f = (PFila)malloc(sizeof(TFila));

    if(f == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    f->ini = f->fim = NULL;

    return f;
}

PFila novoNodo (PFila f, int n){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = n;
    novo->prox = NULL;

    if(f->ini == NULL){
        f->ini = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    return f;
}

PFila remover (PFila f){
    PNodo aux;

    if(f == NULL){
        printf("[FILA VAZIA].\n");
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

void imprimirFila(PFila f){
    PNodo aux;

    for(aux = f->ini; aux != NULL; aux = aux->prox){
        printf("%d ", aux->info);
    }
}

void liberarFila(PFila f){
    PNodo aux;

    for(aux = f->ini; aux != NULL; aux = f->ini){
        f->ini = f->ini->prox;
        free(aux);
    }

    free(f);
}

void organizarFilas(PFila f1, PFila par, PFila impar){
    PNodo aux;

    for(aux = f1->ini; aux != NULL; aux = f1->ini){
        if(aux->info % 2 == 0){
            par = novoNodo(par, aux->info);
        } else {
            impar = novoNodo(impar, aux->info);
        }

        f1->ini = f1->ini->prox;
        free(aux);
    }
}

int main(){
    int N, valido = 1;
    PFila fila1 = inicializarFila();
    PFila filaPar = inicializarFila(), filaImpar = inicializarFila();

    system("cls");

    do {
        printf("DIGITE UM NUMERO QUE SERÁ ADICIONADO A FILA 1.\n");
        printf("DIGITE -1 PARA TERMINAR O PROCEDIMENTO.\n");
        scanf("%d", &N);

        if(0 <= N && N <= 100){
            fila1 = novoNodo(fila1, N);
        } else {
            valido = 0;
        }

    } while(valido == 1);

    system("cls");

    printf("FILA 1.\n");
    imprimirFila(fila1);

    organizarFilas(fila1, filaPar, filaImpar);

    printf("\nFILA 1.\n");
    imprimirFila(fila1);
    printf("FILA PAR.\n");
    imprimirFila(filaPar);
    printf("\nFILA IMPAR.\n");
    imprimirFila(filaImpar);

    liberarFila(fila1);
    liberarFila(filaPar);
    liberarFila(filaImpar);

    return 0;
}

