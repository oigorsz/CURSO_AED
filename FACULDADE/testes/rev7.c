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

    f->ini = f->fim = NULL;
}

void liberar(PFila f){
    PNodo aux;

    for(aux = f->ini; aux != NULL; aux = f->ini){
        f->ini = f->ini->prox;
        free(aux);
    }

    free(f);
}

PFila addFila(PFila f, int v){
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
    printf("\n");

    for(aux = f->ini; aux != NULL; aux = aux->prox){
        printf("%d ", aux->info);
    }

    printf("\n");
}

int comparar(PFila f1, PFila f2){
    PNodo aux1, aux2;

    if(f1->ini == NULL || f2->ini == NULL){
        return 2;
    }

    for(aux1 = f1->ini, aux2 = f2->ini; aux1 != NULL || aux2 != NULL; aux1 = aux1->prox, aux2 = aux2->prox){
        if(aux1->info != aux2->info){
            return 0;
        }
    }

    return 1;
}

PNodo push(PNodo p, int v){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = v;
    novo->prox = p;
    return novo;
}

PFila inverter(PFila f1, PFila f3){
    PNodo pilha, aux;
    pilha = NULL;

    if(f1 == NULL){
        printf("FILA VAZIA.\n");
        return f1;
    }

    for(aux = f1->ini; aux != NULL; aux = aux->prox){
        pilha = push(pilha, aux->info);
    }

    f3->ini = pilha;

    for(aux = pilha; aux->prox != NULL; aux = aux->prox);
    f3->fim = aux;

    return f3;
}

int main(){
    int N, op, comp;
    PFila f1 = iniciarFila(), f2 = iniciarFila(), f3 = iniciarFila();

    system("cls");

    do {
        printf("FILA 1.\n\n");
        printf("DIGITE 1 PARA ADICIONAR UM NOVO ELEMENTO NA FILA.\n");
        printf("DIGITE 2 PARA REMOVER O ELEMENTO DESSA FILA.\n");
        printf("DIGITE 0 PARA FINALIZAR.\n");

        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            printf("DIGITE O VALOR QUE DESEJA ADICIONAR.\n");
            scanf("%d", &N);
            f1 = addFila(f1, N);
            break;
        case 2:
            f1 = remover(f1);
            break;
        
        default:
            if(op != 0){
                printf("VALOR INVALIDO.\n");
            }
            break;
        }
    } while(op != 0);

    do {
        printf("FILA 2.\n\n");
        printf("DIGITE 1 PARA ADICIONAR UM NOVO ELEMENTO NA FILA.\n");
        printf("DIGITE 2 PARA REMOVER O ELEMENTO DESSA FILA.\n");
        printf("DIGITE 0 PARA FINALIZAR.\n");

        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            printf("DIGITE O VALOR QUE DESEJA ADICIONAR.\n");
            scanf("%d", &N);
            f2 = addFila(f2, N);
            break;
        case 2:
            f2 = remover(f2);
            break;
        
        default:
            if(op != 0){
                printf("VALOR INVALIDO.\n");
            }
            break;
        }
    } while(op != 0);

    imprimir(f1);
    imprimir(f2);

    comp = comparar(f1, f2);

    if(comp == 1){
        printf("LISTAS IGUAIS.\n");
    } else if(comp == 2){
        printf("LISTAS VAZIAS.\n");
    } else {
        printf("LISTAS DIFERENTES");
    }

    f3 = inverter(f1, f3);

    imprimir(f3);



    liberar(f1);
    liberar(f2);
    liberar(f3);


    return 0;
}