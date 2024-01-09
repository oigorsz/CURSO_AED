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
        printf("[ERRO DE ALOCAÇÃO NA FILA].\n");
        exit(1);
    }

    f->ini = f->fim = NULL;
    return f;
}

void liberar(PFila f){
    PNodo aux;

    for(aux = f->ini; aux!= NULL; aux = f->ini){
        f->ini = f->ini->prox;
        free(aux);
    }

    free(f);
}

PFila adicionar(PFila f, int v){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        liberar(f);
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

    if(f->ini == NULL){
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
    
    printf("\n");
}

int main(){
    int N, op;
    PFila fila = iniciarFila();

    system("cls");

    do {
        printf("DIGITE 1 PARA ADICIONAR UM ELEMENT A FILA.\n");
        printf("DIGITE 2 PARA REMOVER UM ELEMENTO DA FILA.\n");
        printf("DIGITE 3 PARA IMPRIMIR A FILA.\n");
        printf("DIGITE 0 PARA FINALIZAR.\n");

        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            printf("DIGITE O VALOR A SER ADICIONADO.\n");
            scanf("%d", &N);
            fila = adicionar(fila, N);
            break;
        case 2:
            fila = remover(fila);
            break;
        case 3:
            imprimir(fila);
            break;
        
        default:
            if(op != 0){
                printf("VALOR INVALIDO.\n");
            }
            break;
        }

    } while(op != 0);

    liberar(fila);
    return 0;
}

