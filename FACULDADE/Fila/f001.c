#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *next;
}TNodo;

typedef TNodo *PNodo;

typedef struct Fila {
    PNodo ini;
    PNodo fim;
}TFila;

typedef TFila *PFila;

PFila criar(){
    PFila fila = (PFila)malloc(sizeof(TFila));

    if(fila == NULL){
        printf("[ERRO DE ALOCAÇÃO]");
        exit(1);
    }

    fila->ini = fila->fim = NULL;
    return fila;
}

PFila inserir(PFila fila, int valor){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO]");
        exit(1);
    }

    novo->info = valor;
    novo->next = NULL;

    if(fila->ini == NULL){
        fila->ini = fila->fim = novo;
    } else {
        fila->fim->next = novo;
        fila->fim = novo;
    }

    return fila;
}

int retirar (PFila fila, int dado){
    PNodo p;

    if(fila->ini == NULL){
        //FILA VAZIA
        return -1;
    }

    dado = fila->ini->info;
    p = fila->ini;
    fila->ini = p->next;
    free(p);

    if(fila->ini == NULL){
        fila->fim = NULL;
    }

    return dado;
}


void imprimir(PFila fila){
    if (fila == NULL || fila->ini == NULL) {
        printf("A fila está vazia.\n");
        return;
    }


    PNodo aux;

    for(aux = fila->ini; aux != NULL; aux = aux->next){
        printf("%d\n", aux->info);
    }

}

void liberar(PFila fila){
    PNodo aux;

    for(aux = fila->ini; aux != NULL;){
        fila->ini = fila->ini->next;
        free(aux);
    }

    free(fila);
}

void registrar(PFila fila, int *i){
    system("cls");

    fila = inserir(fila, *i);

    (*i)++;
}

void excluir(PFila fila) {
    int removido;
    system("cls");
    
    removido = retirar(fila, removido);

    if(removido == -1){
        printf("FILA VAZIA.\n");
        return;
    } else {
        printf("NUMERO REMOVIDO: %d.\n", removido);
    }

}

void encerrar(PFila fila){
    system("cls");

    liberar(fila);

    printf("PROGRAMA ENCERRADO.\n");
}


int main(){
    int choice, i = 1;
    PFila fila = criar();

    system("cls");

    while (1)
    {
        printf("FILA DE CAIXA.\n");
        imprimir(fila);
        printf("DIGITE 1 PARA ADICIONAR ALGUEM A LISTA.\n");
        printf("DIGITE 2 PARA REMOVER ALGUEM DA LISTA.\n");
        printf("DIGITE 0 PARA ENCERRAR A FILA.\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registrar(fila, &i);
            break;
        case 2:
            excluir(fila);
            break;
        case 0:
            encerrar(fila);
            return 0;
            break;
        
        default:
            system("cls");
            printf("[VALOR INVALIDO]");
            break;
        }
    }
    
}

