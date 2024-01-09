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

void liberar(PNodo l){
    PNodo aux;

    for(aux = l; aux != NULL; aux = l){
        l = l->prox;
        free(aux);
    }
}

PNodo addOrd(PNodo l, int v){
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
        return novo;
    } else if(novo->info < l->info){
        novo->prox = l;
        l = novo;
    } else {
        aux = l;

        while (aux->prox != NULL && novo->info > aux->prox->info)
        {
            aux = aux->prox;
        }

        novo->prox = aux->prox;
        aux->prox = novo;
    }

    return l;
}

PNodo removerMeio(PNodo l, int v){
    PNodo  aux, ant = NULL;

    if(l == NULL){
        printf("[LISTA VAZIA].\n");
        return NULL;
    }

    aux = l;

    while (aux != NULL && aux->info != v)
    {
        ant = aux;
        aux = aux->prox;
    }

    if(aux == NULL){
        printf("VALOR NAO ENCONTRADO.\n");
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
    int op, num;
    PNodo lista = iniciarLista();

    system("cls");

    do {
        printf("DIGITE 1 PARA ADICIONAR A LISTA.\n");
        printf("DIGITE 2 PARA REMOVER UM ELEMENTO DA LISTA.\n");
        printf("DIGITE 3 PARA IMPRIMIR A LISTA.\n");
        printf("DIGITE 0 PARA ENCERRAR.\n");
        scanf("%d", &op);

        system("cls");


        switch (op)
        {
        case 1:
            printf("DIGITE O VALOR A SER ADICIONADO.\n");
            scanf("%d", &num);
            lista = addOrd(lista, num);
            break;
        case 2:
            printf("DIGITE O VALOR A SER REMOVIDO.\n");
            scanf("%d", &num);
            lista = removerMeio(lista, num);
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
    } while (op != 0);


    liberar(lista);
    
    return 0;
}
