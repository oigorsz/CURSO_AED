#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *prox;
}TNodo;

typedef TNodo *PNodo;

typedef struct Fila {
    PNodo ini;
    PNodo fim;
}TFila;

typedef TFila *PFila;

PFila iniciarFila(){
    PFila f = (PFila)malloc(sizeof(TFila));

    if(f == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    f->ini = f->fim = NULL;

    return f;
}

PFila novoNodo (PFila f, int v){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = v;
    novo->prox = NULL;

    if(f->ini == NULL){
        f->ini = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    return f;
}

PFila remover(PFila f){
    PNodo aux;

    if(f == NULL){
        printf("FILA VAZIA.\n");
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

void imprimir(PFila f){
    PNodo aux;

    for(aux = f->ini; aux != NULL; aux = aux->prox){
        printf("%d ", aux->info);
    }
}

void liberar(PFila f){
    PNodo aux;

    for(aux = f->ini; aux != NULL; aux = f->ini){
        f->ini = f->ini->prox;
        free(aux);
    }

    free(f);
}

PFila push(PFila f2, int v){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = v;
    novo->prox = f2->ini;

    if(f2->ini == NULL){
        f2->fim = novo;
    }

    f2->ini = novo;

    return f2;
}



PFila inverter(PFila f1, PFila f2){
    PNodo aux;

    if(f1 == NULL){
        printf("FILA VAZIA.\n");
        return f1;
    }

    for(aux = f1->ini; aux != NULL; aux = aux->prox){
        f2 = push(f2, aux->info);
    }

    return f2;
}

int main(){
    int N, valido = 1;
    PFila fila1 = iniciarFila(), fila2 = iniciarFila();

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
    imprimir(fila1);


    fila2 = inverter(fila1, fila2);

    printf("\nFILA 2.\n");
    imprimir(fila2);


    liberar(fila1);
    liberar(fila2);

    return 0;
}