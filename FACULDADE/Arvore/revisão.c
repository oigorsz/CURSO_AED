#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *dir, *esq;
}TNodo;

typedef TNodo *PNodo;

typedef struct Lista {
    int info;
    struct Nodo *prox;
}TLista;

typedef TLista *PLista;


void liberar(PNodo arv){
    if(arv == NULL)
        return NULL;

    liberar(arv->esq);
    liberar(arv->esq);
    free(arv);
}

void imprimir(PNodo arv){
    if(arv == NULL)
        return NULL;

    imprimir(arv->esq);
    printf("%d ", arv->info);
    imprimir(arv->dir);
}

PNodo criarNodo(int info){
    PNodo novo;
    novo = (PNodo)malloc(sizeof(TNodo));

    if(novo != NULL){
        novo->info = info;
        novo->esq = NULL;
        novo->dir = NULL;
    }

    return novo;
}

PNodo adicionar(PNodo arv, int info){
    if(arv == NULL)
        return arv = criarNodo(info);

    if(info < arv->info)
        arv->esq = adicionar(arv->esq, info);
    else if(info > arv->info)
        arv->dir = adicionar(arv->dir, info);

    return arv;
}

PNodo remover(PNodo arv, int info){
    if(arv == NULL)
        return NULL;

    if(arv->info == info){
        PNodo pai, filho;
        //REMOVER NO
        if(arv->dir == NULL && arv->esq == NULL){
            free(arv);
            return NULL;
        }

        if(arv->dir == NULL){
            filho = arv->esq;
            free(arv);
            return filho;
        }

        if(arv->esq == NULL){
            filho = arv->dir;
            free(arv);
            return filho;
        }

        for(pai = arv, filho = arv->esq; arv->dir != NULL; pai = filho, filho = filho->dir);
        arv->info = filho->info;

        if(pai == arv)
            pai->esq = filho->esq;
        else
            pai->dir = filho->esq;

        free(filho);

        return arv;

    } else if(info < arv->esq)
        arv->esq = remover(arv->esq, info);
    else
        arv->dir = remover(arv->dir, info);

    return arv;
}

PNodo buscar(PNodo arv, int info){
    if(arv == NULL)
        return NULL;

    if(arv->info == info)
        return arv;

    if(info < arv->info)
        return buscar(arv->esq, info);
    else
        return buscar(arv->dir, info);

    return NULL;
}

PNodo liberarSub(PNodo arv){
    if(arv == NULL)
        return NULL;

    liberarSub(arv->esq);
    liberarSub(arv->dir);
    free(arv);
    return NULL;
}

PNodo removerSub(PNodo arv, int chave){
    if(arv == NULL)
        return NULL;

    if(chave < arv->info)
        arv->esq = removerSub(arv->esq, chave);
    else if(chave > arv->info)
        arv->dir = removerSub(arv->dir, chave);
    else if(chave == arv->info)
        arv = liberarSub(arv);

    return arv;
}

int buscarValor(PNodo arv, int info){
    if(arv == NULL)
        return 0;
    
    if(arv->info == info)
        return 1;

    if(info < arv->info)
        return buscarValor(arv->esq, info);
    else
        return buscar(arv->dir, info);
}

int contar(PNodo arv){
    if(arv == NULL)
        return 0;

    return 1 + contar(arv->esq) + contar(arv->dir);
}

int soma(PNodo arv){
    if(arv == NULL)
        return 0;

    return arv->info + soma(arv->esq) +  soma(arv->dir);
}

int altura(PNodo arv){
    int esq, dir;

    if(arv == NULL)
        return -1;

    esq = altura(arv->esq);
    dir = altura(arv->dir);

    if(esq > dir)
        return 1 + esq;
    else
        return 1 + dir;
}

int iguais(PNodo a1, PNodo a2){
    if(a1 == NULL && a2 == NULL) return 1;
    if(a1 == NULL || a2 == NULL) return 0;
    if(a1->info != a2->info) return 0;

    return iguais(a1->esq, a2->esq) || iguais(a1->dir, a2->dir);
}

int folhas(PNodo arv){
    if(arv == NULL)
        return 0;

    if(arv->dir == NULL && arv->esq == NULL){
        return 1;
    }

    return folhas(arv->dir) + folhas(arv->esq);
}

int maior(PNodo arv){
    PNodo aux;

    for(aux = arv; aux->dir != NULL; aux = aux->dir);

    return aux->info;//RETORNA O VALOR DO MAIOR NODO
}

int menor(PNodo arv){
    PNodo aux;

    for(aux = arv; aux->esq != NULL; aux = aux->esq);

    return aux->info; //RETORNA O VALOR DO MENOR NODO
}

int nivel(PNodo arv, int chave){
    PNodo aux;
    int nivel = 0;

    for(aux = arv; aux != NULL && aux->info != chave;){
        if(chave < aux->info)
            aux = aux->esq;
        else if(chave > aux->info)
            aux = aux->dir;
        nivel++;
    }

    if(aux == NULL)
        return -1;

    return nivel;
}

PNodo removerTodasFolhas(PNodo arv){
    if(arv == NULL)
        return NULL;

    removerTodasFolhas(arv->esq);
    removerTodasFolhas(arv->dir);

    if(arv->dir == NULL && arv->esq == NULL){
        free(arv);
        return NULL;   
    }

    return arv;
}

PNodo converter(PLista lista){
    PLista aux;
    PNodo arv;
    arv = NULL;

    if(lista == NULL)
        return NULL;

    while (lista != NULL)
    {
        aux = lista;
        lista = lista->prox;
        arv = adicionar(arv, aux->info);
        free(aux);
    }

    return arv;
    
}