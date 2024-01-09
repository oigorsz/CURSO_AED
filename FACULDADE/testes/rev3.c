#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *prox;
}TNodo;

typedef TNodo *PNodo;

PNodo iniciarLista(){
    return NULL;
}

PNodo liberar(PNodo l){
    PNodo aux;

    for(aux = l; aux != NULL; aux = l){
        l = l->prox;
        free(aux);
    }
}

PNodo busca(PNodo l, int ref){
    PNodo aux, last;

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->info == ref){
            return aux;
        }

        last = aux;
    }

    return last;
}

PNodo adicionar(PNodo l, int v, int ref){
    PNodo novo, aux;
    novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        liberar(l);
        exit(1);
    }

    novo->info = v;

    if(l == NULL){
        novo->prox = NULL;
        l = novo;
    } else {
        aux = busca(l, ref);

        novo->prox = aux->prox;
        aux->prox = novo;
    }

    return l;
}

PNodo remover(PNodo l, int ref){
    PNodo aux, ant = NULL;

    if(l == NULL){
        printf("LISTA VAZIA.\n");
        return l;
    }

    aux = l;

    while (aux != NULL && aux->info != ref)
    {
        ant = aux;
        aux = aux->prox;
    }

    if(aux == NULL){
        printf("VALOR NÃO ENCONTRADO.\n");
        return l;
    }

    if(ant == NULL){
        l = l->prox;
    } else {
        ant->prox = aux->prox;
        aux->prox = NULL;
    }

    free(aux);
    return l;
}

void imprimir(PNodo l){
    PNodo aux;

    for(aux = l; aux != NULL; aux = aux->prox){
        printf("%d ", aux->info);
    }

    printf("\n");
}

int main(){
    int N, op, ref;
    PNodo lista = iniciarLista();

    system("cls");

    do {
        printf("DIGITE 1 PARA ADICIONAR UM ELEMENT A LISTA.\n");
        printf("DIGITE 2 PARA REMOVER UM ELEMENTO DA LISTA.\n");
        printf("DIGITE 3 PARA IMPRIMIR A LISTA.\n");
        printf("DIGITE 0 PARA FINALIZAR.\n");

        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            printf("DIGITE O VALOR A SER ADICIONADO.\n");
            scanf("%d %d", &N, &ref);
            lista = adicionar(lista, N, ref);
            break;
        case 2:
            printf("DIGITE O VALOR A SER REMOVIDO.\n");
            scanf("%d", &ref);
            lista = remover(lista, ref);
            break;
        case 3:
            imprimir(lista);
            break;
        
        default:
            if(op != 0){
                printf("VALOR INVALIDO.\n");
            }
            break;
        }

    } while(op != 0);

    liberar(lista);
    return 0;
}

