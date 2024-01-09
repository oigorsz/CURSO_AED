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

PNodo inserirIni(PNodo l, int v){
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

PNodo inserirFim(PNodo l, int v){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));
    PNodo aux;

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = v;
    novo->prox = NULL;

    if(l == NULL){
        return novo;
    }

    aux = l;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }

    aux->prox = novo;

    return l;
}
PNodo busca(PNodo l, int v){
    PNodo aux;

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->info == v){
            return aux;
        }
    }

    return NULL;
}

PNodo inserirMeio(PNodo l, int v, int ant){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));
    PNodo aux;

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = v;

    if(l == NULL){
        novo->prox = NULL;
        return novo;
    } else {
        aux = busca(l, ant);
        novo->prox = aux->prox;
        aux->prox = novo;
    }

    return l;
}

PNodo removerIni(PNodo l){
    PNodo aux;

    if(l == NULL){
        printf("LISTA VAZIA.\n");
        return l;
    }

    aux = l;
    l = l->prox;
    free(aux);

    return l;
}


void imprimir(PNodo l){
    PNodo aux;

    printf("\nLISTA: ");

    for(aux = l; aux != NULL; aux = aux->prox){
        printf("%d ", aux->info);
    }

    printf("\n");
}

void liberar(PNodo l){
    PNodo aux;

    for(aux = l; aux != NULL; aux = l){
        l = l->prox;
        free(aux);
    }
}


int main(){
    PNodo lista = iniciarLista();
    int num, pos, op;


    do {
        printf("DIGITE 1 PARA ADICIONAR NO INICIO.\n");
        printf("DIGITE 2 PARA ADICIONAR AO FINAL.\n");
        printf("DIGITE 3 PARA ADICIONAR NO MEIO.\n");
        printf("DIGITE 4 PARA REMOVER NO INICIO.\n");
        printf("DIGITE 5 PARA REMOVER NO FINAL.\n");
        printf("DIGITE 6 PARA REMOVER NO MEIO.\n");
        printf("DIGITE 7 PARA IMPRIMIR A LISTA.\n");
        printf("DIGITE 0 PARA ENCERRAR.\n");
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            printf("DIGITE UM VALOR PARA O INICIO.\n");
            scanf("%d", &num);
            lista = inserirIni(lista, num);
            break;
        case 2:
            printf("DIGITE UM VALOR PARA O FIM.\n");
            scanf("%d", &num);
            lista = inserirFim(lista, num);
            break;
        case 3:
            printf("DIGITE UM VALOR INTERMEDIARIO.\n");
            scanf("%d %d", &num, &pos);
            lista = inserirMeio(lista, num, pos);
            break;
        case 4:
            system("cls");
            imprimir(lista);
            break;
        
        case 5:
            lista = removerIni(lista);
            break;
        case 6:
            lista = removerFim(lista);
            break;
        case 7:
            printf("DIGITE O VALOR QUE DESEJA REMOVER.\n");
            scanf("%d", &num);
            lista = removerMeio(lista, num);
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