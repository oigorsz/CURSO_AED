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

PNodo addIni(PNodo l, int v){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        liberar(l);
        exit(1);
    }

    novo->info = v;
    novo->prox = l;
    l = novo;

    return l;
}

PNodo addFim(PNodo l, int v){
    PNodo novo, aux;
    novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        liberar(l);
        exit(1);
    }

    novo->info = v;
    novo->prox = NULL;

    if(l == NULL){
        return novo;
    } else {
        for(aux = l; aux->prox != NULL; aux = aux->prox);
        aux->prox = novo;
    }

    return l;
}


PNodo busca(PNodo l, int ref){
    PNodo aux;

    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->info == ref){
            return aux;
        }
    }

    return NULL;
}

PNodo addMeio(PNodo l, int v, int ref){
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
    } else {
        aux = busca(l, ref);
        novo->prox = aux->prox;
        aux->prox = novo;
    }

    return l;
}

PNodo removeIni(PNodo l){
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

PNodo removeFim(PNodo l){
    PNodo aux, temp = NULL;

    if(l == NULL){
        printf("LISTA VAZIA.\n");
        return NULL;
    }

    if(l->prox == NULL){
        free(l);
        return NULL;
    }

    aux = l;

    while (aux->prox != NULL)
    {
        temp = aux;
        aux = aux->prox;
    }

    temp->prox = NULL;
    free(aux);

    return l;
}

PNodo removeMeio(PNodo l, int ref){
    PNodo aux, ant = NULL;

    if(l == NULL){
        return NULL; 
    }

    aux = l;

    while (aux != NULL && aux->info != ref)
    {
        ant = aux;
        aux = aux->prox;
    }

    if(aux == NULL){
        printf("VALOR NÃO ENCONTRADO.\n");
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
            lista = addIni(lista, num);
            break;
        case 2:
            printf("DIGITE UM VALOR PARA O FIM.\n");
            scanf("%d", &num);
            lista = addFim(lista, num);
            break;
        case 3:
            printf("DIGITE UM VALOR INTERMEDIARIO.\n");
            scanf("%d %d", &num, &pos);
            lista = addMeio(lista, num, pos);
            break;
        case 4:
            lista = removeIni(lista);
            break;
        
        case 5:
            lista = removeFim(lista);
            break;
        case 6:
            system("cls");
            printf("DIGITE O VALOR QUE SERA REMOVIDO.\n");
            scanf("%d", &num);
            lista = removeMeio(lista, num);
            break;
        case 7:
            system("cls");
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