#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *prox;
}TNodo;

typedef TNodo *PNodo;

PNodo iniciar(){
    return NULL;
}

PNodo adicionarIni(PNodo l, int v){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = v;
    novo->prox = l;
    l = novo;

    return l;
}

PNodo adicionarFim(PNodo l, int v) {
    PNodo novo, aux;
    novo = (PNodo)malloc(sizeof(TNodo));

    if (novo == NULL) {
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = v;
    novo->prox = NULL;

    if (l == NULL) {
        // Se a lista estiver vazia, o novo nó se torna a lista
        return novo;
    } else {
        aux = l;
        
        // Percorra até o último nó da lista
        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        // Adicione o novo nó ao final da lista
        aux->prox = novo;
        return l; // Retorne a lista com o novo nó adicionado
    }
}


void liberar(PNodo l){
    PNodo aux;

    for(aux = l; aux != NULL; aux = l){
        l = l->prox;
        free(aux);
    }
}

void imprimir(PNodo l){
    PNodo aux;

    for(aux = l; aux != NULL; aux = aux->prox){
        printf("%d ", aux->info);
    }
}


int main(){
    int N, valido = 1;
    PNodo lista1 = iniciar();
    PNodo lista2 = iniciar();

    system("cls");

    do {
        printf("DIGITE UM NUMERO QUE SERÁ ADICIONADO A FILA 1.\n");
        printf("DIGITE -1 PARA TERMINAR O PROCEDIMENTO.\n");
        scanf("%d", &N);

        if(0 <= N && N <= 100){
            lista1 = adicionarIni(lista1, N);
            lista2 = adicionarFim(lista2, N);
        } else {
            valido = 0;
        }

    } while(valido == 1);

    system("cls");

    printf("LISTA 1.\n");
    imprimir(lista1);
    printf("\nLISTA 2.\n");
    imprimir(lista2);

    liberar(lista1);
    liberar(lista2);

    return 0;
}


