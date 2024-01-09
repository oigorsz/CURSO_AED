#include <stdio.h>
#include <stdlib.h>
#define MAX_LINHAS 10

typedef struct No {
    int info, col;
    struct No *prox;
}TNo;

typedef TNo *PNo;
typedef PNo Pme[MAX_LINHAS];

void start(Pme m, int l){
    int i;

    for(i = 0; i < l; i++){
        m[i] = NULL;
    }
}

void inserir(Pme m, int l, int c, int v){
    PNo novo, p, q;

    if(v == 0 || l >= MAX_LINHAS) return;

    novo = (PNo)malloc(sizeof(TNo));
    novo->info = v;
    novo->col = c;

    p = m[l];
    q = NULL;

    if(p == NULL || c < p->col){
        novo->prox = p;
        m[l] = novo;
    } else {
        for(;p->prox != NULL && p->prox->col < c; p = p->prox);
        q = p->prox;
        p->prox = novo;
        novo->prox = q;
    }
}

void liberar(Pme m){
    PNo aux;
    int i;

    for(i = 0; i < MAX_LINHAS; i++){
        for(aux = m[i]; aux != NULL; aux = m[i]){
            m[i] = aux->prox;
            free(aux);
        }
    }
}

void imprimir(Pme m, int c){
    PNo p;
    int i, j;
    

    for(i = 0; i < MAX_LINHAS; i++){
        p = m[i];

        for(j = 0; j < c; j++){
            if(p != NULL && p->col == j){
                printf("%d ", p->info);
                p = p->prox;
            } else {
                printf("0 ");
            }
        }
    }
}



PNo transposta(Pme m, int l, int c){
    Pme novo[c];
    PNo p;
    int i;

    start(novo, c);

    for(i = 0; i < l; i++){
        for(p = m[i]; p != NULL; p = p->prox){
            inserir(novo, p->col, l, p->info);
        }
    }
}

int iguais(Pme m1, Pme m2, int l1, int l2){
    PNo p, q;

    if(m1 == NULL && m2 == NULL) return 1;
    if(m1 == NULL || m2 == NULL) return 0;


}