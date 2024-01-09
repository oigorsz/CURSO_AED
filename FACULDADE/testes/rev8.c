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

PNodo addIni(PNodo l, int v){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = v;
    
    if(l == NULL){
        novo->prox = NULL;
        novo->ant = NULL;
    } else {
        novo->prox = l;
        novo->ant = NULL;
        l->ant = novo;
    }

    return novo;
}

PNodo adicionarFim(PNodo l, int v){
    PNodo novo, aux;
    novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = v;
    novo->prox = NULL;

    if(l == NULL){
        novo->ant = NULL;
        return novo;
    }

    for(aux = l; aux->prox != NULL; aux = aux->prox);
    aux->prox = novo;
    novo->ant = aux;

    return l;
}

PNodo addMeio(PNodo l, int v, int ref){
    PNodo novo, aux;
    novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = v;

    if(l == NULL){
        novo->ant = NULL;
        novo->prox = NULL;
        return l;
    }

   for(aux = l; aux->info != ref && aux->prox != NULL; aux = aux->prox);
   novo->prox = aux->prox;
   aux->prox->ant = novo;
   novo->ant = aux->prox->ant;
   aux->prox = novo;
    
}