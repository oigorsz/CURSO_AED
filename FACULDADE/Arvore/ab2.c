//ARVORE BINÁRIA GENÉTICA
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    char info;
    struct Nodo *prim, *prox;
}TNodo;

TNodo *start(){
    return NULL;
}

//IMPRIMIR DE FORMA INFIXA 
void imprimirIn(TNodo *raiz){
    if(raiz == NULL)
        return;
    
    imprimirIn(raiz->prim);
    printf("%c ", raiz->info);
    imprimirIn(raiz->prox);
}

void liberar(TNodo *raiz){
    if(raiz == NULL)
        return;

    liberar(raiz->prim);
    liberar(raiz->prox);
    free(raiz);
}

TNodo *buscar(TNodo *raiz, char valor){
    TNodo *p;

    if(raiz == NULL || raiz->info == valor) 
        return raiz;
    p = buscar(raiz->prim, valor);

    if(p != NULL)
        return p;
    return buscar(p->prox, valor);
}

int iguais(TNodo *a, TNodo *b){
    if(a == NULL && b == NULL)  
        return 1;
    if(a == NULL || b == NULL)
        return 0;
    if(a->info != b->info)
        return 0;

    return iguais(a->prim, b->prim) && iguais(a->prox, b->prox);
}


TNodo *inserir(TNodo *raiz, char p, char f) {
    TNodo *pai, *filho;

    if (raiz == NULL) {
        raiz = (TNodo *)malloc(sizeof(TNodo));
        if (raiz == NULL) exit(1); // ERRO DE ALOCAÇÃO
        raiz->info = p;
        raiz->prim = NULL;
        raiz->prox = NULL;
    }

    pai = buscar(raiz, p);

    if (pai == NULL)
        return raiz;

    filho = (TNodo *)malloc(sizeof(TNodo));
    if (filho == NULL) exit(1);
    filho->info = f;
    filho->prim = NULL;
    filho->prox = pai->prim;
    pai->prim = filho;

    return raiz;
}


int main(){
    TNodo *raiz;
    raiz = start();

    raiz = inserir(raiz, 'A', 'B');
    raiz = inserir(raiz, 'A', 'C');
    raiz = inserir(raiz, 'B', 'D');
    raiz = inserir(raiz, 'B', 'E');
    raiz = inserir(raiz, 'C', 'F');

    imprimirIn(raiz);
    liberar(raiz);

    return 0;
}