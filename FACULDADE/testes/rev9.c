#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *prox;
    struct Nodo *ant;
}TNodo;

typedef TNodo *PNodo;

PNodo iniciarLista(){
    return NULL;
}

PNodo addLista(PNodo l, int v){
    PNodo novo, aux;
    novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = v;

    if(l == NULL){
        novo->prox = NULL;
        novo->ant = NULL;
        return novo;
    }

    aux = l;

    if(aux->info > v){
        novo->prox = aux;
        novo->ant = NULL;
        aux->ant = novo;
        return novo;
    }

    for(aux = l->prox; aux->prox->info < v && aux->prox != NULL; aux = aux->prox);
    novo->prox = aux->prox;
    aux->prox->ant = novo;
    novo->ant = aux;
    aux->prox = novo;
}

PNodo busca(PNodo l, int ref){
    PNodo aux;

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->info == ref){
            return aux;
        }
    }

    return NULL;   
}

PNodo remover(PNodo l, int ref){
    PNodo aux;

    aux = busca(l, ref);

    if(aux == NULL){
        printf("VALOR NÃO ENCONTRADO.\n");
        return NULL;
    }

    if(aux->ant == NULL){
        aux->prox->ant = NULL;
        l = aux->prox;
    } else if(aux->prox == NULL){
        aux->ant->prox = NULL;
    } else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }

    free(aux);
    return l;
}