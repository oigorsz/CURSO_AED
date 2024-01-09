#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *right;
    struct Nodo *left;
}Nodo;

Nodo* createNodo(int valor){
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = valor;
    novo->left = NULL;
    novo->right = NULL;

    return novo;
}

Nodo* adicionar(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return createNodo(valor);
    }

    if (valor == raiz->info) {
        printf("VALOR JÁ EXISTENTE.\n");
        return raiz;
    }

    if (valor < raiz->info) {
        raiz->left = adicionar(raiz->left, valor);
    } else {
        raiz->right = adicionar(raiz->right, valor);
    }

    return raiz;
}


void imprimir(Nodo *raiz){
    if(raiz == NULL){
        return;
    }

    imprimir(raiz->left);
    printf("%d ", raiz->info);
    imprimir(raiz->right);
}

void liberar(Nodo *raiz){
    if(raiz == NULL){
        return;
    }

    liberar(raiz->left);
    liberar(raiz->right);

    free(raiz);
}

int main(){
    int choice = 1, num;
    Nodo* raiz = NULL;

    system("cls");

    while(choice != 0){
        printf("DIGITE 1 PARA ADICIONAR UM NODO.\n");
        printf("DIGITE 2 PARA IMPRIMIR OS NODOS EM ORDEM.\n");
        printf("DIGITE 0 PARA ENCERRAR.\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            printf("DIGITE O NUMERO PARA ADICIONAR:\n => ");
            scanf("%d", &num);
            raiz = adicionar(raiz, num);
            system("cls");
            break;
        case 2:
            system("cls");
            printf("\n");
            imprimir(raiz);
            printf("\n");
            break;
        case 0:
            system("cls");
            printf("PROGRAMA ENCERRADO.\n");
            liberar(raiz);
            break;
        
        default:
            printf("VALOR INVALIDO.\n");
            break;
        }
    }
    

    return 0;
}