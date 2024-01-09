#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *prox;
}TNodo;

typedef TNodo *PNodo;

PNodo iniciarLista (){
    return NULL;
}

PNodo adicionarFim(PNodo l, int v){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = v;

    if(l == NULL){
        novo->prox = novo;
        return novo;
    }

    novo->prox = l->prox;
    l->prox = novo;

    return l;
}

PNodo removeIni(PNodo l){
    PNodo aux;

    if(l == NULL){
        printf("LISTA VAZIA.\n");
        return l;
    }

    aux = l->prox;

    if(aux == l){
        l = NULL;
    } else {
        l->prox = aux->prox;
        free(aux);
    }

    return l;
}

void liberar(PNodo l){
    PNodo aux;

    aux = l->prox;

    while (aux != l)
    {
        l->prox = aux->prox;
        free(aux);
        aux = l->prox;
    }

    free(l);
}

void imprimir(PNodo l){
    PNodo aux;

    if(l == NULL){
        printf("LISTA VAZIA.\n");
    } else {
        aux = l->prox;

        do {
            printf("%d ", aux->info);
            aux = aux->prox;
        } while(aux != l->prox);
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
            scanf("%d", &N);
            lista = adicionarFim(lista, N);
            break;
        case 2:
            lista = removeIni(lista);
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

